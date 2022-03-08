#include <vector>
#include <iostream>
#include "vector.hpp"

#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
#include "is_integral.hpp"
#include "enable_if.hpp"


template <typename T>
void print_vector(const ft::vector<T>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
	{
		std::cout << vector[i] << std::endl;
	}
	std::cout << "-------------------" << std::endl;
}
template <unsigned n>
struct factorial :integral_constant<int,n * factorial<n-1>::value> {};

template <>
struct factorial<0> : integral_constant<int,1> {};

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename ft::enable_if<std::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

// 2. the second template argument is only valid if T is an integral type:
template < class T,
           class = typename ft::enable_if<std::is_integral<T>::value>::type>
bool is_even (T i) {return !bool(i%2);}
int main()
{
	// {
	// 	ft::vector<std::string> vec;
	// 	std::cout << "capacity: " << vec.capacity() << " size: "<< vec.size() <<"\n"; 
	// 	vec.push_back("chicky");
	// 	vec.push_back("akira");
	// 	vec.push_back("test");
	// 	print_vector(vec);
	// 	std::cout << "capacity: " << vec.capacity() << " size: "<< vec.size() <<"\n"; 
	// 	vec.pop_back();
	// 	print_vector(vec);
	// 	std::cout << "capacity: " << vec.capacity() << " size: "<< vec.size() <<"\n"; 


	// 	vec.push_back("test2");
	// 	vec.push_back("test3");
	// 	print_vector(vec);
	// 	std::cout << "capacity: " << vec.capacity() << " size: "<< vec.size() <<"\n";  
	// 	vec.clear();
	// 	print_vector(vec);
	// 	std::cout << "capacity: " << vec.capacity() << " size: "<< vec.size() <<"\n"; 
	// 	vec.push_back("test4");
	// 	vec.push_back("test5");
	// 	vec.push_back("test4");
	// 	vec.push_back("test5");
	// 	vec.push_back("test4");
	// 	vec.push_back("test5");
	// 	print_vector(vec);
	// 	std::cout << "capacity: " << vec.capacity() << " size: "<< vec.size() <<"\n"; 
	// }


	// //test iterator_traits
	// typedef ft::iterator_traits<int*> my_traits;
  	// if (typeid(my_traits::iterator_category)==typeid(std::random_access_iterator_tag))
    // 	std::cout << "int* is My random-access iterator\n";	

	// std::cout << "1 ---------------" << "\n";
    // ft::vector<int> vect;
    // vect.puch_back(13);
    // vect.puch_back(11);
    // vect.puch_back(3);
    // std::cout << vect[0] << "\n";
    // std::cout << vect[1] << "\n";
    // std::cout << vect[2] << "\n";

    // std::cout << "2 ---------------" << "\n";
    // //test iterator

    // ft::vector<int>::iterator it = vect.begin();

    // //test dereference
    // std::cout << *it << "\n";

    // //test post_increment a++
    // it++;

    // //test dereference
    // std::cout << *it << "\n";

    // it++;
    // std::cout << *it << "\n";

    //  std::cout << "3 ---------------" << "\n";
    // //create other vector

    // ft::vector<int> vect1;
    // vect1.puch_back(1);
    // vect1.puch_back(-5);

    // ft::vector<int>::iterator it1 = vect1.begin();

    // std::cout << *it1 << "\n";
    // std::cout << *it << "\n";

    // //test assignement
    // it = it1;
    // std::cout << *it << "\n";

    // it++;
    // std::cout << *it << "\n";

    // std::cout << "4 ---------------" << "\n";

    // std::cout << *it1 << "\n";

    // //test copy constructor
    // ft::vector<int>::iterator it2(it1);
    // std::cout << *it2 << "\n";

    // std::cout << "5 ---------------" << "\n";

    // ft::vector<int> vect2;
    // vect2.puch_back(100);
    // vect2.puch_back(200);
    // vect2.puch_back(300);

    // ft::vector<int>::iterator it3 = vect2.begin();

    // int a = 3;
    // a = *it3++;

    // std::cout << "a : " << a << "\n";
    // std::cout << "a : " << *it3 << "\n";

    // std::cout << "6 ---------------" << "\n";
    // //test pre-increment ++a

    // ++it3;
    // std::cout << *it3 << "\n";

    // std::cout << "7 ---------------" << "\n";

    // ft::vector<std::string> myVector;
    // myVector.puch_back("chicky");
    // myVector.puch_back("akira");
    // // myVector.puch_back("www");
    // // myVector.puch_back("rrr");
    // // myVector.puch_back("ggg");

    // ft::vector<std::string>::iterator myIt1 = myVector.begin();
    // ft::vector<std::string>::iterator myIt2 = myIt1++;

    // std::cout <<  "myIt1 :" << *myIt1 << "\n";
    // std::cout << "myIt2 :"  << *myIt2 << "\n";

    // ft::vector<std::string>::iterator myIt3 = ++myIt1;

    // std::cout <<  "myIt1 :" << *myIt1 << "\n";
    // std::cout << "myIt3 :"  << *myIt3 << "\n";

	// std::cout << "8 ---------------" << "\n";
	// {
	// 	ft::vector<int> vect;
	// 	vect.puch_back(10);
	// 	vect.puch_back(11);
	// 	vect.puch_back(43);
	// 	vect.puch_back(66);
	// 	vect.puch_back(90);
	// 	ft::vector<int>::iterator it = vect.begin();
	// 	std::cout << *it <<"\n";
	// 	std::cout << it[0] <<"\n";
	// 	// a + n
	// 	ft::vector<int>::iterator ret = it + 3;

	// 	std::cout << "*ret " << *ret << "\n";
	// 	std::cout << "*it " << *it << "\n";
	// 	// n + a
	// 	ft::vector<int>::iterator ret3  = 1 + ret; 
	// 	std::cout << "*ret3 " << *ret3 << "\n";
	// 	std::cout << "*it " << *it << "\n";
	// 	// a - n
	// 	ft::vector<int>::iterator ret4  = ret3 - 1; 
	// 	std::cout << "*ret4 " << *ret4 << "\n";
	// 	std::cout << "*it " << *it << "\n";
	// 	// a - b
	// 	int ret5  = ret4 - it; 
	// 	std::cout << "*ret5 " << ret5 << "\n";
	// 	std::cout << "*it " << *it << "\n";
	// 	// test comparison operators 
	// 	if (ret == ret4)
	// 		std::cout << *ret << " = " << *ret4 << "\n";
	// 	if (it != ret4)
	// 		std::cout << *it << " != " << *ret4 << "\n";
	// 	if (it < ret4)
	// 		std::cout << *it << " < " << *ret4 << "\n";
	// 	if (ret3 > ret)
	// 		std::cout << *ret3 << " > " << *ret << "\n";
	// 	if (it <= ret4)
	// 		std::cout << *it << " <= " << *ret4 << "\n";
	// 	if (ret3 >= ret)
	// 		std::cout << *ret3 << " >= " << *ret << "\n";
	// 	// a += n
	// 	ft::vector<int>::iterator p  = ret += 1; 
	// 	std::cout << "ret += 1 ==> " << *p << "\n";
	// 	std::cout << "ret ==> " << *ret << "\n";
	// 	// a -= n
	// 	ft::vector<int>::iterator m = ret -= 1;
	// 	std::cout << "ret -= 1 ==> " << *m << "\n";
	// 	std::cout << "ret ==> " << *ret << "\n";

	// {
	// 	//test constuction reverse iterator
	// 	std::cout << "test constuction reverse iterator" << std::endl;
	// 	ft::vector<int> myvector;
	// 	myvector.puch_back(43);
	// 	myvector.puch_back(55);
	// 	myvector.puch_back(6);
	// 	print_vector(myvector);

	// 	typedef ft::vector<int>::iterator iter_type;
	// 															// ? 0 1 2 3 4 5 6 7 8 9 ?
	// 	iter_type from (myvector.begin());                     	//   ^
	// 															//         ------>
	// 	iter_type until (myvector.end());                      	//                       ^
	// 															//
	// 	std::reverse_iterator<iter_type> rev_until (from);     	// ^
	// 															//         <------
	// 	std::reverse_iterator<iter_type> rev_from (until);     	//                     ^

	// 	std::cout << "myvector:";
	// 	while (rev_from != rev_until)
	// 		std::cout << ' ' << *rev_from++;
	// 	std::cout << '\n';
	// }

	// {
	// 	//test base iterator
	// 	std::cout << "test base iterator" << std::endl;
	// 	ft::vector<int> myvector;
	// 	myvector.puch_back(43);
	// 	myvector.puch_back(55);
	// 	myvector.puch_back(6);
	// 	print_vector(myvector);

	// 	typedef ft::vector<int>::iterator iter_type;

	// 	std::reverse_iterator<iter_type> rev_end (myvector.begin());
	// 	std::reverse_iterator<iter_type> rev_begin (myvector.end());

	// 	std::cout << "myvector:";
	// 	for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }

	// {
	// 	// test operator +
	// 	std::cout << "test operator +" << std::endl;
	// 	ft::vector<int> myvector;
	// 	myvector.puch_back(43);
	// 	myvector.puch_back(55);
	// 	myvector.puch_back(6);
	// 	myvector.puch_back(77);
	// 	myvector.puch_back(32);
	// 	print_vector(myvector);

	// 	typedef ft::vector<int>::iterator iter_type;
		
	// 	ft::reverse_iterator<iter_type> rev_it;
		
	// 	rev_it = myvector.rbegin() +3;

  	// 	std::cout << "The fourth element from the end is: " << *rev_it << '\n';
	// 	// test operator ++
	// 	iter_type from (myvector.begin());                     //   ^
    //                                                      //         ------>
	// 	iter_type until (myvector.end()); 
	// 	ft::reverse_iterator<iter_type> rev_until (from);     // ^
    //                                                      //         <------
	// 	ft::reverse_iterator<iter_type> rev_from (until); 
	// 	while (rev_from != rev_until)
	// 	{
    // 		std::cout << ' ' << *rev_from;
	// 		++rev_from;
	// 	}
	// 	std::cout << "\n";
	// 	// reverse_iterator::operator+= example
	// 	ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

	// 	rev_iterator += 2;

  	// 	std::cout << "The third element from the end is: " << *rev_iterator << '\n';
	// 	// reverse_iterator::operator- example
	// 	rev_iterator = myvector.rend() - 3;

  	// 	std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n';
	// }

	// {
	// 	// reverse_iterator::operator-- example
	// 	std::cout << "// reverse_iterator::operator-- example\n";
	// 	ft::vector<int> myvector;
	// 	myvector.puch_back(11);
	// 	myvector.puch_back(12);
	// 	myvector.puch_back(13);
	// 	myvector.puch_back(14);
	// 	myvector.puch_back(15);

	// 	typedef ft::vector<int>::iterator iter_type;

	// 	ft::reverse_iterator<iter_type> rev_begin (myvector.end());
	// 	ft::reverse_iterator<iter_type> rev_end (myvector.begin());

	// 	ft::reverse_iterator<iter_type> rev_iterator = rev_begin;
	// 	while ( rev_iterator != rev_end )
	// 		std::cout << *rev_iterator++ << ' ';
	// 	std::cout << '\n';

	// 	while ( rev_iterator != rev_begin )
	// 		std::cout << *(--rev_iterator) << ' ';
	// 	std::cout << '\n';
	// 	//test operator -=
	// 	ft::reverse_iterator<iter_type> rev_iterator1 = myvector.rend();
		
	// 	rev_iterator1 -= 2;

  	// 	std::cout << "rev_iterator now points to: " << *rev_iterator1 << '\n';
		
	// 	// reverse_iterator::operator[] example
	// 	std::cout << "The fourth element from the end is: " << rev_iterator[1] << '\n';
	// }
	// integral_constant::operator value_type example

	{
		// is_integral<T> inherits from integral_constant

		if ( ft::is_integral<int>() )
			std::cout << "int is an integral type" << std::endl;

		// same result as:
		if ( ft::is_integral<int>::value )
			std::cout << "int is an integral type" << std::endl;
	}
	{
		 std::cout << factorial<5>::value;  // constexpr (no calculations on runtime)
	}

	{
		// enable_if example: two ways of using enable_if
		short int i = 1;    // code does not compile if type of i is not integral

  		std::cout << std::boolalpha;
  		std::cout << "i is odd: " << is_odd(i) << std::endl;
  		std::cout << "i is even: " << is_even(i) << std::endl;
	}
	// {
	// 	//test Constructs a container with as many elements as the range 
	// 	ft::vector<int> second (4,100);                       // four ints with value 100
  	// 	std::vector<int> third (second.begin(),second.end());  // iterating through second
	// }
    return 0;
}