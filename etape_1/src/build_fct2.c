/*
** build_fct2.c for build_fct2.c in /home/manzan_m/project/c/rush/epikong/real
**
** Made by manzan_m
** Login   <manzan_m@epitech.net>
**
** Started on  Sat Mar  8 00:32:22 2014 manzan_m
** Last update Sat Mar  8 11:21:23 2014 abgral_f
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
