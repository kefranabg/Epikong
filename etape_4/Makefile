##
## Makefile for Makefile in /home/abgral_f/dev/my_script
## 
## Made by abgral_f
## Login   <abgral_f@epitech.net>
## 
## Started on  Sat Feb 22 23:01:39 2014 abgral_f
## Last update Sun Mar  9 20:57:45 2014 Elliot Kersale
##

CC	= gcc

RM	= rm -f

NAME	= epikong

PATH1	= include/

PATH2	= src/

SRCS	= $(PATH2)main.c				\
	  $(PATH2)start_parsing.c			\
	  $(PATH2)run_epikong.c				\
	  $(PATH2)error.c				\
	  $(PATH2)init_img.c				\
	  $(PATH2)parse_map.c				\
	  $(PATH2)build_fct.c				\
	  $(PATH2)build_fct2.c				\
	  $(PATH2)start_display.c			\
	  $(PATH2)get_monster.c				\
	  $(PATH2)get_hero.c				\
	  $(PATH2)fire.c				\
	  $(PATH2)move_hero.c				\
	  $(PATH2)scale_case.c				\
	  $(PATH2)mouse_event.c				\
	  $(PATH2)move_hero_jump.c			\
	  $(PATH2)hero_fall.c	 			\
	  $(PATH2)move_monster.c 			\
	  $(PATH2)start_music.c				\
	  $(PATH2)life.c				\
	  $(PATH2)build_fct3.c				\
	  $(PATH2)game_over.c				\
	  $(PATH2)move_hero_end.c			\
	  $(PATH2)take_key.c				\
	  $(PATH2)move_monster_ends.c			\
	  $(PATH2)event.c				\
	  $(PATH2)build_fct4.c				\
	  $(PATH2)take_key2.c				\
	  $(PATH2)move_end.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -W -Wall -Werror -Wextra -Wshadow -I$(PATH1) 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lSDLmain -lSDL -lSDL_mixer

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
