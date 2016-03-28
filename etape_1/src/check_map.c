/*
** check_map.c for check_map.c in /home/abgral_f/rendu/T2Rush1/etape_1/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Mar  9 13:25:52 2014 abgral_f
** Last update Sun Mar  9 13:33:33 2014 abgral_f
*/

#include		<stdlib.h>
#include		"epikong.h"

int			check_map(t_map *map)
{
  int			y;
  int			x;

  y = 0;
  x = 0;
  while (x != map->size_column)
    {
      if (map->map[y][x] != WALL)
	return (error(MAP_WALL));
      x++;
    }
  while (y != map->size_line)
    {
      if (map->map[y][0] != WALL || map->map[y][map->size_column - 1] != WALL)
	return (error(MAP_WALL));
      y++;
    }
  x = 0;
  while (x != map->size_column)
    {
      if (map->map[y - 1][x] != WALL)
	return (error(MAP_WALL));
      x++;
    }
  return (EXIT_SUCCESS);
}
