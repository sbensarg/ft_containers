NAME = vector
SRCS = main.cpp
FLAGS = -Wall -Wextra -Werror -std=c++11 
CC = c++
HEADER = vector.hpp iterators_traits.hpp RandomAccessIterator.hpp ReverseIterator.hpp
all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	
fclean: clean
	@rm -f $(NAME)
re: fclean all