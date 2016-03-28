/*
** build_fct3.c for build_fct3.c in /home/abgral_f/rendu/T2Rush1/etape_2/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Mar  9 16:17:00 2014 abgral_f
** Last update Sun Mar  9 16:21:12 2014 abgral_f
*/

#include		<stdlib.h>
#include		"epikong.h"

int                     build_black(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface           *img;

  if ((img = new_texture(BLACK)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
