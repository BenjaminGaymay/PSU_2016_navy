/*
** attack.c for navy in /home/benoit.pingris/delivery/PSU_2016_navy
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Thu Feb  2 11:57:48 2017 benoit pingris
** Last update Wed Feb 15 13:50:00 2017 Benjamin GAYMAY
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "navy.h"
#include "my_printf.h"

int	deci_to_bin(char *str)
{
  int	i;
  int	res;
  char	*no_letter;

  i = 0;
  if ((no_letter = malloc(sizeof(no_letter) * 4)) == NULL)
    return (ERROR);
  no_letter[0] = '\0';
  while (str[i])
    {
      if (str[i] >= 'A' && str[i] <= 'H')
	no_letter[i] = str[i] - 16;
      else
	no_letter[i] = str[i] - 1;
      i++;
    }
  no_letter[i] = '\0';
  res = my_getnbr(no_letter);
  free(no_letter);
  return (res);
}

void	send_attack_2(char *binary, t_player *player)
{
  int	i;

  i = 0;
  while (binary[i] != '\0')
    {
      usleep(7500);
      if (binary[i] == '0')
	kill(player->enemy_pid, SIGUSR1);
      if (binary[i] == '1')
	kill(player->enemy_pid, SIGUSR2);
      i++;
    }
}
int	send_attack(int attack, t_player *player)
{
  char	*binary;
  int	tmp;
  int	i;

  i = 0;
  binary = my_strcpy(binary, "0000000\0");
  while (attack != 0)
    {
      tmp = attack % 2;
      tmp = tmp + '0';
      attack = attack / 2;
      binary[i] = tmp;
      i++;
    }
  binary = my_revstr(binary);
  send_attack_2(binary, player);
  free(binary);
  return (0);
}
