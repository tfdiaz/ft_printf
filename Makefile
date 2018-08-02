# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 11:46:35 by tdiaz             #+#    #+#              #
#    Updated: 2018/07/20 18:58:36 by tdiaz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c itoa_base.c ft_strnew.c ft_putendl.c ft_putnbr.c ft_putchar.c \
	ft_memset.c ft_putstr.c ft_atoi.c ft_strlen.c vect_add.c vect_new.c vect_free.c \
	ft_memmove.c ft_strcat.c ft_strcpy.c ft_strjoin.c ft_strdup.c unicode.c wchar_funt.c \
	up_str.c flags.c concheck.c prt_cws.c octhex.c clouds.c iu_prt.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
