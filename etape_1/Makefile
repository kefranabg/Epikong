##
## Makefile for Makefile in /home/abgral_f/dev/my_script
## 
## Made by abgral_f
## Login   <abgral_f@epitech.net>
## 
## Started on  Sat Feb 22 23:01:39 2014 abgral_f
## Last update Sun Mar  9 13:25:38 2014 abgral_f
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
	  $(PATH2)check_map.c				\

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -W -Wall -Werror -Wextra -Wshadow -I$(PATH1) 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lSDLmain -lSDL 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
