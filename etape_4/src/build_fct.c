/*
** build_fct.c for build_fct.c in /home/manzan_m/project/c/rush/epikong/real
**
** Made by manzan_m
** Login   <manzan_m@epitech.net>
**
** Started on  Sat Mar  8 00:10:46 2014 manzan_m
** Last update Sun Mar  9 12:34:43 2014 Elliot Kersale
*/

#include		<stdlib.h>
#include		"epikong.h"

int			build_wall(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface		*img;

  if ((img = new_texture(PATHWALL)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			build_monster(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface		*img;

  if ((img = new_texture(PATHMONSTER)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			build_scale(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface		*img;

  if ((img = new_texture(PATHSCALE)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			build_entercase(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface		*img;

  if ((img = new_texture(PATHENTER)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			build_exitcase(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface		*img;

  if ((img = new_texture(PATHEXIT)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
