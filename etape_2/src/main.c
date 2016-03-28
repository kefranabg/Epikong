/*
** main.c for main.c in /home/abgral_f/rendu/dev_rush/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Mar  7 18:34:21 2014 abgral_f
** Last update Sat Mar  8 12:20:03 2014 abgral_f
*/

#include		<stdlib.h>
#include		"epikong.h"

int			main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  if (run_epikong() == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
