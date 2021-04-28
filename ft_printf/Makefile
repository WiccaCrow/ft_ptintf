# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdulcie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 03:39:47 by mdulcie           #+#    #+#              #
#    Updated: 2021/01/12 03:39:50 by mdulcie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./ft_printf.c ./add_funct.c ./types.c ./flags_and_part_of_diux.c

OBJ = $(SRC:.c=.o)

HEAD = ft_printf.h
FLAG = -Wall -Wextra -Werror

all:	$(NAME)

%.o: %.c
	gcc $(FLAG) -c $< -I $(HEAD) 

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ) $(OBJ_B)

fclean:	clean
	rm -rf $(NAME)

re:     fclean all

.PHONY: all clean fclean re
