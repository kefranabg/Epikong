/*
** parse_map.c for parse_map.c in /home/manzan_m/project/c/rush/epikong/real
**
** Made by manzan_m
** Login   <manzan_m@epitech.net>
**
** Started on  Fri Mar  7 23:10:11 2014 manzan_m
** Last update Sun Mar  9 21:32:21 2014 abgral_f
*/

#include		<stdlib.h>
#include		"epikong.h"

int		parse_map(struct s_map *map)
{
  t_conf	conf;

  conf.posx = 0;
  conf.posy = 0;
  conf.winsize_w = map->size_line * SIZECUBE;
  if (conf.winsize_w > 1000)
    return (error(ERR_WSIZE));
  conf.winsize_h = map->size_column * SIZECUBE;
  if (conf.winsize_h > 1900)
    return (error(ERR_HSIZE));
  if (loop_screen(&conf, map->map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
