/*
** scale_case.c for scale_case.c in /home/abgral_f/rendu/T2Rush1/etape_2/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar  8 13:43:52 2014 abgral_f
** Last update Sat Mar  8 13:44:46 2014 abgral_f
*/

#include		<stdlib.h>
#include		"epikong.h"

void			scale_case(t_map *map)
{
  if (map->map[map->hero->y][map->hero->x] == '-')
    map->map[map->hero->y][map->hero->x] = 's';
  else
    map->map[map->hero->y][map->hero->x] = ' ';
}
