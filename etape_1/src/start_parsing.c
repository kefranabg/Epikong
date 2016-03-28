/*
** start_parsing.c for start_parsing.c in /home/abgral_f/rendu/T2Rush1/etape_1/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Mar  7 20:49:18 2014 abgral_f
** Last update Sat Mar  8 17:18:05 2014 abgral_f
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<stdio.h>
#include		"epikong.h"

int			mall_map(FILE *fd, t_map *map)
{
  int			count;
  char			*line;
  size_t		len;

  count = 0;
  line = NULL;
  while (getline(&line, &len, fd) != -1)
    count++;
  if ((map->map = malloc(sizeof (*(map->map)) * (count + 1))) == NULL)
    return (error(MALLOC_ERR));
  fseek(fd, 0, SEEK_SET);
  return (EXIT_SUCCESS);
}

void			init_get_line(size_t *len, char **line,
				      int *count, int *cmp)
{
  *line = NULL;
  *count = 0;
  *len = 0;
  *cmp = -1;
}

void			set_map(t_map *map, int *count, int *cmp)
{
  map->size_line = *count;
  map->map[*count] = NULL;
  map->size_column = *cmp - 1;
}

int			get_map(FILE *fd, t_map *map)
{
  char			*line;
  size_t		len;
  ssize_t		read;
  int			count;
  int			cmp;

  init_get_line(&len, &line, &count, &cmp);
  if (mall_map(fd, map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while ((read = getline(&line, &len, fd)) != -1)
    {
      if (count != 0)
	{
	  if (cmp != read)
	    return (error(MAP_ERROR));
	}
      cmp = read;
      if ((map->map[count] = strdup(line)) == NULL)
	return (error(STRDUP_ERR));
      count++;
    }
  if (cmp == -1)
    return (error(EMPTY_MAP));
  set_map(map, &count, &cmp);
  return (EXIT_SUCCESS);
}

int			start_parsing(int argc, char **argv, t_map *map)
{
  FILE			*fd;

  if (argc != 2)
    return (error(USAGE));
  if (access(argv[1], R_OK) == -1)
    return (error(ACCESS));
  if ((fd = fopen(argv[1], FOPEN_MOD)) == NULL)
    return (error(OPEN_ERROR));
  if (get_map(fd, map) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
