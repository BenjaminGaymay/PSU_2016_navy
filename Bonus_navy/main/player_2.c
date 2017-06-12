/*
** player_2.c for navy in /home/benoit.pingris/delivery/PSU_2016_navy
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Fri Feb  3 11:19:33 2017 benoit pingris
** Last update Mon Feb 13 10:16:23 2017 benoit pingris
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

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
  usleep(5000);
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
  if (player->id == 1)
    my_putstr("\n my positions:\t\t\t enemy's positions:\n");
  else
    my_putstr("\n\n my positions:\t\t\t enemy's positions:\n");
  my_showtab(player->my_map, player->enemy_map);
  if (g_pid == 0)
    {
      my_putstr(GREEN"\n\t       __ __ __ __ ____ __\n");
      my_putstr("\t      |  |  |  |  |    |  |\n");
      my_putstr("\t      |  |  |  |  |       |\n");
      my_putstr("\t       \\__/\\__/|__|__|____|\n"WHITE);
    }
  else
    {
      my_putstr(RED2"\n\t     __    _____ _____ _____\n");
      my_putstr("\t    |  |  |     |   __|   __|\n");
      my_putstr("\t    |  |__|  |  |__   |   __|\n");
      my_putstr("\t    |_____|_____|_____|_____|\n"WHITE);
    }
  return (g_pid == 0 ? 0 : 1);
}
