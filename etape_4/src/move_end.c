/*
** move_end.c for epikong in /home/kersal_e/Dropbox/rush1 (1)/etape_4
** 
** Made by Elliot Kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Sun Mar  9 20:55:18 2014 Elliot Kersale
** Last update Sun Mar  9 21:04:29 2014 Elliot Kersale
*/

#include		"epikong.h"

void			move_left2(t_map *map)
{
  if (map->map[map->hero->y][map->hero->x - 1] != KEYCASE
      && (map->map[map->hero->y + 1][map->hero->x] == WALL ||
	  map->map[map->hero->y + 1][map->hero->x] == KEYCASE ||
	  map->map[map->hero->y + 1][map->hero->x] == EXTRALIFE ||
	  map->map[map->hero->y + 1][map->hero->x] == GUN ||
	  map->map[map->hero->y + 1][map->hero->x] == SCALE)
      && map->hero->x - 1 >= 0)
    {
      scale_case(map);
      map->hero->x -= 1;
      map->map[map->hero->y][map->hero->x] = HERO_L;
    }
}

void			move_right2(t_map *map)
{
  if (map->map[map->hero->y][map->hero->x + 1] != ENTERCASE
      && (map->map[map->hero->y + 1][map->hero->x] == WALL ||
	  map->map[map->hero->y + 1][map->hero->x] == SCALE ||
	  map->map[map->hero->y + 1][map->hero->x] == GUN ||
	  map->map[map->hero->y + 1][map->hero->x] == EXTRALIFE ||
	  map->map[map->hero->y + 1][map->hero->x] == KEYCASE)
      && map->hero->x + 1 < map->size_column)
    {
      scale_case(map);
      map->hero->x += 1;
      map->map[map->hero->y][map->hero->x] = HERO_R;
    }
}

void			move_space2(t_map *map, t_conf *conf,
				    SDL_Surface *screen)
{
  if (map->map[map->hero->y - 2][map->hero->x] != EXTRALIFE
      && map->map[map->hero->y - 2][map->hero->x] != WALL
      && map->map[map->hero->y - 2][map->hero->x] != GUN
      && map->map[map->hero->y - 2][map->hero->x] != EXITCASE
      && map->map[map->hero->y - 2][map->hero->x] != ENTERCASE
      && map->map[map->hero->y - 2][map->hero->x] != KEYCASE
      && map->map[map->hero->y - 2][map->hero->x] != ENTERCASE
      && map->map[map->hero->y - 2][map->hero->x] != SCALE
      && map->hero->y - 2 > 0)
    move_space_two(map, screen, conf);
}

void			move_up2(t_map *map)
{
  if (map->map[map->hero->y - 1][map->hero->x] != ENTERCASE
      && map->map[map->hero->y - 1][map->hero->x] != KEYCASE
      && map->map[map->hero->y][map->hero->x] == HERO_SCALE
      && map->hero->y - 1 >= 0)
    {
      scale_case(map);
      map->hero->y -= 1;
      map->map[map->hero->y][map->hero->x] = HERO;
    }
}
