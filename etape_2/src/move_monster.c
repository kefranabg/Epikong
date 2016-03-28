/*
** move_monster.c for move_monster.c in /home/abgral_f/rendu/T2Rush1/etape_2/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar  8 22:12:18 2014 abgral_f
** Last update Sun Mar  9 10:36:35 2014 abgral_f
*/

#include		<stdlib.h>
#include		"epikong.h"

void			move_monster_left(t_map *map,
					  t_conf *conf, SDL_Surface *screen,
					  t_monster **tmp)
{
  if (map->map[(*tmp)->y][(*tmp)->x - 1] != WALL
      && map->map[(*tmp)->y][(*tmp)->x - 1] != MONSTER
      && map->map[(*tmp)->y][(*tmp)->x - 1] != EXITCASE
      && map->map[(*tmp)->y][(*tmp)->x - 1] != ENTERCASE
      && map->map[(*tmp)->y][(*tmp)->x - 1] != HERO
      && map->map[(*tmp)->y][(*tmp)->x - 1] != HERO_R
      && map->map[(*tmp)->y][(*tmp)->x - 1] != HERO_L
      && map->map[(*tmp)->y][(*tmp)->x - 1] != KEYCASE
      && map->map[(*tmp)->y][(*tmp)->x - 1] != SCALE
      && (map->map[(*tmp)->y + 1][(*tmp)->x - 1] == WALL ||
	  map->map[(*tmp)->y + 1][(*tmp)->x - 1] == SCALE)
      && (*tmp)->x - 1 > 0 && (*tmp)->check == 0)
    {
      map->map[(*tmp)->y][(*tmp)->x] = SPACE;
      (*tmp)->x -= 1;
      map->map[(*tmp)->y][(*tmp)->x] = MONSTER;
      conf->posx = (*tmp)->x * SIZECUBE;
      conf->posy = (*tmp)->y * SIZECUBE;
      find_texture(conf, screen, map->map[(*tmp)->y][(*tmp)->x]);
      conf->posx = ((*tmp)->x + 1) * SIZECUBE;
      conf->posy = (*tmp)->y * SIZECUBE;
      find_texture(conf, screen, map->map[(*tmp)->y][(*tmp)->x + 1]);
    }
  else
    (*tmp)->check = 1;
}

void			move_monster_right(t_map *map,
					   t_conf *conf, SDL_Surface *screen,
					   t_monster **tmp)
{
  if (map->map[(*tmp)->y][(*tmp)->x + 1] != WALL
      && map->map[(*tmp)->y][(*tmp)->x + 1] != MONSTER
      && map->map[(*tmp)->y][(*tmp)->x + 1] != EXITCASE
      && map->map[(*tmp)->y][(*tmp)->x + 1] != HERO
      && map->map[(*tmp)->y][(*tmp)->x + 1] != HERO_R
      && map->map[(*tmp)->y][(*tmp)->x + 1] != HERO_L
      && map->map[(*tmp)->y][(*tmp)->x + 1] != KEYCASE
      && map->map[(*tmp)->y][(*tmp)->x + 1] != ENTERCASE
      && map->map[(*tmp)->y][(*tmp)->x + 1] != SCALE
      && (map->map[(*tmp)->y + 1][(*tmp)->x + 1] == WALL ||
	  map->map[(*tmp)->y + 1][(*tmp)->x + 1] == SCALE)
      && (*tmp)->x + 1 < map->size_column && (*tmp)->check == 1)
    {
      map->map[(*tmp)->y][(*tmp)->x] = SPACE;
      (*tmp)->x += 1;
      map->map[(*tmp)->y][(*tmp)->x] = MONSTER;
      conf->posx = (*tmp)->x * SIZECUBE;
      conf->posy = (*tmp)->y * SIZECUBE;
      find_texture(conf, screen, map->map[(*tmp)->y][(*tmp)->x]);
      conf->posx = ((*tmp)->x - 1) * SIZECUBE;
      conf->posy = (*tmp)->y * SIZECUBE;
      find_texture(conf, screen, map->map[(*tmp)->y][(*tmp)->x - 1]);
    }
  else
    (*tmp)->check = 0;
}

void			move_monster(t_map *map,
				     t_conf *conf, SDL_Surface *screen, int *newtime)
{
  int			oldtime;
  t_monster		*tmp;

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
      *newtime = oldtime + 1000;
    }
}
