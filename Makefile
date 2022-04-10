
FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
HEADER = vector.hpp map.hpp stack.hpp

map:
	@$(CC) -D MAP=1 $(FLAGS) main_map.cpp -o std_map
	@$(CC) -D MAP=0 $(FLAGS) main_map.cpp -o ft_map
vector:
	@$(CC) -D VEC=1 $(FLAGS) main_vector.cpp -o std_vector
	@$(CC) -D VEC=0 $(FLAGS) main_vector.cpp -o ft_vector
stack:
	@$(CC) -D STACK=1 $(FLAGS) main_stack.cpp -o std_stack
	@$(CC) -D STACK=0 $(FLAGS) main_stack.cpp -o ft_stack
clean:
	
fclean: clean
	@rm -f std_map std_vector std_stack
	@rm -f ft_map ft_vector ft_stack
re: fclean all