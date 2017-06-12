/*
** convert.c for navy in /home/benoit.pingris/delivery/PSU_2016_navy
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Wed Feb  1 14:26:59 2017 benoit pingris
** Last update Fri Feb 17 22:48:30 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "navy.h"

int	good_format(t_player *player)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (player->boats_position[i] != NULL)
    {
      if (my_strlen(player->boats_position[i++]) != 7)
	return (ERROR);
    }
  if (i != 4)
    return (ERROR);
  return (0);
}

int	check_pos(t_player *player, int i, int j, int k)
{
  char	**tmp;
  char	swap;

  tmp = player->boats_position;
  if ((tmp[i][j] >= 'A' && tmp[i][j] <= 'H')
      && tmp[i][k] >= 'A' && tmp[i][k] <= 'H')
    return (ERROR);
  else if ((tmp[i][j] >= '1' && tmp[i][j] <= '8')
	   && tmp[i][k] >= '1' && tmp[i][k] <= '8')
    return (ERROR);
  else if ((tmp[i][j] >= '1' && tmp[i][j] <= '8')
	   && tmp[i][k] >= 'A' && tmp[i][k] <= 'H')
    return (my_swap(player, i, j, k));
  else
    return (ERROR);
}

int	good_pos(t_player *player)
{
  int	i;
  int	c;
  char	**tmp;

  i = 0;
  c = 0;
  if (good_format(player) == ERROR)
    return (ERROR);
  tmp = player->boats_position;
  while (tmp[i] != NULL)
    {
      if (!(tmp[i][2] >= 'A' && tmp[i][2] <= 'H'
	   && tmp[i][3] >= '1' && tmp[i][3] <= '8'))
	c = check_pos(player, i , 2, 3);
      else if (!(tmp[i][5] >= 'A' && tmp[i][5] <= 'H'
		 && tmp[i][6] >= '1' && tmp[i][6] <= '8'))
	c = check_pos(player, i, 5, 6);
      if (c == ERROR)
	return (ERROR);
      i++;
    }
  return (0);
}

int	check_pos_size(t_player *player)
{
  char	**tmp;
  int	nb1;
  int	nb2;
  int	i;

  tmp = player->boats_position;
  i = 0;
  while (tmp[i] != NULL)
    {
      if (tmp[i][2] != tmp[i][5] && tmp[i][3] != tmp[i][6])
	return (ERROR);
      else
	{
	  nb1 = (tmp[i][2] - 48) * 10 + (tmp[i][3] - 48);
	  nb2 = (tmp[i][5] - 48) * 10 + (tmp[i][6] - 48);
	  if (nb2 < nb1)
	    {
	      my_swap(player, i, 2, 5);
	      my_swap(player, i, 3, 6);
	    }
	}
      i++;
    }
}

int	convert_pos(t_player *player)
{
  int	i;
  int	j;
  char	**tmp;

  i = 0;
  tmp = player->boats_position;
  if (good_pos(player) == ERROR)
    return (ERROR);
  while (tmp[i] != NULL)
    {
      j = 2;
      while (tmp[i][j] != '\0')
	{
	  if (tmp[i][j] >= 'A' && tmp[i][j] <= 'H')
	    tmp[i][j] -= 17;
	  else if (tmp[i][j] >= '1' && tmp[i][j] <= '8')
	    tmp[i][j] -= 1;
	  else if (tmp[i][j] != ':')
	    return (ERROR);
	  j++;
	}
      i++;
    }
  check_pos_size(player);
  return (0);
}
