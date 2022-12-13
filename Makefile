NAME = containers


CPP_FILES = main.cpp 

OBJ = $(CPP_FILES:.c=.o)

all : $(NAME)

$(NAME) : main.cpp
	c++ main.cpp -fsanitize=address -g
	ar -rc $(NAME) $(OBJ)

clean :
	rm -rf $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all
