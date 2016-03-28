/*
** build_fct4.c for build_fct4.c in /home/abgral_f/Dropbox/rush1 (1)/etape_4/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sun Mar  9 20:19:10 2014 abgral_f
** Last update Sun Mar  9 20:19:27 2014 abgral_f
*/

#include		<stdlib.h>
#include		"epikong.h"

int                     build_weapon_left(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface           *img;

  if ((img = new_texture(PATHWEAPONL)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int                     build_weapon_right(t_conf *conf, SDL_Surface *screen)
{
  SDL_Surface           *img;

  if ((img = new_texture(PATHWEAPONR)) == NULL)
    return (EXIT_FAILURE);
  if (put_img_on_screen(img, screen, conf) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
