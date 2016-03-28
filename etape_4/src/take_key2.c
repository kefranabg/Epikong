/*
** take_key2.c for epikong in /home/kersal_e/Dropbox/rush1 (1)/etape_4
**
** Made by Elliot Kersale
** Login   <kersal_e@epitech.net>
**
** Started on  Sun Mar  9 20:41:58 2014 Elliot Kersale
** Last update Sun Mar  9 21:23:42 2014 manzan_m
*/

#include		"epikong.h"

int                    take_gun(t_map *map, SDL_Surface *screen, t_conf *conf)
{
  if (map->map[map->hero->y][map->hero->x + 1] == GUN)
    {
      do_effects(map->sound_gun);
      map->hero->gun = 1;
      map->x = map->hero->x + 1;
      map->y = map->hero->y;
      key_depop(map, screen, conf);
    }
  if (map->map[map->hero->y][map->hero->x - 1] == GUN)
    {
      do_effects(map->sound_gun);
      map->hero->gun = 1;
      map->x = map->hero->x - 1;
      map->y = map->hero->y;
      key_depop(map, screen, conf);
    }
  take_gun_end(map, screen, conf);
  return (EXIT_SUCCESS);
}

void			take_gun_end(t_map *map, SDL_Surface *screen,
				     t_conf *conf)
{
  if (map->map[map->hero->y - 1][map->hero->x] == GUN)
    {
      do_effects(map->sound_gun);
      map->hero->gun = 1;
      map->x = map->hero->x;
      map->y = map->hero->y - 1;
      key_depop(map, screen, conf);
    }
  if (map->map[map->hero->y + 1][map->hero->x] == GUN)
    {
      do_effects(map->sound_gun);
      map->hero->gun = 1;
      map->x = map->hero->x;
      map->y = map->hero->y + 1;
      key_depop(map, screen, conf);
    }
}

int                    take_life(t_map *map, SDL_Surface *screen, t_conf *conf)
{
  if (map->hero->life == 3)
    return (EXIT_SUCCESS);
  if (map->map[map->hero->y][map->hero->x + 1] == EXTRALIFE)
    {
      do_effects(map->sound_xlife);
      add_life(map, conf, screen);
      map->hero->key = 1;
      map->x = map->hero->x + 1;
      map->y = map->hero->y;
      key_depop(map, screen, conf);
    }
  if (map->map[map->hero->y][map->hero->x - 1] == EXTRALIFE)
    {
      do_effects(map->sound_xlife);
      add_life(map, conf, screen);
      map->hero->key = 1;
      map->x = map->hero->x - 1;
      map->y = map->hero->y;
      key_depop(map, screen, conf);
    }
  take_life_end(map, screen, conf);
  return (EXIT_SUCCESS);
}

void			take_life_end(t_map *map, SDL_Surface *screen,
				     t_conf *conf)
{
  if (map->map[map->hero->y - 1][map->hero->x] == EXTRALIFE)
    {
      do_effects(map->sound_xlife);
      add_life(map, conf, screen);
      map->x = map->hero->x;
      map->y = map->hero->y - 1;
      key_depop(map, screen, conf);
    }
  if (map->map[map->hero->y + 1][map->hero->x] == EXTRALIFE)
    {
      do_effects(map->sound_xlife);
      add_life(map, conf, screen);
      map->x = map->hero->x;
      map->y = map->hero->y + 1;
      key_depop(map, screen, conf);
    }
}
