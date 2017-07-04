##
## Makefile for Makefile in /home/walter_h/wireframe
##
## Made by Hugo WALTER
## Login   <walter_h@epitech.net>
##
## Started on  Fri Nov 25 10:55:04 2016 Hugo WALTER
## Last update Sun Jan 15 18:51:42 2017 Hugo WALTER
##

NAME    =       wolf3d

SRC     =	wolf3d.c			\
		fctraycast.c			\
		src/move_forward.c		\
		src/my_put_pixel.c		\
		src/raycast.c			\
		my_draw_linewolf.c		\
		my_abs.c			\
		my_strlen.c			\
		collision.c			\
		window.c			\
		move.c				\
		draw.c				\
		crossandcontrol.c

OBJ     =       $(SRC:.c=.o)

CC      =       gcc

CFLAGS  =       -I./include

LDFLAGS =       -W -Wall -Werror -lc_graph_prog -lm -g

RM      =       rm -rf

all:    $(NAME)

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

dbg: CFLAGS += -g
dbg: re
