/*
** run_epikong.c for run_epikong.c in /home/abgral_f/rendu/T2Rush1/etape_1/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Mar  7 20:47:34 2014 abgral_f
** Last update Sun Mar  9 13:25:43 2014 abgral_f
*/

#include		<stdlib.h>
#include                <SDL/SDL.h>
#include		"epikong.h"

int			run_epikong(int argc, char **argv)
{
  t_map			map;

  if (start_parsing(argc, argv, &map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (check_map(&map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (parse_map(&map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
