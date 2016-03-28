/*
** error.c for error.c in /home/abgral_f/rendu/T2Rush1/etape_1/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Mar  7 20:53:46 2014 abgral_f
** Last update Sat Mar  8 10:46:51 2014 abgral_f
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		"epikong.h"

int			error(char *str)
{
  fprintf(stderr, "%s", str);
  return (EXIT_FAILURE);
}
