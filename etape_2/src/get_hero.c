/*
** get_hero.c for get_hero.c in /home/abgral_f/rendu/T2Rush1/etape_2/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar  8 12:04:30 2014 abgral_f
** Last update Sun Mar  9 11:19:02 2014 abgral_f
*/

#include		<stdlib.h>
#include		"epikong.h"

int			get_hero(t_map *map)
{
  int                   x;
  int                   y;

  if ((map->hero = malloc(sizeof (*(map->hero)))) == NULL)
    return (error(MALLOC_ERR));
  y = 0;
  while (map->map[y] != NULL)
    {
      x = 0;
      while (x != map->size_column)
        {
          if (map->map[y][x] == HERO)
            {
	      map->hero->x = x;
	      map->hero->y = y;
	      map->hero->direc = HERO;
	      return (EXIT_SUCCESS);
	    }
          x++;
        }
      y++;
    }
  return (error(HERO_ERR));
}
