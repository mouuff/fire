##
## Makefile for fire in /home/alies/rendu/gfx_incendie
## 
## Made by Arnaud Alies
## Login   <alies_a@epitech.net>
## 
## Started on  Fri Dec  4 21:57:46 2015 Arnaud Alies
## Last update Tue Apr  4 19:22:24 2017 Morgan Simon
##

NAME    =       fire

CC	=	gcc

INC	=	./include/

CFLAGS	+=	-I/home/${USER}/.froot/include -I$(INC) -Wall -Werror

LDFLAGS	+=	-L/home/${USER}/.froot/lib		\
		-llapin -lsfml-audio -lsfml-graphics	\
		-lsfml-window -lsfml-system -lstdc++ 	\
		-ldl -lm

SRC	=	src/

GRID	=	src/grid/

CORE	=	src/core/

SRCS	=	$(SRC)main.c \
		$(CORE)tekpixel.c \
		$(CORE)pixfill.c \
		$(CORE)pal.c \
		$(GRID)grid_init.c \
		$(GRID)grid_pix.c \
		$(GRID)live.c \
		$(GRID)get_ave.c \
		$(GRID)mouse_to_grid.c \
		$(GRID)rand_start.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
