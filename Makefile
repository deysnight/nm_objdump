##
## EPITECH PROJECT, 2018
## MAKEFILE
## File description:
## MAKEFILE
##

RED	=	\033[01;31m

GREEN	=	\033[01;32m

YELLOW	=	\033[01;33m

BLUE	=	\033[01;34m

WHITE	=	\033[0m

SRC	=	src_my_objdump/main.c		\
		src_my_objdump/my_objdump.c	\
		src_my_objdump/filesize.c	\
		src_my_objdump/print_header.c	\
		src_my_objdump/print_content.c

CC	=	gcc -g

RM	=	rm -f

INCLUDE	+=	-I./include

CFLAGS	=	#-Wextra -Wall -Werror

NAME	=	my_objdump

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

%.o: %.c
	   @printf "$(GREEN)Compilation: %s to %s\n$(WHITE)" $< $@
	   @$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	   @$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	   @printf "$(YELLOW)Executable generated: $(NAME)$(WHITE)\n"

clean:
	   @printf "$(BLUE)"
	   $(RM) $(OBJ)
	   @printf "$(RED)Deleting Binairies Success$(WHITE)\n"

fclean: clean
	   @printf "$(BLUE)"
	   $(RM) $(NAME)
	   @printf "$(RED)Deleting Executable Success$(WHITE)\n"

re	:	fclean all

.PHONY	:	clean fclean re
