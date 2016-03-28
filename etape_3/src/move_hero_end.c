/*
** move_hero_end.c for epikong in /home/kersal_e/Dropbox/rush1 (1)/lastlast/etape_3/src
**
** Made by Elliot Kersale
** Login   <kersal_e@epitech.net>
**
** Started on  Sun Mar  9 13:09:02 2014 Elliot Kersale
** Last update Sun Mar  9 15:58:31 2014 abgral_f
*/

#include		"epikong.h"

void			move_right_end(t_map *map, SDL_Surface *screen,
				       t_conf *conf)
{
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x]);
  conf->posx = (map->hero->x - 1) * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x - 1]);
}

void			move_left_end(t_map *map, SDL_Surface *screen,
				      t_conf *conf)
{
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x]);
  conf->posx = (map->hero->x + 1) * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x + 1]);
}

int			move_right(t_map *map,
				   SDL_Surface *screen, t_conf *conf)
{
  if (map->map[map->hero->y][map->hero->x + 1] == MONSTER)
    life(map, conf, screen);
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
	   && map->map[map->hero->y][map->hero->x + 1] != KEYCASE
	   && map->map[map->hero->y][map->hero->x + 1] != ENTERCASE
	   && (map->map[map->hero->y + 1][map->hero->x] == WALL ||
	       map->map[map->hero->y + 1][map->hero->x] == SCALE ||
	       map->map[map->hero->y + 1][map->hero->x] == KEYCASE)
	   && map->hero->x + 1 < map->size_column)
    {
      scale_case(map);
      map->hero->x += 1;
      map->map[map->hero->y][map->hero->x] = HERO_R;
    }
  move_right_end(map, screen, conf);
  return (EXIT_SUCCESS);
}

int			move_left(t_map *map,
				  SDL_Surface *screen, t_conf *conf)
{
  if (map->map[map->hero->y][map->hero->x - 1] == MONSTER)
    life(map, conf, screen);
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
	   && map->map[map->hero->y][map->hero->x - 1] != KEYCASE
	   && (map->map[map->hero->y + 1][map->hero->x] == WALL ||
	       map->map[map->hero->y + 1][map->hero->x] == KEYCASE ||
	       map->map[map->hero->y + 1][map->hero->x] == SCALE)
	   && map->hero->x - 1 >= 0)
    {
      scale_case(map);
      map->hero->x -= 1;
      map->map[map->hero->y][map->hero->x] = HERO_L;
    }
  move_left_end(map, screen, conf);
  return (EXIT_SUCCESS);
}
