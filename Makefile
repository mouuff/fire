##
## Makefile for fire in /home/alies/rendu/gfx_incendie
## 
## Made by Arnaud Alies
## Login   <alies_a@epitech.net>
## 
## Started on  Fri Dec  4 21:57:46 2015 Arnaud Alies
## Last update Sun Dec  6 19:02:49 2015 Arnaud Alies
##

NAME    =       fire

CC	=	gcc

INC	=	./include/

CFLAGS	=	-W -Wall -Werror -ansi -pedantic \
		-I/home/${USER}/.froot/include \
		-L/home/${USER}/.froot/lib \
		-llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm \
		-I$(INC)

SRC	=	./src/

GRID	=	./src/grid/

CORE	=	./src/core/

SRCS	=	$(SRC)main.c \
		$(CORE)tekpixel.c \
		$(CORE)pixfill.c \
		$(CORE)pal.c \
		$(GRID)grid_init.c \
		$(GRID)grid_pix.c \
		$(GRID)do_stuff.c \
		$(GRID)get_moy.c \
		$(GRID)mouse_to_grid.c \
		$(GRID)rand_start.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
