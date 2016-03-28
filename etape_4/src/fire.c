/*
** fire.c for fire.c in /home/abgral_f/final/etape_4/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Mar  9 18:39:16 2014 abgral_f
** Last update Sun Mar  9 20:16:10 2014 manzan_m
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		"epikong.h"

void			fire_left(t_map *map, SDL_Surface *screen, t_conf *conf)
{
  int			i;
  t_monster             *tmp;

  i = 0;
  while (map->hero->x - i >= 0
	 && map->map[map->hero->y][map->hero->x - i] != MONSTER)
    i++;
  if (i <= 4)
    {
      if (map->map[map->hero->y][map->hero->x - i] == MONSTER)
	{
	  tmp = map->first;
	  while (map->hero->y != tmp->y && map->hero->x - i != tmp->x)
	    tmp = tmp-> next;
	  tmp->life--;
	  if (tmp->life == 0)
	    {
	      delete_monster(tmp, map);
	      map->map[map->hero->y][map->hero->x - i] = SPACE;
	      conf->posx = (map->hero->x - i) * SIZECUBE;
	      conf->posy = map->hero->y * SIZECUBE;
	      find_texture(conf, screen, map->map[map->hero->y][map->hero->x - i]);
	    }
	}
    }
}

void			fire_right(t_map *map, SDL_Surface *screen, t_conf *conf)
{
  int			i;
  t_monster             *tmp;

  i = 0;
  while (map->hero->x + i < map->size_column
	 && map->map[map->hero->y][map->hero->x + i] != MONSTER)
    i++;
  if (i <= 4)
    {
      if (map->map[map->hero->y][map->hero->x + i] == MONSTER)
	{
	  tmp = map->first;
	  while (map->hero->y != tmp->y && map->hero->x + i != tmp->x)
	    tmp = tmp-> next;
	  tmp->life--;
	  if (tmp->life == 0)
	    {
	      delete_monster(tmp, map);
	      map->map[map->hero->y][map->hero->x + i] = SPACE;
	      conf->posx = (map->hero->x + i) * SIZECUBE;
	      conf->posy = map->hero->y * SIZECUBE;
	      find_texture(conf, screen, map->map[map->hero->y][map->hero->x + i]);
	    }
	}
    }
}

int			fire(t_map *map, SDL_Surface *screen, t_conf *conf)
{
  if (map->hero->direc == HERO_R && map->hero->gun == 1)
    {
      do_effects(map->sound_fire);
      fire_right(map, screen, conf);
    }
  if (map->hero->direc == HERO_L && map->hero->gun == 1)
    {
      do_effects(map->sound_fire);
      fire_left(map, screen, conf);
    }
  return (EXIT_SUCCESS);
}
