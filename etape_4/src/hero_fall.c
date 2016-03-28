/*
** hero_fall.c for hero_fall.c in /home/abgral_f/rendu/T2Rush1/etape_2/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar  8 21:56:28 2014 abgral_f
** Last update Sun Mar  9 19:46:19 2014 manzan_m
*/

#include		<stdlib.h>
#include                <unistd.h>
#include		"epikong.h"

void			falling(int i, t_map *map)
{
  if (i > 5)
    map->hero->is_alive = FALSE;
}

int			fall_exp(t_map *map, int *fall, int *i)
{
  int			y;
  int			tmp;

  *fall *= 2;
  y = map->hero->y;
  while (y != *fall + map->hero->y && map->map[y + 1][map->hero->x] != WALL
	 && map->map[y + 1][map->hero->x] != EXITCASE
	 && map->map[y + 1][map->hero->x] != GUN
	 && map->map[y + 1][map->hero->x] != EXTRALIFE
	 && map->map[y + 1][map->hero->x] != MONSTER
	 && map->map[y + 1][map->hero->x] != KEYCASE
	 && map->map[y + 1][map->hero->x] != ENTERCASE
	 && map->map[y + 1][map->hero->x] != SCALE)
      y++;
  tmp = y - map->hero->y;
  *i = *i + tmp;
  return (tmp);
}

void			hero_fall_end(t_map *map, int *tmp, int *fall, int *i)
{
  map->map[map->hero->y][map->hero->x] = SPACE;
  *tmp = fall_exp(map, fall, i);
  map->hero->y += *tmp;
  map->map[map->hero->y][map->hero->x] = map->hero->direc;
}

void			hero_fall_end_end(t_map *map, t_conf *conf,
					  SDL_Surface *screen, int *tmp)
{
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x]);
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = (map->hero->y - *tmp) * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y - *tmp][map->hero->x]);
}

void			hero_fall(t_map *map, t_conf *conf, SDL_Surface *screen)
{
  int			i;
  int			fall;
  int			tmp;

  i = 0;
  fall = 1;
  if (map->map[map->hero->y][map->hero->x] != HERO_SCALE)
    {
      while (map->map[map->hero->y + 1][map->hero->x] != WALL
	     && map->map[map->hero->y + 1][map->hero->x] != EXITCASE
	     && map->map[map->hero->y + 1][map->hero->x] != EXTRALIFE
	     && map->map[map->hero->y + 1][map->hero->x] != MONSTER
	     && map->map[map->hero->y + 1][map->hero->x] != KEYCASE
	     && map->map[map->hero->y + 1][map->hero->x] != ENTERCASE
	     && map->map[map->hero->y + 1][map->hero->x] != GUN
	     && map->map[map->hero->y + 1][map->hero->x] != SCALE)
	{
	  usleep(90000);
	  hero_fall_end(map, &tmp, &fall, &i);
	  hero_fall_end_end(map, conf, screen, &tmp);
	  i++;
	}
      falling(i, map);
    }
}
