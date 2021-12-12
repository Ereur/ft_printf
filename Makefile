# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 14:50:28 by zoukaddo          #+#    #+#              #
#    Updated: 2021/12/11 17:11:44 by aamoussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_puthexa.c



OBJ = ft_printf.o ft_putchar.o ft_putnbr.o ft_putstr.o ft_puthexa.o

all :$(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)
re :fclean all