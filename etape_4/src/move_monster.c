/*
** move_monster.c for move_monster.c in /home/abgral_f/rendu/T2Rush1/etape_2/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar  8 22:12:18 2014 abgral_f
** Last update Sun Mar  9 17:51:39 2014 Elliot Kersale
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"epikong.h"

void			move_monster_left(t_map *map,
					  t_conf *conf, SDL_Surface *screen,
					  t_monster **tmp)
{
 if (map->map[(*tmp)->y][(*tmp)->x - 1] == HERO
      || map->map[(*tmp)->y][(*tmp)->x - 1] == HERO_R
      || map->map[(*tmp)->y][(*tmp)->x - 1] == HERO_L)
    {
      life(map, conf, screen);
      (*tmp)->check = 1;
    }
 if (move_monster_left_end(map, conf, screen, tmp) == 0)
   return ;
 else
   (*tmp)->check = 1;
}

void			move_monster_right(t_map *map,
					   t_conf *conf, SDL_Surface *screen,
					   t_monster **tmp)
{
  if (map->map[(*tmp)->y][(*tmp)->x + 1] == HERO
      || map->map[(*tmp)->y][(*tmp)->x + 1] == HERO_R
      || map->map[(*tmp)->y][(*tmp)->x + 1] == HERO_L)
    {
      life(map, conf, screen);
      (*tmp)->check = 0;
    }
  if (move_monster_right_end(map, conf, screen, tmp) == 0)
    return ;
  else
    (*tmp)->check = 0;
}

void			move_monster(t_map *map, t_conf *conf,
				     SDL_Surface *screen,
				     int *newtime)
{
  int			oldtime;
  t_monster		*tmp;
  int			i;

  i = 0;
  while (i != 4)
    {
      oldtime = SDL_GetTicks();
      tmp = map->first;
      if (oldtime > *newtime)
	{
	  while (tmp != NULL)
	    {
	      move_monster_left(map, conf, screen, &tmp);
	      move_monster_right(map, conf, screen, &tmp);
	      tmp = tmp->next;
	    }
	  *newtime = oldtime + 100;
	}
      i++;
      usleep(150000);
    }
}
