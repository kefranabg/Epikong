/*
** put_img.c for put_img.c in /home/manzan_m/project/c/rush/epikong/real
**
** Made by manzan_m
** Login   <manzan_m@epitech.net>
**
** Started on  Fri Mar  7 22:56:44 2014 manzan_m
** Last update Sat Mar  8 11:29:36 2014 abgral_f
*/

#include		<stdlib.h>
#include		"epikong.h"

SDL_Surface		*new_texture(char *path)
{
  SDL_Surface		*surface;

  if ((surface = SDL_LoadBMP(path)) == NULL)
    {
      error(BMP_ERR);
      return (NULL);
    }
  if (surface == NULL)
    {
      error(ERR_LOADBMP);
      return (NULL);
    }
  return (surface);
}

int			put_img_on_screen(SDL_Surface *img,
				  SDL_Surface *screen, t_conf *conf)
{
  SDL_Rect		img_conf;
  SDL_Rect		screen_conf;

  img_conf.w = SIZECUBE;
  img_conf.h = SIZECUBE;
  img_conf.x = 0;
  img_conf.y = 0;
  screen_conf.w = conf->winsize_w;
  screen_conf.h = conf->winsize_h;
  screen_conf.x = conf->posx;
  screen_conf.y = conf->posy;
  if ((SDL_BlitSurface(img, &img_conf, screen, &screen_conf)) == -1)
    return (error(BLIT_ERR));
  if ((SDL_Flip(screen)) == -1)
    return (error(FLIP_ERR));
  return (EXIT_SUCCESS);
}

int			loop_screen(t_conf *conf, char **map)
{
  int			bool;
  SDL_Event		e;
  SDL_Surface		*screen;

  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return (error(ERR_SDLINIT));
  bool = TRUE;
  if ((screen = SDL_SetVideoMode(conf->winsize_h,
				 conf->winsize_w, 32, SDL_SWSURFACE)) == NULL)
    return (error(VIDEO_ERR));
  if (start_display(conf, screen, map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
    while (bool != FALSE)
    {
      SDL_PollEvent(&e);
      if (e.type == SDL_KEYDOWN)
	bool = FALSE;
      if (screen == NULL)
	return (error(ERR_SETVIDEO));
    }
  return (EXIT_SUCCESS);
}
