# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/11 01:48:13 by lraffin           #+#    #+#              #
#    Updated: 2021/09/17 17:48:34 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME = libft.a

# Path
OBJ_PATH = ./obj/

# Binary
SRC_NAME=	ft_abs.c \
			ft_atoi_base.c \
			ft_atol.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isflag.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_max.c \
			ft_min.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_nbrlen_u.c \
			ft_nbrlen_ul.c \
			ft_nbrlen.c \
			ft_put0xhexa_ret.c \
			ft_putchar_fd.c \
			ft_putchar_ret.c \
			ft_putchar.c \
			ft_putendl_fd.c \
			ft_puthexa_ret.c \
			ft_putnbr_fd.c \
			ft_putnbr_ret.c \
			ft_putnbr_u_ret.c \
			ft_putnbr_u.c \
			ft_putnbr.c \
			ft_putstr_fd.c \
			ft_putstr_n_ret.c \
			ft_putstr_ret.c \
			ft_putstr.c \
			ft_split.c \
			ft_str_digit.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_swap.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c

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
