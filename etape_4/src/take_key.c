/*
** take_key.c for take_key.c in /home/abgral_f/tmp/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Mar  9 14:38:14 2014 abgral_f
** Last update Sun Mar  9 20:43:25 2014 Elliot Kersale
*/

#include                <stdlib.h>
#include		<unistd.h>
#include                "epikong.h"

int			key_and_door(t_map *map)
{
  if ((map->map[map->hero->y][map->hero->x + 1] == EXITCASE
       || map->map[map->hero->y][map->hero->x - 1] == EXITCASE
       || map->map[map->hero->y + 1][map->hero->x] == EXITCASE
       || map->map[map->hero->y - 1][map->hero->x + 1] == EXITCASE)
      && map->hero->key == 1)
    {
      do_effects(map->sound_door);
      sleep(2);
      map->hero->win = TRUE;
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

void                    key_depop(t_map *map, SDL_Surface *screen,
				  t_conf *conf)
{
  map->map[map->y][map->x] = SPACE;
  conf->posx = map->x * SIZECUBE;
  conf->posy = map->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->y][map->x]);
}

void			take_key_end(t_map *map, SDL_Surface *screen,
				     t_conf *conf)
{
  if (map->map[map->hero->y - 1][map->hero->x] == KEYCASE)
    {
      do_effects(map->sound_key);
      map->hero->key = 1;
      map->x = map->hero->x;
      map->y = map->hero->y - 1;
      key_depop(map, screen, conf);
    }
  if (map->map[map->hero->y + 1][map->hero->x] == KEYCASE)
    {
      do_effects(map->sound_key);
      map->hero->key = 1;
      map->x = map->hero->x;
      map->y = map->hero->y + 1;
      key_depop(map, screen, conf);
    }
}

int                    take_key(t_map *map, SDL_Surface *screen, t_conf *conf)
{
  if (map->map[map->hero->y][map->hero->x + 1] == KEYCASE)
    {
      do_effects(map->sound_key);
      map->hero->key = 1;
      map->x = map->hero->x + 1;
      map->y = map->hero->y;
      key_depop(map, screen, conf);
    }
  if (map->map[map->hero->y][map->hero->x - 1] == KEYCASE)
    {
      do_effects(map->sound_key);
      map->hero->key = 1;
      map->x = map->hero->x - 1;
      map->y = map->hero->y;
      key_depop(map, screen, conf);
    }
  take_key_end(map, screen, conf);
  return (EXIT_SUCCESS);
}
