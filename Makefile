# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 12:19:37 by otmallah          #+#    #+#              #
#    Updated: 2022/12/27 18:50:50 by otmallah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CPPFLAGS = -Wall -Wextra -Werror  -fsanitize=address -g

CPP_FILES = main.cpp 

OBJ = $(CPP_FILES:.c=.o)

all : $(NAME)

$(NAME) : main.cpp
	c++  main.cpp 
	ar -rc $(NAME) $(OBJ)

clean :
	rm -rf $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all
