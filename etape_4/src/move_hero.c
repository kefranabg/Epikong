/*
** move_right.c for move_right.c in /home/abgral_f/rendu/T2Rush1/etape_2/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar  8 12:48:46 2014 abgral_f
** Last update Sun Mar  9 21:05:05 2014 Elliot Kersale
*/

#include		<stdlib.h>
#include		"epikong.h"

int			move_up(t_map *map,
				SDL_Surface *screen, t_conf *conf)
{
  if (map->map[map->hero->y - 1][map->hero->x] == MONSTER)
    life(map, conf, screen);
  map->hero->direc = HERO;
  if (map->map[map->hero->y - 1][map->hero->x] == SCALE
      && map->map[map->hero->y][map->hero->x] == HERO_SCALE
      && map->hero->y - 1 >= 0)
    {
      scale_case(map);
      map->hero->y -= 1;
      map->map[map->hero->y][map->hero->x] = HERO_SCALE;
    }
  else if (map->map[map->hero->y - 1][map->hero->x] != WALL
	   && map->map[map->hero->y - 1][map->hero->x] != MONSTER
	   && map->map[map->hero->y - 1][map->hero->x] != GUN
	   && map->map[map->hero->y - 1][map->hero->x] != EXITCASE
	   && map->map[map->hero->y - 1][map->hero->x] != EXTRALIFE)
    move_up2(map);
  move_space_else(map, screen, conf);
  return (EXIT_SUCCESS);
}

int			move_down(t_map *map,
				  SDL_Surface *screen, t_conf *conf)
{
  map->hero->direc = HERO;
  if (map->map[map->hero->y + 1][map->hero->x] == SCALE
      && map->hero->y + 1 < map->size_line)
    {
      scale_case(map);
      map->hero->y += 1;
      map->map[map->hero->y][map->hero->x] = HERO_SCALE;
    }
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x]);
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = (map->hero->y - 1) * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y - 1][map->hero->x]);
  return (EXIT_SUCCESS);
}

int			move_space(t_map *map,
				   SDL_Surface *screen, t_conf *conf)
{
  map->hero->direc = HERO;
  if (map->map[map->hero->y - 1][map->hero->x] != WALL
      && map->map[map->hero->y - 1][map->hero->x] != EXITCASE
      && map->map[map->hero->y - 1][map->hero->x] != KEYCASE
      && map->map[map->hero->y - 1][map->hero->x] != ENTERCASE
      && map->map[map->hero->y - 1][map->hero->x] != SCALE
      && map->map[map->hero->y - 1][map->hero->x] != GUN
      && map->map[map->hero->y - 1][map->hero->x] != EXTRALIFE
      && map->hero->y - 1 > 0)
    move_space2(map, conf, screen);
  else if (map->map[map->hero->y - 1][map->hero->x] != WALL
	   && map->map[map->hero->y - 1][map->hero->x] != EXTRALIFE
	   && map->map[map->hero->y - 1][map->hero->x] != GUN
	   && map->map[map->hero->y - 1][map->hero->x] != EXITCASE
	   && map->map[map->hero->y - 1][map->hero->x] != ENTERCASE
	   && map->map[map->hero->y - 1][map->hero->x] != SCALE
	   && map->hero->y - 1 > 0)
    move_space_one(map, screen, conf);
  return (EXIT_SUCCESS);
}

int			move_space_right(t_map *map,
					 SDL_Surface *screen, t_conf *conf)
{
  map->hero->direc = HERO_R;
  do_effects(map->sound_jump);
  if (map->map[map->hero->y - 1][map->hero->x + 2] != WALL
      && map->map[map->hero->y - 1][map->hero->x + 2] != EXITCASE
      && map->map[map->hero->y - 1][map->hero->x + 2] != EXTRALIFE
      && map->map[map->hero->y - 1][map->hero->x + 2] != ENTERCASE
      && map->map[map->hero->y - 1][map->hero->x + 2] != KEYCASE
      && map->map[map->hero->y - 1][map->hero->x + 2] != SCALE
      && map->map[map->hero->y - 1][map->hero->x + 2] != MONSTER
      && map->map[map->hero->y - 1][map->hero->x + 2] != GUN
      && map->hero->y - 1 > 0 && map->hero->x + 2 < map->size_column)
    {
      scale_case(map);
      map->hero->y -= 1;
      map->hero->x += 2;
      map->map[map->hero->y][map->hero->x] = HERO_R;
      conf->posx = map->hero->x * SIZECUBE;
      conf->posy = map->hero->y * SIZECUBE;
      find_texture(conf, screen, map->map[map->hero->y][map->hero->x]);
      conf->posx = (map->hero->x - 2) * SIZECUBE;
      conf->posy = (map->hero->y + 1) * SIZECUBE;
      find_texture(conf, screen, map->map[map->hero->y + 1][map->hero->x - 2]);
    }
  return (EXIT_SUCCESS);
}

int			move_space_left(t_map *map,
					SDL_Surface *screen, t_conf *conf)
{
  map->hero->direc = HERO_L;
  do_effects(map->sound_jump);
  if (map->map[map->hero->y - 1][map->hero->x - 2] != WALL
      && map->map[map->hero->y - 1][map->hero->x - 2] != EXTRALIFE
      && map->map[map->hero->y - 1][map->hero->x - 2] != EXITCASE
      && map->map[map->hero->y - 1][map->hero->x - 2] != ENTERCASE
      && map->map[map->hero->y - 1][map->hero->x - 2] != SCALE
      && map->map[map->hero->y - 1][map->hero->x - 2] != GUN
      && map->map[map->hero->y - 1][map->hero->x - 2] != KEYCASE
      && map->map[map->hero->y - 1][map->hero->x - 2] != MONSTER
      && map->hero->y - 1 > 0 && map->hero->x - 2 >= 0)
    {
      scale_case(map);
      map->hero->y -= 1;
      map->hero->x -= 2;
      map->map[map->hero->y][map->hero->x] = HERO_L;
      conf->posx = map->hero->x * SIZECUBE;
      conf->posy = map->hero->y * SIZECUBE;
      find_texture(conf, screen, map->map[map->hero->y][map->hero->x]);
      conf->posx = (map->hero->x + 2) * SIZECUBE;
      conf->posy = (map->hero->y + 1) * SIZECUBE;
      find_texture(conf, screen, map->map[map->hero->y + 1][map->hero->x + 2]);
    }
  return (EXIT_SUCCESS);
}
