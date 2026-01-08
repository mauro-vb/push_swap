# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 11:46:41 by mvazquez          #+#    #+#              #
#    Updated: 2026/01/08 11:46:44 by mvazquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc
RM = rm -f

SRC = $(wildcard src/*.c)


OBJ = $(SRC:.c=.o)

# pattern rule to build any .o file i need corresponding .c
%.o: %.c
	@echo "Compiling $^"
	@$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Building $(NAME)"
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJ} ./libft/libft.a -o ${NAME}

clean:
	@echo "Cleaning $(NAME) .o files"
	@$(RM) $(OBJ)

fclean: clean
	@echo "Removing $(NAME)"
	@$(RM) $(NAME)
	@${MAKE} fclean -C ./libft

re: fclean all
