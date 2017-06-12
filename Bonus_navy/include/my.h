/*
** my.h for navy in /home/benoit.pingris/delivery/PSU_2016_navy/include
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Mon Jan 30 09:39:31 2017 benoit pingris
** Last update Sat Feb  4 21:38:29 2017 Benjamin GAYMAY
*/

#ifndef MY_H_
# define MY_H_

# include "navy.h"

void	my_putchar(char c);
void	my_showtab(char **array, char **array2);
void	my_putstr(char *str);

char	*my_swap_2(char *str);
char	*my_revstr(char *str);
char	*clear_my_str(char *str, char separator);
char	*get_next_line(int fd);
char	*my_str_uppercase(char *s);
char	*my_strcpy(char *dest, char *src);

int	my_getnbr(char *str);
int	my_strlen(char *str);
int	my_power_rec(int nb, int p);
int	my_swap(t_player *player, int i, int j, int k);
int	my_strincmp(char *s1, char *s2, int i, int j);
int	my_strcmp(char *s1, char *s2);
int	my_printf(char *format, ...);
int	my_fprintf(char *format, ...);
int	my_str_isnum(char *s);
int	my_put_nbr(int nb);
int	reverse_nb(int nb);

#endif /* !MY_H_ */
