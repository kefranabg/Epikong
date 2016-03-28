/*
** run_epikong.c for run_epikong.c in /home/abgral_f/rendu/T2Rush1/etape_1/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Mar  7 20:47:34 2014 abgral_f
** Last update Sun Mar  9 16:29:35 2014 manzan_m
*/

#include		<stdlib.h>
#include                <SDL/SDL.h>
#include		"epikong.h"

int			run_epikong(int i)
{
  t_map			map;
  char			*path;

  if ((path = init_screen(i)) == NULL)
    return (EXIT_FAILURE);
  i = i + 1;
  if (start_music(&map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (start_parsing(path, &map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (get_monster(&map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (get_hero(&map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
    map.hero->win = FALSE;
  if (parse_map(&map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (end_screen(&map, i) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (i != 6 && map.hero->win == TRUE)
    run_epikong(i);
  end_screen(&map, i);
  return (EXIT_SUCCESS);
}
