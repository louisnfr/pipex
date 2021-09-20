# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/11 01:48:13 by lraffin           #+#    #+#              #
#    Updated: 2021/09/21 00:40:53 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME = libft.a

# Path
OBJ_PATH = ./obj/

# Binary
SRC_NAME=	ft_split.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strnstr.c

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror

# Rules

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	-@norminette *.c
	-@norminette *.h

push:
	git add .
	git status
	git commit -m libft
	git push

.PHONY: all clean fclean re norm push
