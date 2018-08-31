##
## Makefile for Makefile in /home/sadiqu-m/delivery/C_prog_elem/CPE_rush4stek_2016
## 
## Made by Sadiqu-m
## Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
## 
## Started on  Sat Jun  3 15:48:46 2017 Sadiqu-m
## Last update Sun Jun  4 16:47:24 2017 Sadiqu-m
##

NAME            = ai

SRC             = ./src/main.c \
		  ./src/get_cmd.c \
		  ./src/get_next_line.c \
		  ./src/tools.c \
		  ./src/ai.c \
		  ./src/timer.c \
		  ./src/my_str_to_wordtab.c \

CC              = gcc $(LFLAGS)

RM              = rm -rf

OBJ             = $(SRC:.c=.o)

CFLAGS		+= -I./include -I.

CFLAGS		+= -W -Wall -Wextra

all:
	@make --no-print-directory $(NAME)

$(NAME):        $(OBJ)
	$(CC) 	$(OBJ) -o $(NAME) -lc_graph_prog_full -lm -lncurses
 
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all
