/*
** build_fct2.c for build_fct2.c in /home/manzan_m/project/c/rush/epikong/real
**
** Made by manzan_m
** Login   <manzan_m@epitech.net>
**
** Started on  Sat Mar  8 00:32:22 2014 manzan_m
** Last update Sun Mar  9 16:22:44 2014 abgral_f
*/

#include		<stdlib.h>
#include		"epikong.h"

int			build_keycase(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface		*img;

  if ((img = new_texture(PATHKEY)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			build_hero(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface		*img;

  if ((img = new_texture(PATHHERO)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			build_hero_r(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface		*img;

  if ((img = new_texture(PATHHEROR)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			build_hero_l(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface		*img;

  if ((img = new_texture(PATHHEROL)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			build_hero_scale(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface		*img;

  if ((img = new_texture(PATHHERO2)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
