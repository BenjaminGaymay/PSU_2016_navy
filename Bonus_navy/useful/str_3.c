/*
** str_3.c for navy in /home/benoit.pingris/delivery/PSU_2016_navy/useful
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Feb  2 16:57:47 2017 benoit pingris
** Last update Thu Feb  2 17:00:28 2017 benoit pingris
*/

#include <stdlib.h>
#include "navy.h"

int	my_strlen(char *s)
{
  int	i;

  i = 0;
  while  (s[i] != '\0')
    i++;
  return (i);
}

char	*my_strcpy(char *s1, char *s2)
{
  int	i;

  if ((s1 = malloc(sizeof(char) * (my_strlen(s2) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (s2[i] != '\0')
    {
      s1[i] = s2[i];
      i++;
    }
  s1[i] = '\0';
  return (s1);
}

char	*my_revstr(char *str)
{
  int	i;
  int	f;
  int	tmp;

  i = 0;
  while (str[i] != '\0')
    i++;
  i--;
  f = 0;
  tmp = 0;
  while (i > f)
    {
      tmp = str[f];
      str[f] = str[i];
      str[i] = tmp;
      i--;
      f++;
    }
  return (str);
}

int	my_str_isnum(char *str)
{
  int	i;
  int	f;

  i = 0;
  f = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0') || (str[i] > '9'))
	f++;
      i++;
    }
  return (f != 0 ? 0 : 1);
}

char	*my_str_uppercase(char *s)
{
  int	i;

  i = 0;
  while (s[i] != '\0')
    {
      if (s[i] >= 'a' && s[i] <= 'z')
	s[i] = s[i] - 32;
      i++;
    }
  return (s);
}
