/*
** build_fct3.c for epikong in /home/kersal_e/Dropbox/rush1 (1)/lastlast/etape_3/src
** 
** Made by Elliot Kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Sun Mar  9 13:02:09 2014 Elliot Kersale
** Last update Sun Mar  9 13:02:53 2014 Elliot Kersale
*/

#include		"epikong.h"

int			build_hero_scale(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface		*img;

  if ((img = new_texture(PATHHERO2)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			build_black(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface		*img;

  if ((img = new_texture(BLACK)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			build_life(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface		*img;

  if ((img = new_texture(PATHLIFE)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
