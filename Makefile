# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 12:19:37 by otmallah          #+#    #+#              #
#    Updated: 2022/12/19 18:09:00 by otmallah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers


CPP_FILES = main.cpp 

OBJ = $(CPP_FILES:.c=.o)

all : $(NAME)

$(NAME) : main.cpp
	c++ -Wall -Wextra -Werror main.cpp -fsanitize=address -g 
	ar -rc $(NAME) $(OBJ)

clean :
	rm -rf $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all
