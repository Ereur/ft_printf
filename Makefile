# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 14:50:28 by zoukaddo          #+#    #+#              #
#    Updated: 2021/12/12 08:28:36 by aamoussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils.c


OBJ = ft_printf.o ft_printf_utils.o

all :$(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)
re :fclean all