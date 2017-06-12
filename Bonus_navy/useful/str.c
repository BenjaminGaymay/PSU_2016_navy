/*
** str.c for navy in /home/benoit.pingris/delivery/PSU_2016_navy/useful
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Feb  2 16:25:55 2017 benoit pingris
** Last update Thu Feb  2 16:32:12 2017 benoit pingris
*/

#include <unistd.h>
#include "navy.h"
#include "my.h"

void	my_putchar(char a)
{
  write(1, &a, 1);
}

int	my_swap(t_player *player, int i, int j, int k)
{
  char	c;
  char	**tmp;

  tmp = player->boats_position;
  c = tmp[i][j];
  tmp[i][j] = tmp[i][k];
  tmp[i][k] = c;
  return (0);
}

char	*my_swap_2(char *str)
{
  char	tmp;

  tmp = str[0];
  str[0] = str[1];
  str[1] = tmp;
  return (str);
}

int	my_put_nbr(int n)
{
  if (n < 0)
    {
      my_putchar('-');
      n = (n * (-1));
    }
  if ((n >= 0) && (n <= 9))
    my_putchar(n + '0');
  if (n > 9)
    {
      my_put_nbr(n / 10);
      my_put_nbr(n % 10);
    }
  return (0);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
