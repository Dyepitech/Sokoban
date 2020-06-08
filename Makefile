##
## EPITECH PROJECT, 2019
## final_stumper
## File description:
## makefile for final_stumper
##

NAME		=	"my_sokoban"

NAME_TEST	=	"unit_tests"

MAKE        =   make

LIBMY_DIR   =   ./lib/my/

CXX			=	gcc

RM			=	rm -f

CXXFLAGS	=	-Wall -Wextra -Werror
CXXFLAGS	+=	-I./include/ -L./lib/ -lmy -lncurses

LDFLAGS		=

DEBUG		=	no

DFLAGS		=	-Y.include/

ifneq ($(DEBUG), no)
CXXFLAGS	+=	-g
LDFLAGS		+=	-s
endif

SRC			=
include		sources_sokoban.mk

OBJ			=	$(SRC:.c=.o)

SRC_TEST	= /tests/test.c
include

OBJ_TEST	=	$(SRC_TEST:.c=.o)

all		:	$(NAME)

$(MAKE) :
	        $(MAKE) -C $(LIBMY_DIR)

$(NAME) :   $(MAKE) $(OBJ)
	        $(CXX) $(OBJ) -o $(NAME) $(CXXFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re		:	fclean all

tests_run	:	$(MAKE) $(SRC_TEST)
		$(CXX) -o $(NAME_TEST) $(SRC_TEST) $(CXXFLAGS) --coverage -lcriterion
		./$(NAME_TEST)
		./tests/

%.o		:	%.c
		$(CXX) -c $< -o $@ $(CXXFLAGS)

.PHONY  :   all clean fclean re
