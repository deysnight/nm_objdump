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

SRC1	=	src_my_objdump/main.c		\
		src_my_objdump/my_objdump.c	\
		src_my_objdump/filesize.c	\
		src_my_objdump/print_header.c	\
		src_my_objdump/print_content.c	\
		src_my_objdump/get_flag.c

SRC2	=	src_my_nm/main.c

CC	=	gcc -g

RM	=	rm -f

INCLUDE	+=	-I./include

CFLAGS	=	-Wextra -Wall -Werror

NAME1	=	my_objdump

NAME2	=	my_nm

OBJ1	=	$(SRC1:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

all:	$(NAME1) $(NAME2)

objdump:	$(NAME1)

nm:	$(NAME2)

%.o: %.c
	@printf "$(GREEN)Compilation: %s to %s\n$(WHITE)" $< $@
	@$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

$(NAME1): $(OBJ1)
	@$(CC) -o $(NAME1) $(OBJ1) $(CFLAGS)
	@printf "$(YELLOW)Executable generated: $(NAME1)$(WHITE)\n"

$(NAME2): $(OBJ2)
	@$(CC) -o $(NAME2) $(OBJ2) $(CFLAGS)
	@printf "$(YELLOW)Executable generated: $(NAME2)$(WHITE)\n"

clean:
	@printf "$(BLUE)"
	$(RM) $(OBJ1) $(OBJ2)
	@printf "$(RED)Deleting Binairies Success$(WHITE)\n"

fclean: clean
	@printf "$(BLUE)"
	$(RM) $(NAME1) $(NAME2)
	@printf "$(RED)Deleting Executable Success$(WHITE)\n"

re	:	fclean all

.PHONY	:	clean fclean re objdump nm
