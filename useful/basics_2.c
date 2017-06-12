/*
** basics_2.c for navy in /home/benoit.pingris/delivery/PSU_2016_navy
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Feb  2 21:25:27 2017 benoit pingris
** Last update Thu Feb  2 21:58:59 2017 benoit pingris
*/

int	reverse_nb(int nb)
{
  int	tmp;
  int	rev;

  rev = 0;
  while (nb != 0)
    {
      tmp = nb % 10;
      rev = rev * 10 + tmp;
      nb /= 10;
    }
  return (rev);
}
