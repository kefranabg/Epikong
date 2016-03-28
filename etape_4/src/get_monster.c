/*
** get_monster.c for get_monster.c in /home/abgral_f/rendu/T2Rush1/etape_2/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar  8 11:49:30 2014 abgral_f
** Last update Sun Mar  9 20:00:15 2014 abgral_f
*/

#include		<stdlib.h>
#include		"epikong.h"

int			delete_monster(t_monster *to_del, t_map *map)
{
  t_monster             *tmp;

  do_effects(map->sound_die);
  tmp = map->first;
  if (tmp == to_del)
    {
      map->first = tmp->next;
      free(to_del);
      tmp = map->first;
      while (tmp != NULL)
	  tmp = tmp->next;
      return (EXIT_SUCCESS);
    }
  while (tmp->next != to_del)
    tmp = tmp->next;
  if (tmp != NULL)
    tmp->next = to_del->next;
  free(to_del);
  return (EXIT_SUCCESS);
}

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
  new->life = 3;
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
