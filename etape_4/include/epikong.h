/*
** epikong.h for epikong.h in /home/abgral_f/rendu/T2Rush1/etape_1/include
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Mar  7 20:44:04 2014 abgral_f
** Last update Sun Mar  9 21:18:55 2014 Elliot Kersale
*/

#ifndef			_EPIKONG_H__
# define		_EPIKONG_H__
/*
** INCLUDES
*/
#include		<stdio.h>
#include		<SDL/SDL.h>
#include		<SDL/SDL_mixer.h>
/*
** DEFINES
*/
# define	NB_MOOVE	11
# define	CHOOSE		"NOTCHOOSE"
# define	MAP1            "map/map_1"
# define	MAP2            "map/map_2"
# define	MAP3            "map/map_3"
# define	MAP4            "map/map_4"
# define	MAP5            "map/map_5"
# define	MINX	       	468
# define	MAXX   		750
# define	NB_OBJ 		13
# define	WALL		'w'
# define	EXTRALIFE	'l'
# define	MONSTER		'm'
# define	SCALE		's'
# define	EXITCASE	'o'
# define	GUN		'g'
# define	ENTERCASE	'i'
# define	KEYCASE		'k'
# define	HERO		'h'
# define	HERO_R		'r'
# define	HERO_L		'q'
# define	HERO_SCALE	'-'
# define	LIFE		'v'
# define	SPACE		' '
# define	EPIKONG       	"Epikong"
# define	FOPEN_MOD	"r"
# define	PATHXLIFE	"img/xlife.bmp"
# define	PATHWIN		"img/winner.bmp"
# define	PATHMONSTER	"img/monster.bmp"
# define	PATHSCALE	"img/scale.bmp"
# define	PATHGUN		"img/gun.bmp"
# define	PATHEXIT	"img/exit.bmp"
# define	PATHENTER	"img/entrance.bmp"
# define	PATHKEY		"img/key.bmp"
# define	PATHWALL	"img/wall.bmp"
# define	PATHHERO	"img/hero1.bmp"
# define	PATHEND		"img/end.bmp"
# define	PATHWEAPONR     "img/gun_right.bmp"
# define	PATHWEAPONL     "img/gun_left.bmp"
# define	PATHHEROR	"img/heroright.bmp"
# define	PATHHEROL	"img/heroleft.bmp"
# define	PATHLIFE	"img/life.bmp"
# define	PATHHERO2	"img/hero_scale.bmp"
# define	PATHLOG         "img/log.bmp"
# define	BLACK		"img/noir.bmp"
# define	SLIFE		"music/life.wav"
# define	JUMP		"music/jump.wav"
# define	AMBIANCE	"music/music.wav"
# define	GAME_OVER	"music/gameover.wav"
# define	INTRO_MUSIC	"music/intro.wav"
# define	SKEY		"music/key.wav"
# define	SDOOR		"music/doorsound.wav"
# define	SGUN		"music/take_gun.wav"
# define	SDIE		"music/monster_scream.wav"
# define	S_FIRE		"music/gun.wav"
# define	SXLIFE		"music/xlife.wav"
# define	SIZECUBE	30
# define	TRUE		0
# define	FALSE		1
/*
** ERROR
*/
# define	HERO_ERR        "epikong : The map must contain a Hero\n"
# define	ACCESS		"epikong : Can't access to this file\n"
# define	EMPTY_MAP	"epikong : Map is empty\n"
# define	ERR_HSIZE	"epikong : The height of the map is to damn high !\n"
# define	ERR_WSIZE	"epikong : The weight of the map is to damn high !\n"
# define	ERR_LOADBMP	"epikong : Error with SDL_LoadBMP function.\n"
# define	ERR_SDLINIT	"epikong : Error with SDL_Init function.\n"
# define	ERR_SETVIDEO	"epikong : Error with SDL_SetVideoMode function.\n"
# define	SDL_INIT	"epikong : Initialization error SDL\n"
# define	VIDEO_ERROR	"epikong : Error on SDL_SetVideoMode\n"
# define	USAGE		"epikong : \n\tUsage => ./epikong [MAP]\n"
# define	OPEN_ERROR	"epikong : Error on fopen\n"
# define	MAP_ERROR	"epikong : Lines must have the same size\n"
# define	STRDUP_ERR	"epikong : Error on strdup\n"
# define	MALLOC_ERR	"epikong : Error on malloc\n"
# define	BLIT_ERR	"epikong : Error on SDL_BlitSurface\n"
# define	FLIP_ERR	"epikong : Error on SDL_Flip\n"
# define	BMP_ERR		"epikong : This BMP doesn't exist\n"
# define	VIDEO_ERR	"epikong : Error on SDL_SetVideoMode\n"
/*
** STRUCTURES
*/
typedef struct		s_hero
{
  int			gun;
  char			key;
  int			win;
  int			is_alive;
  int                   life;
  char			direc;
  int			x;
  int			y;
}			t_hero;

