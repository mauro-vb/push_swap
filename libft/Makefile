# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 15:20:24 by mvazquez          #+#    #+#              #
#    Updated: 2025/12/15 16:56:08 by mvazquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = $(shell find "." -name "*.c") $(shell find "ft_printf" -name "*.c")


OBJ = $(SRC:.c=.o)

# pattern rule to build any .o file i need corresponding .c
%.o: %.c
	@echo "Compiling $^"
	@$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Building $(NAME)"
	@ar crs $(NAME) $(OBJ)

clean:
	@echo "Cleaning $(NAME) .o files"
	@$(RM) $(OBJ)

fclean: clean
	@echo "Removing $(NAME)"
	@$(RM) $(NAME)

re: fclean all
