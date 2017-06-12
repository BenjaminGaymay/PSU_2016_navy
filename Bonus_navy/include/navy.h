/*
** navy.h for navy in /home/benjamin.g/delivery/PSU_2016_navy/include
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Jan 30 20:22:36 2017 Benjamin GAYMAY
** Last update Sat Feb  4 22:12:06 2017 Benjamin GAYMAY
*/

#ifndef NAVY_H_
# define NAVY_H_

# define ERROR 84
# define CLIGN "\033[5m"
# define BLUE "\033[1;34m"
# define RED "\033[1;31m"
# define RED2 "\033[31m"
# define WHITE "\033[0m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"

typedef struct	s_player
{
  int		id;
  int		play;
  int		pid;
  int		enemy_pid;
  int		boats_alive;
  char		**boats_position;
  char		**my_map;
  char		**enemy_map;
}		t_player;

extern int	g_pid;

int	disp_err(char *str);
int	aff_game(t_player *player, char **av);
int	convert_pos(t_player *player);
void	put_boat_on_map(t_player *player);
int	check_boats_alive(t_player *player);
int	is_pos_valid(char *str);
int	lets_play(t_player *player);
int	good_format(t_player *player);
int	send_attack(int attack, t_player *player);
int	deci_to_bin(char *str);
char	*get_cell(char bool, int do_or_not);

int	time_to_wait_2(t_player *player);
int	last_aff(t_player *player);

char	*new_cell(char *str);

void	put_x_o(t_player *player, int attack, int choice);
void	catch_0();
void	catch_1();
void	miss();
void	hit();
void	play_again();
void	win();

#endif /* !NAVY_H_ */
