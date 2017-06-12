/*
** signal.c for navy in /home/benjamin.g/delivery/PSU_2016_navy
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Thu Feb  2 16:26:45 2017 Benjamin GAYMAY
** Last update Fri Feb  3 11:13:50 2017 benoit pingris
*/
#include "navy.h"

char	*get_cell(char bool, int do_or_not)
{
  static char	my_bin[8] = "0000000\0";
  static int	i = 0;

  if (do_or_not == 1)
    {
      if (i == 7)
	i = 0;
      my_bin[i] = bool;
      ++i;
    }
  return (my_bin);
}

void	catch_0()
{
  get_cell('0', 1);
}

void	catch_1()
{
  get_cell('1', 1);
}
