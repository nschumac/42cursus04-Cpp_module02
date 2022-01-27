NAME = triangle

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp

FLAGS = -Wall -Werror -Wextra -o

all: $(NAME)

$(NAME):
	clang++ $(SRC) $(FLAGS) $@

fclean:
	rm -rf $(NAME)

clean:

re: fclean $(NAME)