##
## EPITECH PROJECT, 2019
## libmy makefile
## File description:
## makefile for my libmy
##

NAME		=	"libmy.a"

INC			=	"my.h"

INC_DIR		=	"../../include/"

CXX			=	gcc


RM			=	rm -f

SRC_LIBMY	=
include		sources_libmy.mk

SRC			=	$(SRC_LIBMY)

OBJ			= 	$(SRC_LIBMY:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../
		cp $(NAME) ../../
		cp $(INC) $(INC_DIR)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)
		$(RM) $(INC_DIR)$(INC)
		$(RM) ../$(NAME)

re		:	fclean all

%.o		:	%.c
		$(CXX) -c $< -o $@ $(CXXFLAGS)

.PHONY	:	all clean fclean re
