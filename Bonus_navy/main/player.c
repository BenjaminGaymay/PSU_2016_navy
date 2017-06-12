/*
** player.c for navy in /home/benjamin.g/delivery/PSU_2016_navy
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Feb  1 14:21:14 2017 Benjamin GAYMAY
** Last update Mon Feb 13 10:15:18 2017 benoit pingris
*/

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "navy.h"
#include "get_next_line.h"
#include "use_array.h"
#include "my.h"

char	*check_attack(char *str)
{
  char	tmp;

  if (str == NULL)
    {
      my_putchar('\n');
      return (NULL);
    }
  str = my_str_uppercase(str);
  if (my_strlen(str) != 2)
    return (NULL);
  else if ((str[0] < 'A' && str[0] > '8') || (str[0] < '1') || (str[0] > 'H'))
    return (NULL);
  else if ((str[1] < 'A' && str[1] > '8') || (str[1] < '1') || (str[1] > 'H'))
    return (NULL);
  else if ((str[0] >= '1' && str[0] <= '8' && str[1] >= '1' && str[1] <= '8'))
    return (NULL);
  else if ((str[0] >= 'A' && str[0] <= 'H' && str[1] >= 'A' && str[1] <= 'H'))
    return (NULL);
  else if (str[0] >= '1' && str[0] <= '8'
	   && str[1] >= 'A' && str[1] <= 'H')
    str = my_swap_2(str);
  return (str);
}

int	time_to_play(t_player *player)
{
  char	*cell;
  int	attack;

  my_putstr("\nattack: ");
  cell = get_next_line(0);
  while ((cell = check_attack(cell)) == NULL)
    cell = new_cell(cell);
  attack = deci_to_bin(cell);
  if (send_attack(attack, player) == ERROR)
    return (ERROR);
  my_printf("%s: ", cell);
  signal(12, hit);
  signal(10, miss);
  pause();
  if (g_pid == 1)
    player->enemy_map[attack % 10][(attack - 10) / 10] = 'x';
  else
    player->enemy_map[attack % 10][(attack - 10) / 10] = 'o';
  signal(12, win);
  signal(10, play_again);
  pause();
  free(cell);
  player->play = 0;
  return (g_pid == 1 ? 1 : 0);
}

int	bin_to_dec(char *s)
{
  int	i;
  int	nbr;

  s = my_revstr(s);
  i = 0;
  nbr = 0;
  while (s[i])
    {
      if (s[i] == '1')
	nbr += my_power_rec(2, i);
      i++;
    }
  return (reverse_nb(nbr));
}

int	time_to_wait(t_player *player)
{
  int	i;
  int	attack;

  my_putstr("\nwaiting for enemy's attack..");
  my_putstr(CLIGN"."WHITE);
  signal(12, catch_1);
  signal(10, catch_0);
  i = 0;
  while (i < 7)
    {
      pause();
      i++;
    }
  attack = bin_to_dec(get_cell(0, 0));
  usleep(5000);
  if (player->my_map[attack / 10][(attack - 1) % 10] == '.' ||
      player->my_map[attack / 10][(attack - 1) % 10] == 'o')
    put_x_o(player, attack, 0);
  else
    put_x_o(player, attack, 1);
  return (time_to_wait_2(player));
}

int	lets_play(t_player *player)
{
  int	do_it_again;

  do_it_again = check_boats_alive(player);
  my_putstr("\n\n my positions:\t\t\t enemy's positions:\n");
  my_showtab(player->my_map, player->enemy_map);
  while (do_it_again != 0)
    {
      if (player->play == 0)
	{
	  if (time_to_wait(player) == 0)
	    do_it_again = 0;
	  if (player->id == 1)
	    {
	      my_putstr("\n\n my positions:\t\t\t enemy's positions:\n");
	      my_showtab(player->my_map, player->enemy_map);
	    }
	}
      else
	{
	  if (player->id != 1)
	    my_putchar('\n');
	  my_putstr(BLUE"\n===================================================\n"WHITE);
	  if (time_to_play(player) == 0)
	    do_it_again = 0;
	  if (player->id != 1)
	    {
	      my_putstr("\n my positions:\t\t\t enemy's positions:\n");
	      my_showtab(player->my_map, player->enemy_map);
	    }
	}
    }
  return (last_aff(player));
}
