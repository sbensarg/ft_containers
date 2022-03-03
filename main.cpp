#include <vector>
#include <iostream>
#include "vector.hpp"

#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid


template <typename T>
void print_vector(const ft::vector<T>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
	{
		std::cout << vector[i] << std::endl;
	}
	std::cout << "-------------------" << std::endl;
}

int main()
{
	// {
	// 	ft::vector<std::string> vec;
	// 	std::vector<std::string> v;
	// 	std::cout << v.capacity() << v.size() <<"\n"; 
	// 	vec.puch_back("chicky");
	// 	vec.puch_back("akira");
	// 	vec.puch_back("test");
	// 	print_vector(vec);
	// 	// vec.pop_back();
	// 	// print_vector(vec);


	// 	// vec.puch_back("test2");
	// 	// vec.puch_back("test3");
	// 	// print_vector(vec);
	// 	// vec.clear();
	// 	// print_vector(vec);
	// 	// vec.puch_back("test4");
	// 	// vec.puch_back("test5");
	// 	// print_vector(vec);
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

	{
		//test constuction reverse iterator
		std::cout << "test constuction reverse iterator" << std::endl;
		ft::vector<int> myvector;
		myvector.puch_back(43);
		myvector.puch_back(55);
		myvector.puch_back(6);
		print_vector(myvector);

		typedef ft::vector<int>::iterator iter_type;
																// ? 0 1 2 3 4 5 6 7 8 9 ?
		iter_type from (myvector.begin());                     	//   ^
																//         ------>
		iter_type until (myvector.end());                      	//                       ^
																//
		std::reverse_iterator<iter_type> rev_until (from);     	// ^
																//         <------
		std::reverse_iterator<iter_type> rev_from (until);     	//                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}

	{
		//test base iterator
		std::cout << "test base iterator" << std::endl;
		ft::vector<int> myvector;
		myvector.puch_back(43);
		myvector.puch_back(55);
		myvector.puch_back(6);
		print_vector(myvector);

		typedef ft::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_end (myvector.begin());
		std::reverse_iterator<iter_type> rev_begin (myvector.end());

		std::cout << "myvector:";
		for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	{
		// test operator +
		std::cout << "test operator +" << std::endl;
		ft::vector<int> myvector;
		myvector.puch_back(43);
		myvector.puch_back(55);
		myvector.puch_back(6);
		myvector.puch_back(77);
		myvector.puch_back(32);
		print_vector(myvector);

		typedef ft::vector<int>::iterator iter_type;
		
		ft::reverse_iterator<iter_type> rev_it;
		
		rev_it = myvector.rbegin() +3;

  		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
		// test operator ++
		iter_type from (myvector.begin());                     //   ^
                                                         //         ------>
		iter_type until (myvector.end()); 
		ft::reverse_iterator<iter_type> rev_until (from);     // ^
                                                         //         <------
		ft::reverse_iterator<iter_type> rev_from (until); 
		while (rev_from != rev_until)
		{
    		std::cout << ' ' << *rev_from;
			++rev_from;
		}
		std::cout << "\n";
		// reverse_iterator::operator+= example
		ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

		rev_iterator += 2;

  		std::cout << "The third element from the end is: " << *rev_iterator << '\n';
		// reverse_iterator::operator- example
		rev_iterator = myvector.rend() - 3;

  		std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n';
	}

	{
		// reverse_iterator::operator-- example
		std::cout << "// reverse_iterator::operator-- example\n";
		ft::vector<int> myvector;
		myvector.puch_back(11);
		myvector.puch_back(12);
		myvector.puch_back(13);
		myvector.puch_back(14);
		myvector.puch_back(15);

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_begin (myvector.end());
		ft::reverse_iterator<iter_type> rev_end (myvector.begin());

		ft::reverse_iterator<iter_type> rev_iterator = rev_begin;
		while ( rev_iterator != rev_end )
			std::cout << *rev_iterator++ << ' ';
		std::cout << '\n';

		while ( rev_iterator != rev_begin )
			std::cout << *(--rev_iterator) << ' ';
		std::cout << '\n';
		//test operator -=
		ft::reverse_iterator<iter_type> rev_iterator1 = myvector.rend();
		
		rev_iterator1 -= 2;

  		std::cout << "rev_iterator now points to: " << *rev_iterator1 << '\n';
		
		// reverse_iterator::operator[] example
		std::cout << "The fourth element from the end is: " << rev_iterator[1] << '\n';
	}

    return 0;
}