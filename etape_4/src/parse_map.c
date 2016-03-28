/*
** parse_map.c for parse_map.c in /home/manzan_m/project/c/rush/epikong/real
**
** Made by manzan_m
** Login   <manzan_m@epitech.net>
**
** Started on  Fri Mar  7 23:10:11 2014 manzan_m
** Last update Sun Mar  9 21:33:30 2014 manzan_m
*/

#include		<stdlib.h>
#include		"epikong.h"

int			put_log_screen(SDL_Surface *screen, char *str)
{
  SDL_Surface           *img;

  if ((img = SDL_LoadBMP(str)) == NULL)
    return (error(ERR_LOADBMP));
  if (SDL_BlitSurface(img, NULL, screen, NULL) == -1)
    return (error(BLIT_ERR));
  if (SDL_Flip(screen) == -1)
    return (error(FLIP_ERR));
  return (EXIT_SUCCESS);
}

char   			*select_level(int i)
{
  if (i == 1)
    return (MAP1);
  if (i == 2)
    return (MAP2);
  if (i == 3)
    return (MAP3);
  if (i == 4)
    return (MAP4);
  if (i == 5)
    return (MAP5);
  return (NULL);
}

int			set_values(SDL_Surface **screen)
{
  if ((*screen = SDL_SetVideoMode(800, 800, 32, SDL_SWSURFACE)) == NULL)
    return (EXIT_FAILURE);
  if (*screen == NULL)
    return (EXIT_FAILURE);
  if (put_log_screen(*screen, PATHLOG) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

char			*init_screen(int i)
{
  int                   bool;
  SDL_Event             e;
  SDL_Surface           *screen;
  char                  *path;

  path = select_level(i);
  if (i == 1)
    {
      start_intro();
      if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	return (NULL);
      bool = TRUE;
      if (set_values(&screen) == EXIT_FAILURE)
	return (NULL);
      while (bool != FALSE)
	{
	  SDL_PollEvent(&e);
	  if (e.type == SDL_KEYDOWN)
	    bool = FALSE;
	}
    }
  Mix_CloseAudio();
  return (path);
}

int		parse_map(t_map *map)
{
  t_conf	conf;

  conf.posx = 0;
  conf.posy = 0;
  map->hero->is_alive = TRUE;
  conf.winsize_w = map->size_line * SIZECUBE;
  if (conf.winsize_w > 1000)
    return (error(ERR_WSIZE));
  conf.winsize_h = map->size_column * SIZECUBE;
  if (conf.winsize_h > 1900)
    return (error(ERR_HSIZE));
  if (loop_screen(&conf, map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
