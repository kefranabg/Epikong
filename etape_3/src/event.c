/*
** event.c for event in /home/kersal_e/Dropbox/rush1 (1)/derniere
** 
** Made by Elliot Kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Sun Mar  9 18:13:18 2014 Elliot Kersale
** Last update Sun Mar  9 18:20:20 2014 Elliot Kersale
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		"epikong.h"

static t_cmp_event        g_event[NB_MOOVE] =
  {
    {SDLK_LEFT, move_left},
    {SDLK_UP, move_up},
    {SDLK_DOWN, move_down},
    {SDLK_RIGHT, move_right},
    {SDLK_SPACE, move_space},
    {SDLK_e, move_space_right},
    {SDLK_a, move_space_left},
    {SDLK_t, take_key}
  };

void			moove(SDL_Event *event, t_conf *conf,
			      t_map *map, SDL_Surface *screen)
{
  int		i;

  i = 0;
  while (i != NB_MOOVE)
    {
      if (g_event[i].key == (*event).key.keysym.sym)
	g_event[i].fct(map, screen, conf);
      i++;
    }
}
