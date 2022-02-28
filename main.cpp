#include <vector>
#include <iostream>
#include "vector.hpp"

#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid

#include "iterators_traits.hpp"

template <typename T>
void print_vector(const ft::vector<T>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
		std::cout << vector[i] << std::endl;
		std::cout << "-------------------" << std::endl;
}

int main()
{
	// ft::vector<std::string> vec;
	// std::cout << vec.m_Capacity<< vec.m_Size <<"\n"; 

	// std::vector<std::string> v;
	// std::cout << v.capacity() << v.size() <<"\n"; 
	// vec.puch_back("chicky");
	// vec.puch_back("akira");
	// vec.puch_back("test");
	// print_vector(vec);
	// vec.pop_back();
	// print_vector(vec);


	// vec.puch_back("test2");
	// vec.puch_back("test3");
	// print_vector(vec);
	// vec.clear();
	// print_vector(vec);
	// vec.puch_back("test4");
	// vec.puch_back("test5");
	// print_vector(vec);

	//test iterator_traits
	typedef std::iterator_traits<int*> traits;
  	if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
    	std::cout << "int* is a random-access iterator\n";
	
	typedef ft::iterator_traits<int*> my_traits;
  	if (typeid(my_traits::iterator_category)==typeid(std::random_access_iterator_tag))
    	std::cout << "int* is My random-access iterator";	

    return 0;
}