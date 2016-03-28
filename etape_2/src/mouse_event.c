/*
** mouse_event.c for mouse_event.c in /home/abgral_f/rendu/T2Rush1/etape_2/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar  8 17:21:34 2014 abgral_f
** Last update Sat Mar  8 21:49:00 2014 abgral_f
*/

#include        <stdlib.h>
#include        "epikong.h"

char		*choose_level(int x, int y)
{
  if (x >= MINX && x <= MAXX)
    {
      if (y >= 165 && y <= 234)
        return (MAP1);
      if (y >= 266 && y <= 336)
        return (MAP2);
      if (y >= 367 && y <= 436)
        return (MAP3);
      if (y >= 467 && y <= 536)
        return (MAP4);
      if (y >= 570 && y <= 639)
        return (MAP5);
    }
  return (CHOOSE);
}

char		*mouse_event(SDL_Event e)
{
  if (e.type == SDL_MOUSEBUTTONDOWN)
    {
      if (e.button.button == SDL_BUTTON_LEFT)
        return (choose_level(e.button.x, e.button.y));
    }
  return (NULL);
}
