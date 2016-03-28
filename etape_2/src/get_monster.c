/*
** get_monster.c for get_monster.c in /home/abgral_f/rendu/T2Rush1/etape_2/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar  8 11:49:30 2014 abgral_f
** Last update Sat Mar  8 20:35:45 2014 abgral_f
*/

#include		<stdlib.h>
#include		"epikong.h"

int			add_monster(t_map *map, int x, int y)
{
  t_monster		*new;
  t_monster		*tmp;

  if ((new = malloc(sizeof (*new))) == NULL)
    return (error(MALLOC_ERR));
  new->x = x;
  new->check = 1;
  new->y = y;
  new->next = NULL;
  if (map->first == NULL)
    {
      map->first = new;
      return (EXIT_SUCCESS);
    }
  tmp = map->first;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (EXIT_SUCCESS);
}

int			get_monster(t_map *map)
{
  int			x;
  int			y;

  map->first = NULL;
  y = 0;
  while (map->map[y] != NULL)
    {
      x = 0;
      while (x != map->size_column)
	{
	  if (map->map[y][x] == MONSTER)
	    {
	      if (add_monster(map, x, y) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	    }
	  x++;
	}
      y++;
    }
  return (EXIT_SUCCESS);
}
