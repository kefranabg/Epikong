/*
** run_epikong.c for run_epikong.c in /home/abgral_f/rendu/T2Rush1/etape_1/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Mar  7 20:47:34 2014 abgral_f
** Last update Sat Mar  8 23:10:45 2014 Elliot Kersale
*/

#include		<stdlib.h>
#include                <SDL/SDL.h>
#include		"epikong.h"

int			run_epikong()
{
  t_map			map;
  char			*path;

  if ((path = init_screen()) == NULL)
    return (EXIT_FAILURE);
  if (start_music() == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (start_parsing(path, &map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (get_monster(&map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (get_hero(&map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (parse_map(&map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
