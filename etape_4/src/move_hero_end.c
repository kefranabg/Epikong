/*
** move_hero_end.c for epikong in /home/kersal_e/Dropbox/rush1 (1)/lastlast/etape_3/src
**
** Made by Elliot Kersale
** Login   <kersal_e@epitech.net>
**
** Started on  Sun Mar  9 13:09:02 2014 Elliot Kersale
** Last update Sun Mar  9 20:57:27 2014 Elliot Kersale
*/

#include		"epikong.h"

void			move_right_end(t_map *map, SDL_Surface *screen,
				       t_conf *conf)
{
  conf->posx = (map->hero->x - 1) * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x - 1]);
  if (map->hero->gun == 1)
    {
      conf->posx = map->hero->x * SIZECUBE;
      conf->posy = map->hero->y * SIZECUBE;
      build_weapon_right(conf, screen);
      return ;
    }
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x]);
}

void			move_left_end(t_map *map, SDL_Surface *screen,
				      t_conf *conf)
{
  conf->posx = (map->hero->x + 1) * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x + 1]);
  if (map->hero->gun == 1)
    {
      conf->posx = map->hero->x * SIZECUBE;
      conf->posy = map->hero->y * SIZECUBE;
      build_weapon_left(conf, screen);
      return ;
    }
  conf->posx = map->hero->x * SIZECUBE;
  conf->posy = map->hero->y * SIZECUBE;
  find_texture(conf, screen, map->map[map->hero->y][map->hero->x]);
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
	   && map->map[map->hero->y][map->hero->x + 1] != GUN
	   && map->map[map->hero->y][map->hero->x + 1] != KEYCASE
	   && map->map[map->hero->y][map->hero->x + 1] != EXTRALIFE)
    move_right2(map);
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
	   && map->map[map->hero->y][map->hero->x - 1] != GUN
	   && map->map[map->hero->y][map->hero->x - 1] != EXITCASE
	   && map->map[map->hero->y][map->hero->x - 1] != ENTERCASE
	   && map->map[map->hero->y][map->hero->x - 1] != EXTRALIFE)
    move_left2(map);
  move_left_end(map, screen, conf);
  return (EXIT_SUCCESS);
}
