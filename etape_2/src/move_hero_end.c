/*
** move_hero_end.c for move_hero_end.c in /home/abgral_f/rendu/T2Rush1/etape_2/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Mar  9 16:56:40 2014 abgral_f
** Last update Sun Mar  9 17:04:30 2014 abgral_f
*/

#include		<stdlib.h>
#include                "epikong.h"

void			move_left_two(t_map *map,
				  SDL_Surface *screen, t_conf *conf)
{
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x]);
  conf->posx = (map->hero->x + 1) * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x + 1]);
}

int                     move_left(t_map *map,
				  SDL_Surface *screen, t_conf *conf)
{
  map->hero->direc = HERO_L;
  if (map->map[map->hero->y][map->hero->x - 1] == SCALE)
    {
      scale_case(map);
      map->hero->x -= 1;
      map->map[map->hero->y][map->hero->x] = HERO_SCALE;
    }
  else if (map->map[map->hero->y][map->hero->x - 1] != WALL
           && map->map[map->hero->y][map->hero->x - 1] != MONSTER
           && map->map[map->hero->y][map->hero->x - 1] != EXITCASE
           && map->map[map->hero->y][map->hero->x - 1] != ENTERCASE
           && (map->map[map->hero->y + 1][map->hero->x] == WALL ||
	       map->map[map->hero->y + 1][map->hero->x] == SCALE)
           && map->hero->x - 1 >= 0)
    {
      scale_case(map);
      map->hero->x -= 1;
      map->map[map->hero->y][map->hero->x] = HERO_L;
    }
  move_left_two(map, screen, conf);
  return (EXIT_SUCCESS);
}

void			move_right_two(t_map *map,
				       SDL_Surface *screen, t_conf *conf)
{
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x]);
  conf->posx = (map->hero->x - 1) * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x - 1]);
}

int                     move_right(t_map *map,
                                   SDL_Surface *screen, t_conf *conf)
{
  map->hero->direc = HERO_R;
  if (map->map[map->hero->y][map->hero->x + 1] == SCALE)
    {
      scale_case(map);
      map->hero->x += 1;
      map->map[map->hero->y][map->hero->x] = HERO_SCALE;
    }
  else if (map->map[map->hero->y][map->hero->x + 1] != WALL
           && map->map[map->hero->y][map->hero->x + 1] != MONSTER
           && map->map[map->hero->y][map->hero->x + 1] != EXITCASE
           && map->map[map->hero->y][map->hero->x + 1] != ENTERCASE
           && (map->map[map->hero->y + 1][map->hero->x] == WALL ||
               map->map[map->hero->y + 1][map->hero->x] == SCALE)
           && map->hero->x + 1 < map->size_column)
    {
      scale_case(map);
      map->hero->x += 1;
      map->map[map->hero->y][map->hero->x] = HERO_R;
    }
  move_right_two(map, screen, conf);
  return (EXIT_SUCCESS);
}
