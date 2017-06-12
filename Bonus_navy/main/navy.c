/*
** navy.c for navy in /home/benoit.pingris/delivery/PSU_2016_navy
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Wed Feb  1 10:51:39 2017 benoit pingris
** Last update Mon Feb 13 10:16:02 2017 benoit pingris
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "use_array.h"
#include "navy.h"
#include "my.h"

int	g_pid;

void	handler(int sig, siginfo_t *siginfo, void *context)
{
  g_pid = siginfo->si_pid;
}

char		*enough_boats_2(char **tmp, int i, int j, char *boats)
{
  if (tmp[i][j] == '2')
    boats[0] = boats[0] + 1;
  else if (tmp[i][j] == '3')
    boats[1] = boats[1] + 1;
  else if (tmp[i][j] == '4')
    boats[2] = boats[2] + 1;
  else if (tmp[i][j] == '5')
    boats[3] = boats[3] + 1;
  return (boats);
}

int		enough_boats(t_player *player)
{
  char		**tmp;
  char		*boats;
  int		i;
  int		j;

  i = 0;
  tmp = player->my_map;
  boats = my_strcpy(boats, "0000\0");
  while (tmp[i] != NULL)
    {
      j = 0;
      while (tmp[i][j] != '\0')
	{
	  boats = enough_boats_2(tmp, i, j, boats);
	  j++;
	}
      i++;
    }
  if (my_strcmp(boats, "2345") != 0)
    {
      free(boats);
      return (ERROR);
    }
  free(boats);
  return (0);
}

int		get_pid(t_player *player)
{
  struct sigaction	sa;

  sigemptyset(&sa.sa_mask);
  sa.sa_sigaction = &handler;
  sa.sa_flags = SA_SIGINFO;
  if (sigaction(SIGUSR2, &sa, NULL) == -1)
    return (ERROR);
  pause();
  player->enemy_pid = g_pid;
  return (0);
}

int		aff_game(t_player *player, char **av)
{
  my_printf("my_pid: %d\n", player->pid);
  if (player->id == 1)
    {
      my_printf("waiting for enemy connexion..");
      my_putstr(CLIGN"."WHITE);
      if (get_pid(player) == ERROR)
	return (ERROR);
      usleep(5000);
      kill(player->enemy_pid, SIGUSR2);
      my_putstr("\n\nenemy connected");
    }
  else
    {
      if (kill(my_getnbr(av[1]), SIGUSR2) == -1)
	return (disp_err("Invalid PID\n"));
      if (get_pid(player) == ERROR)
	return (ERROR);
      my_putstr("successfully connected");
    }
  if (convert_pos(player) == ERROR)
    return (disp_err("\nnavy_position invalid\n"));
  put_boat_on_map(player);
  if (enough_boats(player) == ERROR)
    return (disp_err("\nnavy_position invalid\n"));
  return (lets_play(player));
}
