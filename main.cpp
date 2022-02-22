#include <vector>
#include <iostream>
#include "vector.hpp"

template <typename T>
void print_vector(const ft::vector<T>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
		std::cout << vector[i] << std::endl;
		std::cout << "-------------------" << std::endl;
}

int main()
{
	ft::vector<std::string> vec;
	vec.puch_back("chicky");
	vec.puch_back("akira");
	vec.puch_back("test");
	print_vector(vec);
	vec.pop_back();
	print_vector(vec);
	vec.puch_back("test2");
	vec.puch_back("test3");
	print_vector(vec);
	vec.clear();
	print_vector(vec);
	vec.puch_back("test4");
	vec.puch_back("test5");
	print_vector(vec);

    return 0;
}