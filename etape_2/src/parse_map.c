/*
** parse_map.c for parse_map.c in /home/manzan_m/project/c/rush/epikong/real
**
** Made by manzan_m
** Login   <manzan_m@epitech.net>
**
** Started on  Fri Mar  7 23:10:11 2014 manzan_m
** Last update Sat Mar  8 21:49:36 2014 abgral_f
*/

#include		<stdlib.h>
#include		"epikong.h"

int			put_log_screen(SDL_Surface *screen)
{
  SDL_Surface           *img;

  if ((img = SDL_LoadBMP(PATHLOG)) == NULL)
    return (error(ERR_LOADBMP));
  if (SDL_BlitSurface(img, NULL, screen, NULL) == -1)
    return (error(BLIT_ERR));
  if (SDL_Flip(screen) == -1)
    return (error(FLIP_ERR));
  return (EXIT_SUCCESS);
}

char			*init_screen()
{
  int                   bool;
  SDL_Event             e;
  SDL_Surface           *screen;
  char                  *path;

  path = NULL;
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return (NULL);
  bool = TRUE;
  if ((screen = SDL_SetVideoMode(800, 800, 32, SDL_SWSURFACE)) == NULL)
    return (NULL);
  if (screen == NULL)
    return (NULL);
  if (put_log_screen(screen) == EXIT_FAILURE)
    return (NULL);
  while (bool != FALSE)
    {
      SDL_PollEvent(&e);
      path = mouse_event(e);
      if (path != NULL && strcmp(path, CHOOSE) != 0)
        bool = FALSE;
    }
  return (path);
}

int		parse_map(t_map *map)
{
  t_conf	conf;

  conf.posx = 0;
  conf.posy = 0;
  conf.winsize_w = map->size_line * SIZECUBE;
  if (conf.winsize_w > 1900)
    return (error(ERR_WSIZE));
  conf.winsize_h = map->size_column * SIZECUBE;
  if (conf.winsize_h > 1000)
    return (error(ERR_HSIZE));
  if (loop_screen(&conf, map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
