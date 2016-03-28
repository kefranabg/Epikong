/*
** game_over.c for game_over.c in /home/manzan_m/project/c/rush/epikong/etape_3/src
**
** Made by manzan_m
** Login   <manzan_m@epitech.net>
**
** Started on  Sun Mar  9 09:56:33 2014 manzan_m
** Last update Sun Mar  9 16:26:35 2014 manzan_m
*/

#include		<stdlib.h>
#include		"epikong.h"

int			case_game_over(t_map *map)
{
  if (map->hero->is_alive == FALSE)
    return (0);
  return (1);
}

char			*select_end(t_map *map)
{
  if (map->hero->is_alive == FALSE)
    return (PATHEND);
  return (PATHWIN);
}

int			end_screen(t_map *map, int i)
{
  int                   bool;
  SDL_Event             e;
  SDL_Surface           *screen;

  start_death_music(map);
  if (map->hero->is_alive == TRUE && i != 6)
    return (EXIT_SUCCESS);
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return (EXIT_FAILURE);
  bool = TRUE;
  if ((screen = SDL_SetVideoMode(800, 800, 32, SDL_SWSURFACE)) == NULL)
    return (EXIT_FAILURE);
  if (screen == NULL)
    return (EXIT_FAILURE);
  if (put_log_screen(screen, select_end(map)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while (bool != FALSE)
    {
      SDL_WaitEvent(&e);
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
        bool = FALSE;
    }
  return (EXIT_FAILURE);
}
