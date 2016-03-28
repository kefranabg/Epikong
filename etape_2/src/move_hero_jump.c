/*
** move_hero_jump.c for move_hero_jump.c in /home/abgral_f/rendu/T2Rush1/etape_2/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar  8 21:38:23 2014 abgral_f
** Last update Sun Mar  9 10:15:51 2014 abgral_f
*/

#include		<stdlib.h>
#include		"epikong.h"

void			move_space_two(t_map *map,
				       SDL_Surface *screen, t_conf *conf)
{
  do_effects();
  scale_case(map);
  map->hero->y -= 2;
  map->map[map->hero->y][map->hero->x] = HERO;
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x]);
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = (map->hero->y + 2) * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y + 2][map->hero->x]);
}

void			move_space_one(t_map *map,
				       SDL_Surface *screen, t_conf *conf)
{
  do_effects();
  scale_case(map);
  map->hero->y -= 1;
  map->map[map->hero->y][map->hero->x] = HERO;
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x]);
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = (map->hero->y + 1) * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y + 1][map->hero->x]);
}

void			move_space_else(t_map *map,
					SDL_Surface *screen, t_conf *conf)
{
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x]);
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = (map->hero->y + 1) * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y + 1][map->hero->x]);
}
