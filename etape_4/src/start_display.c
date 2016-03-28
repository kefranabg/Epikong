/*
** start_display.c for start_display.c in /home/manzan_m/project/c/rush/epikong/real
**
** Made by manzan_m
** Login   <manzan_m@epitech.net>
**
** Started on  Fri Mar  7 23:17:23 2014 manzan_m
** Last update Sun Mar  9 19:40:25 2014 manzan_m
*/

#include		<stdlib.h>
#include		"epikong.h"

static t_compare	g_compare[NB_OBJ] =
  {
    {WALL, build_wall},
    {MONSTER, build_monster},
    {SCALE, build_scale},
    {ENTERCASE, build_entercase},
    {EXITCASE, build_exitcase},
    {KEYCASE, build_keycase},
    {HERO, build_hero},
    {HERO_SCALE, build_hero_scale},
    {HERO_R, build_hero_r},
    {HERO_L, build_hero_l},
    {LIFE, build_life},
    {EXTRALIFE, build_xlife},
    {GUN, build_gun}
  };

int			find_texture(t_conf *conf,
				     SDL_Surface *screen, char to_cmp)
{
  int			k;

  k = 0;
  while (k != NB_OBJ)
    {
      if (g_compare[k].charac == to_cmp)
	{
	  if (g_compare[k].fct(conf, screen) == EXIT_FAILURE)
	      return (EXIT_FAILURE);
	  return (EXIT_SUCCESS);
	}
      k++;
    }
  if (k == NB_OBJ)
    {
      if (build_black(conf, screen) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			start_display(t_conf *conf,
				      SDL_Surface *screen, t_map *map)
{
  int			i;
  int			j;

  i = 0;
  conf->posy = 0;
  while (map->map[i] != NULL)
    {
      j = 0;
      conf->posx = 0;
      while (map->map[i][j] != '\0')
	{
	  if (find_texture(conf, screen, map->map[i][j]) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  conf->posx += SIZECUBE;
	  j++;
	}
      i++;
      conf->posy += SIZECUBE;
    }
  return (EXIT_SUCCESS);
}
