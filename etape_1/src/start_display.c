/*
** start_display.c for start_display.c in /home/manzan_m/project/c/rush/epikong/real
**
** Made by manzan_m
** Login   <manzan_m@epitech.net>
**
** Started on  Fri Mar  7 23:17:23 2014 manzan_m
** Last update Sun Mar  9 12:41:46 2014 Elliot Kersale
*/

#include		<stdlib.h>
#include		"epikong.h"

static t_compare	g_compare[6] =
  {
    {WALL, build_wall},
    {MONSTER, build_monster},
    {SCALE, build_scale},
    {ENTERCASE, build_entercase},
    {EXITCASE, build_exitcase},
    {KEYCASE, build_keycase}
  };

int			find_texture(t_conf *conf,
				     SDL_Surface *screen, char to_cmp)
{
  int			k;

  k = 0;
  while (k != 6)
    {
      if (g_compare[k].charac == to_cmp)
	{
	  if (g_compare[k].fct(conf, screen) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      k++;
    }
  return (EXIT_SUCCESS);
}

int			start_display(t_conf *conf,
				      SDL_Surface *screen, char **map)
{
  int			i;
  int			j;

  i = 0;
  j = 0;
  while (map[i] != NULL)
    {
      conf->posx = 0;
      while (map[i][j] != '\0')
	{
	  if (find_texture(conf, screen, map[i][j]) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  conf->posx += SIZECUBE;
	  j++;
	}
      j = 0;
      i++;
      conf->posy += SIZECUBE;
    }
  return (EXIT_SUCCESS);
}
