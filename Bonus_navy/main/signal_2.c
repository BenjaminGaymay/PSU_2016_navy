/*
** signal_2.c for navy in /home/benoit.pingris/delivery/PSU_2016_navy
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Feb  3 11:13:12 2017 benoit pingris
** Last update Sat Feb  4 22:47:30 2017 Benjamin GAYMAY
*/

#include "my.h"
#include "navy.h"

void		hit()
{
  g_pid = 1;
  my_putstr(GREEN"hit\n"WHITE);
}

void	miss()
{
  g_pid = 0;
  my_putstr(RED2"missed\n"WHITE);
}

void	play_again()
{
  g_pid = 1;
}

void	win()
{
  g_pid = 0;
}
