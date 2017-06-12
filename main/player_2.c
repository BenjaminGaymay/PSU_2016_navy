/*
** player_2.c for navy in /home/benoit.pingris/delivery/PSU_2016_navy
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Fri Feb  3 11:19:33 2017 benoit pingris
** Last update Wed Feb 15 13:53:49 2017 benoit pingris
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

void	signal_pause(char *cell)
{
  signal(12, win);
  signal(10, play_again);
  pause();
  free(cell);
}

char	*new_cell(char *str)
{
  char	*new_cell;

  free(str);
  my_putstr("wrong position\nattack: ");
  new_cell = get_next_line(0);
  return (new_cell);
}

int	time_to_wait_2(t_player *player)
{
  usleep(7500);
  player->play = 1;
  if (check_boats_alive(player) == 0)
    {
      kill(player->enemy_pid, SIGUSR2);
      return (0);
    }
  else
    kill(player->enemy_pid, SIGUSR1);
  return (1);
}

int	last_aff(t_player *player)
{
  if (player->id != 1)
    my_putstr("\n\nmy positions:\n");
  else
    my_putstr("\nmy positions:\n");
  my_showtab(player->my_map);
  my_putstr("\nenemy's positions:\n");
  my_showtab(player->enemy_map);
  if (g_pid == 0)
    my_putstr("\nI won\n");
  else
    my_putstr("\nEnemy won\n");
  return (g_pid == 0 ? 0 : 1);
}

void	disp_map(t_player *player)
{
  if (player->id == 1)
    my_putstr("\n\nmy positions:\n");
  else
    my_putstr("\nmy positions:\n");
  my_showtab(player->my_map);
  my_putstr("\nenemy's position:\n");
  my_showtab(player->enemy_map);
}
