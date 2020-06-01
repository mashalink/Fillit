# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 10:48:59 by dmukaliy          #+#    #+#              #
#    Updated: 2019/12/02 10:18:38 by dmukaliy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c\
	validate.c\
	trim_input.c\
	support.c\
	fillit.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -I

all: $(NAME)

$(NAME):
		make -C libft/ 
		$(CC) $(FLAGS) libft/ -c $(SRC)
		$(CC) -o $(NAME) $(OBJ) $(FLAGS) libft/ -L libft/ -lft

clean: 
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
