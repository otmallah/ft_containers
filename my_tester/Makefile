# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 20:25:52 by otmallah          #+#    #+#              #
#    Updated: 2023/01/15 20:32:17 by otmallah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = clang++
FLAGS_DEBUG = --std=c++98 -Wall -Wextra -Werror -fsanitize=address -g3
FLAGS = --std=c++98 -Wall -Wextra -Werror

vector:
	@$(COMPILER) $(FLAGS)	vector.cpp -o vector.out 

map:
	@$(COMPILER) $(FLAGS)	map.cpp -o map.out 

stack:
	@$(COMPILER) $(FLAGS)	stack.cpp -o stack.out 

clean:
	rm -f vector.out map.out stack.out
