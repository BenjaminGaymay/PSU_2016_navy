/*
** boats.c for navy in /home/benoit.pingris/delivery/PSU_2016_navy
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Wed Feb  1 10:25:37 2017 benoit pingris
** Last update Sun Feb  5 14:36:39 2017 Benjamin GAYMAY
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"
#include "navy.h"

void	put_boat_on_map_3(t_player *player, int i)
{
  int	y;
  char	**tmp;
  char	**tmp_map;

  tmp = player->boats_position;
  tmp_map = player->my_map;
  y = tmp[i][3] - 48;
  while (y <= tmp[i][6] - 48)
    {
      tmp_map[y][tmp[i][2] - 48] = tmp[i][0];
      y++;
    }
}

void	put_boat_on_map_2(t_player *player, int i)
{
  int	y;
  char	**tmp;
  char	**tmp_map;

  tmp = player->boats_position;
  tmp_map = player->my_map;
  y = tmp[i][2] -48;
  while (y <= tmp[i][5] - 48)
    {
      tmp_map[tmp[i][3] - 48][y] = tmp[i][0];
      y++;
    }
}

void	put_boat_on_map(t_player *player)
{
  int	i;
  int	y;
  char	**tmp;
  char	**tmp_map;

  i = 0;
  tmp = player->boats_position;
  tmp_map = player->my_map;
  while (tmp[i] != NULL)
    {
      if (tmp[i][3] == tmp[i][6])
	put_boat_on_map_2(player, i);
      else if (tmp[i][2] == tmp[i][5])
	put_boat_on_map_3(player, i);
      i++;
    }
}

int	check_boats_alive(t_player *player)
{
  int	x;
  int	y;
  int	boats;

  y = 0;
  boats = 0;
  while (player->my_map[y] != NULL)
    {
      x = 0;
      while (player->my_map[y][x] != '\0')
	{
	  if (player->my_map[y][x] == '2'
	      || player->my_map[y][x] == '3'
	      || player->my_map[y][x] == '4'
	      || player->my_map[y][x] == '5')
	    boats++;
	  x++;
	}
      y++;
    }
  return (boats);
}

void	put_x_o(t_player *player, int att, int choice)
{
  if (choice == 0)
    {
      player->my_map[att / 10][(att - 1) % 10] = 'o';
      kill(player->enemy_pid, SIGUSR1);
      my_printf("\n%c%c: ", ((att - 1) % 10) + 'A', (att / 10) + '1');
      my_putstr(GREEN"missed"WHITE);
    }
  else
    {
      player->my_map[att / 10][(att - 1) % 10] = 'x';
      kill(player->enemy_pid, SIGUSR2);
      my_printf("\n%c%c: ", ((att - 1) % 10) + 'A', (att / 10) + '1');
      my_putstr(RED2"hit"WHITE);
    }
}
