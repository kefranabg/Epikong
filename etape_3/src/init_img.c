/*
** put_img.c for put_img.c in /home/manzan_m/project/c/rush/epikong/real
**
** Made by manzan_m
** Login   <manzan_m@epitech.net>
**
** Started on  Fri Mar  7 22:56:44 2014 manzan_m
** Last update Sun Mar  9 18:19:25 2014 Elliot Kersale
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		"epikong.h"

SDL_Surface		*new_texture(char *path)
{
  SDL_Surface		*surface;

  surface = NULL;
  if ((surface = SDL_LoadBMP(path)) == NULL)
    {
      error(BMP_ERR);
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

void			event_moov(t_conf *conf, t_map *map, int *check,
				   SDL_Surface *screen)
{
  SDL_Event             event;
  int			c;

  c = 0;
  SDL_EnableKeyRepeat(1000, 1000);
  while (*check && map->hero->is_alive != FALSE && key_and_door(map) == 1)
    {
      SDL_WaitEvent(&event);
      hero_fall(map, conf, screen);
      if (c == 4)
	{
	  move_monster(map, conf, screen, &map->newtime);
	  c = 0;
	}
      if (event.type == SDL_QUIT)
	*check = 0;
      if (event.type == SDL_KEYDOWN)
	{
	  c++;
	  moove(&event, conf, map, screen);
	  if (event.key.keysym.sym == SDLK_ESCAPE)
	    *check = 0;
	}
    }
}

int			loop_screen(t_conf *conf, t_map *map)
{
  SDL_Surface		*screen;
  int                   check;

  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return (error(ERR_SDLINIT));
  if ((screen = SDL_SetVideoMode(conf->winsize_h,
				 conf->winsize_w, 32, SDL_HWSURFACE
				 | SDL_DOUBLEBUF)) == NULL)
    return (error(VIDEO_ERR));
  if (start_display(conf, screen, map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  check = 1;
  map->newtime = SDL_GetTicks() + 100;
  event_moov(conf, map, &check, screen);
  return (EXIT_SUCCESS);
}
