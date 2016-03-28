/*
** move_monster_ends.c for epikong in /home/kersal_e/Dropbox/rush1 (1)/derniere
** 
** Made by Elliot Kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Sun Mar  9 17:49:33 2014 Elliot Kersale
** Last update Sun Mar  9 17:53:11 2014 Elliot Kersale
*/

#include		"epikong.h"

void			move_monster_left_end_end(t_map *map, t_conf *conf,
						  SDL_Surface *screen,
						  t_monster **tmp)
{
  map->map[(*tmp)->y][(*tmp)->x] = SPACE;
  (*tmp)->x -= 1;
  map->map[(*tmp)->y][(*tmp)->x] = MONSTER;
  conf->posx = (*tmp)->x * SIZECUBE;
  conf->posy = (*tmp)->y * SIZECUBE;
  find_texture(conf, screen, map->map[(*tmp)->y][(*tmp)->x]);
  conf->posx = ((*tmp)->x + 1) * SIZECUBE;
  conf->posy = (*tmp)->y * SIZECUBE;
  find_texture(conf, screen, map->map[(*tmp)->y][(*tmp)->x + 1]);
}

int			move_monster_left_end(t_map *map, t_conf *conf,
					      SDL_Surface *screen,
					      t_monster **tmp)
{
  if ((*tmp)->x - 1 > 0 && map->map[(*tmp)->y][(*tmp)->x - 1] != WALL
      && map->map[(*tmp)->y][(*tmp)->x - 1] != MONSTER
      && map->map[(*tmp)->y][(*tmp)->x - 1] != EXITCASE
      && map->map[(*tmp)->y][(*tmp)->x - 1] != ENTERCASE
      && map->map[(*tmp)->y][(*tmp)->x - 1] != HERO
      && map->map[(*tmp)->y][(*tmp)->x - 1] != HERO_R
      && map->map[(*tmp)->y][(*tmp)->x - 1] != HERO_SCALE
      && map->map[(*tmp)->y][(*tmp)->x - 1] != HERO_L
      && map->map[(*tmp)->y][(*tmp)->x - 1] != KEYCASE
      && map->map[(*tmp)->y][(*tmp)->x - 1] != SCALE
      && (map->map[(*tmp)->y + 1][(*tmp)->x - 1] == WALL ||
	  map->map[(*tmp)->y + 1][(*tmp)->x - 1] == SCALE)
      && (*tmp)->check == 0)
    {
      move_monster_left_end_end(map, conf, screen, tmp);
      return (0);
    }
  return (1);
}

void			move_monster_right_end_end(t_map *map, t_conf *conf,
						   SDL_Surface *screen,
						   t_monster **tmp)
{
  map->map[(*tmp)->y][(*tmp)->x] = SPACE;
  (*tmp)->x += 1;
  map->map[(*tmp)->y][(*tmp)->x] = MONSTER;
  conf->posx = (*tmp)->x * SIZECUBE;
  conf->posy = (*tmp)->y * SIZECUBE;
  find_texture(conf, screen, map->map[(*tmp)->y][(*tmp)->x]);
  conf->posx = ((*tmp)->x - 1) * SIZECUBE;
  conf->posy = (*tmp)->y * SIZECUBE;
  find_texture(conf, screen, map->map[(*tmp)->y][(*tmp)->x - 1]);
}

int			move_monster_right_end(t_map *map, t_conf *conf,
					      SDL_Surface *screen,
					      t_monster **tmp)
{
  if (map->map[(*tmp)->y][(*tmp)->x + 1] != WALL
      && map->map[(*tmp)->y][(*tmp)->x + 1] != MONSTER
      && map->map[(*tmp)->y][(*tmp)->x + 1] != EXITCASE
      && map->map[(*tmp)->y][(*tmp)->x + 1] != HERO
      && map->map[(*tmp)->y][(*tmp)->x + 1] != HERO_R
      && map->map[(*tmp)->y][(*tmp)->x + 1] != HERO_L
      && map->map[(*tmp)->y][(*tmp)->x + 1] != HERO_SCALE
      && map->map[(*tmp)->y][(*tmp)->x + 1] != KEYCASE
      && map->map[(*tmp)->y][(*tmp)->x + 1] != ENTERCASE
      && map->map[(*tmp)->y][(*tmp)->x + 1] != SCALE
      && (map->map[(*tmp)->y + 1][(*tmp)->x + 1] == WALL ||
	  map->map[(*tmp)->y + 1][(*tmp)->x + 1] == SCALE)
      && (*tmp)->x + 1 < map->size_column && (*tmp)->check == 1)
    {
      move_monster_right_end_end(map, conf, screen, tmp);
      return (0);
    }
  return (1);
}
