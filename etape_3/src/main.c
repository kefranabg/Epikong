/*
** main.c for main.c in /home/abgral_f/rendu/dev_rush/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Mar  7 18:34:21 2014 abgral_f
** Last update Sun Mar  9 13:21:20 2014 manzan_m
*/

#include		<stdlib.h>
#include		"epikong.h"

int			main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  if (run_epikong(1) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
