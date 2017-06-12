/*
** is_pos_valid.c for navy in /home/benjamin.g/delivery/PSU_2016_navy
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Feb  1 13:31:09 2017 Benjamin GAYMAY
** Last update Fri Feb  3 13:24:39 2017 benoit pingris
*/

#include <stdlib.h>
#include "my.h"

char	*is_pos_valid_2(char *str, int i, char *boats)
{
  if (my_strincmp(str, "2:", i, 1) == 0)
    boats[0] = boats[0] + 1;
  if (my_strincmp(str, "3:", i, 1) == 0)
    boats[1] = boats[1] + 1;
  if (my_strincmp(str, "4:", i, 1) == 0)
    boats[2] = boats[2] + 1;
  if (my_strincmp(str, "5:", i, 1) == 0)
    boats[3] = boats[3] + 1;
  return (boats);
}

int	is_pos_valid(char *str)
{
  char	*boats;
  int	i;

  i = 0;
  boats = my_strcpy(boats, "0000\0");
  while (str[i] != '\0')
    {
      if ((i == 0) || (str[i - 1] == '\n'))
	boats = is_pos_valid_2(str, i, boats);
      i++;
    }
  if (my_strcmp(boats, "1111") == 0)
    {
      free(boats);
      return (1);
    }
  free(boats);
  return (0);
}
