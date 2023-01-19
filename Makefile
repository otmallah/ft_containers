# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 21:11:25 by otmallah          #+#    #+#              #
#    Updated: 2023/01/17 18:09:23 by otmallah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CPPFLAGS =  --std=c++98 -Wall -Wextra -Werror -fsanitize=address -g3

CPP_FILES = main.cpp 

OBJ = $(CPP_FILES:.c=.o)

all : $(NAME)

$(NAME) : main.cpp
	clang++ $(CPPFLAGS) main.cpp 
	ar -rc $(NAME) $(OBJ)

clean :
	rm -rf $(NAME) a.out

fclean :
	rm -rf $(NAME) a.out

re : fclean all