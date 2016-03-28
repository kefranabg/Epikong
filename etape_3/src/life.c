/*
** life.c for life.c in /home/abgral_f/rendu/T2Rush1/etape_2/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Mar  9 11:41:18 2014 abgral_f
** Last update Sun Mar  9 13:49:40 2014 Elliot Kersale
*/

#include		<stdlib.h>
#include		"epikong.h"

void			life(t_map *map, t_conf *conf, SDL_Surface * screen)
{
  do_effects(map->sound_life);
  map->hero->life--;
  map->map[0][map->hero->life] = WALL;
  conf->posx = map->hero->life * SIZECUBE;
  conf->posy = 0;
  find_texture(conf, screen, map->map[0][map->hero->life]);
  if (map->hero->life == 0)
    map->hero->is_alive = FALSE;
}
