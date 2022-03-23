NAME = vector
SRCS = main.cpp
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
CC = c++
HEADER = vector.hpp iterators_traits.hpp RandomAccessIterator.hpp ReverseIterator.hpp Node.hpp Tree.hpp AVLTree.hpp
all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	
fclean: clean
	@rm -f $(NAME)
re: fclean all