/*
** epikong.h for epikong.h in /home/abgral_f/rendu/T2Rush1/etape_1/include
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Mar  7 20:44:04 2014 abgral_f
** Last update Sun Mar  9 16:14:02 2014 abgral_f
*/

#ifndef			EPIKONG_H_
# define		EPIKONG_H_

/* INCLUDES */

#include		<stdio.h>
#include		<SDL/SDL.h>

/* DEFINES */

# define	WALL		'w'
# define	MONSTER		'm'
# define	SCALE		's'
# define	EXITCASE	'o'
# define	ENTERCASE	'i'
# define	KEYCASE		'k'
# define	EPIKONG		"Epikong"
# define	FOPEN_MOD	"r"
# define	PATHMONSTER	"img/monster.bmp"
# define	PATHSCALE	"img/scale.bmp"
# define	PATHEXIT	"img/exit.bmp"
# define	PATHENTER	"img/entrance.bmp"
# define	PATHKEY		"img/key.bmp"
# define	PATHHERO	"img/hero.bmp"
# define	PATHWALL	"img/wall.bmp"
# define	SIZECUBE	30
# define	TRUE		0
# define	FALSE		1



/* ERROR */

# define MAP_WALL	"epikong : Wrog map. It must be surround by wall\n"
# define ACCESS		"epikong : Can't access to this file\n"
# define EMPTY_MAP	"epikong : Map is empty\n"
# define ERR_HSIZE	"epikong : The height of the map is to damn high !\n"
# define ERR_WSIZE	"epikong : The weight of the map is to damn high !\n"
# define ERR_LOADBMP	"epikong : Error with SDL_LoadBMP() function.\n"
# define ERR_SDLINIT	"epikong : Error with SDL_Init() function.\n"
# define ERR_SETVIDEO	"epikong : Error with SDL_SetVideoMode() function.\n"
# define SDL_INIT	"epikong : Initialization error SDL\n"
# define VIDEO_ERROR	"epikong : Error on SDL_SetVideoMode\n"
# define USAGE		"epikong : \n\tUsage => ./epikong [MAP]\n"
# define OPEN_ERROR	"epikong : Error on fopen\n"
# define MAP_ERROR	"epikong : Lines must have the same size\n"
# define STRDUP_ERR	"epikong : Error on strdup\n"
# define MALLOC_ERR	"epikong : Error on malloc\n"
# define BLIT_ERR	"epikong : Error on SDL_BlitSurface\n"
# define FLIP_ERR	"epikong : Error on SDL_Flip\n"
# define BMP_ERR	"epikong : This BMP doesn't exist\n"
# define VIDEO_ERR	"epikong : Error on SDL_SetVideoMode\n"

/* STRUCTURES */

typedef struct	s_conf
{
  int		posx;
  int		posy;
  int		winsize_h;
  int		winsize_w;
}		t_conf;

typedef struct	s_map
{
  char		**map;
  int		size_line;
  int		size_column;
}		t_map;

typedef	struct	s_compare
{
  char		charac;
  int		(*fct)(t_conf *, SDL_Surface *);
}		t_compare;

/* PROTOTYPES */

int                     check_map(t_map *);
void                    init_get_line(size_t *, char **, int *, int *);
void                    set_map(t_map *, int *, int *);
SDL_Surface		*new_texture(char *);
int			put_img_on_screen(SDL_Surface *,
					  SDL_Surface *, t_conf *);
int			parse_map(struct s_map *);
int			loop_screen(t_conf *, char **);
int			build_keycase(t_conf *, SDL_Surface *);
int			build_wall(t_conf *, SDL_Surface *);
int			build_exitcase(t_conf *, SDL_Surface *);
int			build_entercase(t_conf *, SDL_Surface *);
int			build_scale(t_conf *, SDL_Surface *);
int			build_monster(t_conf *, SDL_Surface *);
int			find_texture(t_conf *, SDL_Surface *, char);
int			start_display(t_conf *, SDL_Surface *, char **);
int			build_keycase(t_conf *, SDL_Surface *);
int                     mall_map(FILE *, t_map *);
int                     get_map(FILE *, t_map *);
int			error(char *);
int			start_parsing(int, char **, t_map *);
int			run_epikong(int, char **);
int			main(int, char **);

#endif