typedef struct		s_monster
{
  int			life;
  int			x;
  int			y;
  int			check;
  struct s_monster	*next;
}			t_monster;

typedef struct		s_conf
{
  int			posx;
  int			posy;
  int			winsize_h;
  int			winsize_w;
}			t_conf;

typedef struct		s_map
{
  int			x;
  int			y;
  char			**map;
  int			size_line;
  int			size_column;
  t_monster		*first;
  t_hero		*hero;
  int			newtime;
  Mix_Music		*music;
  Mix_Chunk		*sound_jump;
  Mix_Chunk		*sound_life;
  Mix_Chunk		*sound_xlife;
  Mix_Chunk		*sound_key;
  Mix_Chunk		*sound_gun;
  Mix_Chunk		*sound_fire;
  Mix_Chunk		*sound_die;
  Mix_Chunk		*sound_door;
}			t_map;

typedef	struct		s_compare
{
  char			charac;
  int			(*fct)(t_conf *, SDL_Surface *);
}			t_compare;

typedef	struct		s_cmp_event
{
  unsigned int		key;
  int			(*fct)(t_map *, SDL_Surface *, t_conf *);
}			t_cmp_event;
/*
** PROTOTYPES
*/
int                     key_and_door(t_map *);
int			take_key(t_map *, SDL_Surface *, t_conf *);
void			take_key_end(t_map *, SDL_Surface *, t_conf *);
void                    life(t_map *, t_conf *, SDL_Surface *);
int                     fall_exp(t_map *, int *, int *);
int                     build_hero_r(t_conf *, SDL_Surface *);
int                     build_life(t_conf *, SDL_Surface *);
int                     build_hero_l(t_conf *, SDL_Surface *);
void                    event_moov(t_conf *, t_map *, int *, SDL_Surface *);
void			moove(SDL_Event *, t_conf *, t_map *, SDL_Surface *);
void                    move_monster_right(t_map *, t_conf *,
					   SDL_Surface *, t_monster **);
void                    move_monster_left(t_map *, t_conf *,
					  SDL_Surface *, t_monster **);
int			move_monster_right_end(t_map *, t_conf *, SDL_Surface *,
					       t_monster **);
int			move_monster_left_end(t_map *, t_conf *, SDL_Surface *,
					      t_monster **);
void			move_monster_right_end_end(t_map *, t_conf *,
						   SDL_Surface *,
						   t_monster **);
void			move_monster_left_end_end(t_map *, t_conf *,
						   SDL_Surface *,
						   t_monster **);
void                    move_monster(t_map *, t_conf *, SDL_Surface *, int *);
void                    hero_fall(t_map *, t_conf *, SDL_Surface *);
void			hero_fall_end(t_map *, int *, int *, int *);
void			hero_fall_end_end(t_map *, t_conf *,
					  SDL_Surface *, int *);
