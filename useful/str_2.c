/*
** str_2.c for navy in /home/benoit.pingris/delivery/PSU_2016_navy/useful
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Feb  2 16:50:14 2017 benoit pingris
** Last update Fri Feb  3 13:54:28 2017 benoit pingris
*/

#include <stdlib.h>
#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while ((i < n - 1) && (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    i++;
  return (s1[i] - s2[i]);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    i++;
  return (s1[i] - s2[i]);
}

int	my_strincmp(char *s1, char *s2, int i, int j)
{
  int	h;

  h = 0;
  while (s1[i] == s2[h] && j > 0)
    {
      i++;
      h++;
      j--;
    }
  return (s1[i] - s2[h]);
}

char	*clear_my_str(char *str, char separator)
{
  int	i;
  int	h;
  char	*new;

  h = 0;
  i = 0;
  if (str == NULL)
    return (NULL);
  if ((new = malloc(sizeof(new) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] == separator)
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == separator)
	new[h++] = ' ';
      while (str[i] == separator)
	i++;
      new[h++] = str[i++];
    }
  if (new[my_strlen(new) - 1] == separator)
    new[my_strlen(new) - 1] = '\0';
  free(str);
  return (new);
}
