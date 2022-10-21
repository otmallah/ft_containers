NAME = containers

CPPFLAGS = -W -W -W -std=c++98

CPP_FILES = main.cpp utils.cpp

OBJ = $(CPP_FILES:.c=.o)

all : $(NAME)

$(NAME) : main.cpp
	c++ $(CPPFLAGS) $(CPP_FILES) -fsanitize=address
	ar -rc $(NAME) $(OBJ)

clean :
	rm -rf $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all
