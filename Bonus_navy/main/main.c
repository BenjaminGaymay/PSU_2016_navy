/*
** main.c for navy in /home/benoit.pingris/delivery/PSU_2016_navy
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Tue Jan 31 13:40:40 2017 benoit pingris
** Last update Mon Feb  6 12:55:51 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "use_array.h"
#include "my.h"
#include "navy.h"

int		disp_err(char *str)
{
  my_fprintf("%s", str);
  return (ERROR);
}

int		disp_help()
{
  my_printf("USAGE\n\t./navy [first_player_pid] navy_positions\n\n");
  my_printf("DESCRIPTION\n\tfirst_player_pid\tonly for the 2nd player.");
  my_printf(" pid of the first player,\n\tnavy_positions\t\tfile ");
  my_printf("representing the positions of the ships.\n");
  return (0);
}

int	error_return(char **av, char *map, int id)
{
  int	fd;

  if (my_str_isnum(av[1]) != 1 && id == 2)
    return (disp_err("the PID must contains only numbers\n"));
  if ((fd = open(av[id], O_RDONLY)) == -1)
    return (disp_err("could not open the file\n"));
  if (read(fd, map, 31) == -1)
    return (disp_err("could not read the file\n"));
  if (close(fd) == -1)
    return (disp_err("could not close the file \n"));
  if (is_pos_valid(map) == 0)
    return (disp_err("position aren't valid\n"));
  return (0);
}

int	set_struct(int ac, char *map, t_player *player)
{
  char	empty_map[72];

  empty_map[71] = '\0';
  if (ac == 3)
    {
      player->id = 2;
      player->play = 0;
    }
  else
    {
      player->id = 1;
      player->play = 1;
    }
  if (read(open("empty", O_RDONLY), empty_map, 73) == -1)
    return (ERROR);
  player->enemy_map = create_array(empty_map, '\n');
  player->my_map = create_array(empty_map, '\n');
  player->pid = getpid();
  player->boats_position = create_array(my_str_uppercase(map), '\n');
  check_boats_alive(player);
  return (0);
}

int		main(int ac, char **av)
{
  t_player	player;
  char		map[32];
  int		ret;

  map[31] = '\0';
  if (ac == 2 && my_strcmp(av[1], "-h") == 0)
    return (disp_help());
  else if (ac != 2 && ac != 3)
    return (disp_err("invalid number of arguments\n"));
  if (error_return(av, map, ac - 1) == ERROR)
    return (ERROR);
  if (set_struct(ac, map, &player) == ERROR)
    return (ERROR);
  if (good_format(&player) == ERROR)
    return (ERROR);
  if ((ret = aff_game(&player, av)) == ERROR)
    return (ERROR);
  free_array(player.my_map);
  free_array(player.enemy_map);
  free_array(player.boats_position);
  return (ret);
}