void                    move_space_two(t_map *, SDL_Surface *, t_conf *);
void                    move_space_one(t_map *, SDL_Surface *, t_conf *);
void                    move_space_else(t_map *, SDL_Surface *, t_conf *);
int                     build_black(t_conf *, SDL_Surface *);
void                    scale_case(t_map *);
int                     build_hero_scale(t_conf *, SDL_Surface *);
int                     move_left(t_map *, SDL_Surface *, t_conf *);
int                     move_up(t_map *, SDL_Surface *, t_conf *);
int                     move_down(t_map *, SDL_Surface *, t_conf *);
int                     move_right(t_map *, SDL_Surface *, t_conf *);
void			move_right_end(t_map *, SDL_Surface *, t_conf *);
void			move_left_end(t_map *, SDL_Surface *, t_conf *);
int                     move_space(t_map *, SDL_Surface *, t_conf *);
int                     move_space_right(t_map *, SDL_Surface *, t_conf *);
int                     move_space_left(t_map *, SDL_Surface *, t_conf *);
int                     get_hero(t_map *);
int                     add_monster(t_map *, int, int);
int                     get_monster(t_map *);
void                    init_get_line(size_t *, char **, int *, int *);
void                    set_map(t_map *, int *, int *);
SDL_Surface		*new_texture(char *);
int			put_img_on_screen(SDL_Surface *,
					  SDL_Surface *, t_conf *);
int			parse_map(struct s_map *);
int			loop_screen(t_conf *, t_map *);
int			build_hero(t_conf *, SDL_Surface *);
int			build_keycase(t_conf *, SDL_Surface *);
int			build_wall(t_conf *, SDL_Surface *);
int			build_exitcase(t_conf *, SDL_Surface *);
int			build_entercase(t_conf *, SDL_Surface *);
int			build_scale(t_conf *, SDL_Surface *);
int			build_monster(t_conf *, SDL_Surface *);
int			find_texture(t_conf *, SDL_Surface *, char);
int			start_display(t_conf *, SDL_Surface *, t_map *);
int			build_keycase(t_conf *, SDL_Surface *);
int                     mall_map(FILE *, t_map *);
int                     get_map(FILE *, t_map *);
int			error(char *);
int			start_parsing(char *, t_map *);
int			run_epikong(int);
int			main(int, char **);
char                    *mouse_event(SDL_Event);
char                    *choose_level(int, int);
char                    *init_screen(int);
int			set_values(SDL_Surface **);
int                     put_log_screen(SDL_Surface *, char *);
int			start_music(t_map *);
void             	start_intro();
void			start_death_music(t_map *);
void			do_effects(Mix_Chunk *);
int			case_game_over(t_map *);
char			*select_end(t_map *);
int			end_screen(t_map *, int);
int			build_xlife(t_conf *, SDL_Surface *);
int			build_gun(t_conf *, SDL_Surface *);
void			take_life_end(t_map *, SDL_Surface *, t_conf *);
void			take_gun_end(t_map *, SDL_Surface *, t_conf *);
int			take_life(t_map *, SDL_Surface *, t_conf *);
void			add_life(t_map *, t_conf *, SDL_Surface *);
int			take_gun(t_map *, SDL_Surface *, t_conf *);
void			add_gun(t_map *, t_conf *, SDL_Surface *);
int			build_weapon_right(t_conf *, SDL_Surface *);
int			build_weapon_left(t_conf *, SDL_Surface *);
int			delete_monster(t_monster *, t_map *);
int			fire(t_map *, SDL_Surface *, t_conf *);
void                    key_depop(t_map *, SDL_Surface *,
				  t_conf *);
void			move_right2(t_map *);
void			move_left2(t_map *);
void			move_up2(t_map *);
void			move_space2(t_map *, t_conf *, SDL_Surface *);
/*
**
*/
#endif
//EOF _EPIKONG_H__
