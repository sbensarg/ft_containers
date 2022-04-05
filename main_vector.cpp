#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
#include <iomanip> 


#if VEC == 1 //CREATE A REAL STL EXAMPLE
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
#endif

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"


template <typename T>
void print_vector(const ft::vector<T>& vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << std::endl;
	}
	std::cout << "-------------------" << std::endl;
}

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename ft::enable_if<std::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

//a case-insensitive comparison function:
bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main()
{
	{
		ft::vector<std::string> vec;
		std::cout << "capacity: " << vec.capacity() << " size: "<< vec.size() <<"\n"; 
		vec.push_back("chicky");
		vec.push_back("akira");
		vec.push_back("test");
		print_vector(vec);
		std::cout << "capacity: " << vec.capacity() << " size: "<< vec.size() <<"\n"; 
		vec.pop_back();
		print_vector(vec);
		std::cout << "capacity: " << vec.capacity() << " size: "<< vec.size() <<"\n"; 


		vec.push_back("test2");
		vec.push_back("test3");
		print_vector(vec);
		std::cout << "capacity: " << vec.capacity() << " size: "<< vec.size() <<"\n";  
		vec.clear();
		print_vector(vec);
		std::cout << "capacity: " << vec.capacity() << " size: "<< vec.size() <<"\n"; 
		vec.push_back("test4");
		vec.push_back("test5");
		vec.push_back("test4");
		vec.push_back("test5");
		vec.push_back("test4");
		vec.push_back("test5");
		print_vector(vec);
		std::cout << "capacity: " << vec.capacity() << " size: "<< vec.size() <<"\n"; 
	}

	std::cout <<GRN "test iterator_traits\n"RESET;	
	//test iterator_traits
	typedef ft::iterator_traits<int*> my_traits;
  	if (typeid(my_traits::iterator_category)==typeid(std::random_access_iterator_tag))
    	std::cout << "int* is My random-access iterator\n";	

	std::cout << "1 ---------------" << "\n";
    ft::vector<int> vect;
    vect.push_back(13);
    vect.push_back(11);
    vect.push_back(3);
    std::cout << vect[0] << "\n";
    std::cout << vect[1] << "\n";
    std::cout << vect[2] << "\n";

    std::cout << "2 ---------------" << "\n";
	std::cout <<GRN "test iterator\n"RESET;	
    //test iterator

    ft::vector<int>::iterator it = vect.begin();

    //test dereference
	std::cout <<GRN "test dereference\n"RESET;	
    std::cout << *it << "\n";

    //test post_increment a++
	std::cout <<GRN "test post_increment a++\n"RESET;	
    it++;

    //test dereference
	std::cout <<GRN "test dereference\n"RESET;	
    std::cout << *it << "\n";

    it++;
    std::cout << *it << "\n";

    std::cout << "3 ---------------" << "\n";
    //create other vector
	std::cout <<GRN "create other vector\n"RESET;

    ft::vector<int> vect1;
    vect1.push_back(1);
    vect1.push_back(-5);

    ft::vector<int>::iterator it1 = vect1.begin();

    std::cout << *it1 << "\n";
    std::cout << *it << "\n";

    //test assignement
	std::cout <<GRN "test assignement vector\n"RESET;
    it = it1;
    std::cout << *it << "\n";

    it++;
    std::cout << *it << "\n";

    std::cout << "4 ---------------" << "\n";

    std::cout << *it1 << "\n";

    //test copy constructor
	std::cout <<GRN "test copy constructor vector\n"RESET;
    ft::vector<int>::iterator it2(it1);
    std::cout << *it2 << "\n";

    std::cout << "5 ---------------" << "\n";

    ft::vector<int> vect2;
    vect2.push_back(100);
    vect2.push_back(200);
    vect2.push_back(300);

    ft::vector<int>::iterator it3 = vect2.begin();

    int a = 3;
    a = *it3++;

    std::cout << "a : " << a << "\n";
    std::cout << "a : " << *it3 << "\n";

    std::cout << "6 ---------------" << "\n";
	std::cout <<GRN "test pre-increment ++a\n"RESET;
    //test pre-increment ++a

    ++it3;
    std::cout << *it3 << "\n";

    std::cout << "7 ---------------" << "\n";

    ft::vector<std::string> myVector;
    myVector.push_back("chicky");
    myVector.push_back("akira");
    myVector.push_back("www");
    myVector.push_back("rrr");
    myVector.push_back("ggg");

    ft::vector<std::string>::iterator myIt1 = myVector.begin();
    ft::vector<std::string>::iterator myIt2 = myIt1++;

    std::cout <<  "myIt1 :" << *myIt1 << "\n";
    std::cout << "myIt2 :"  << *myIt2 << "\n";

    ft::vector<std::string>::iterator myIt3 = ++myIt1;

    std::cout <<  "myIt1 :" << *myIt1 << "\n";
    std::cout << "myIt3 :"  << *myIt3 << "\n";

	std::cout << "8 ---------------" << "\n";
	{
		ft::vector<int> vect;
		vect.push_back(10);
		vect.push_back(11);
		vect.push_back(43);
		vect.push_back(66);
		vect.push_back(90);
		ft::vector<int>::iterator it = vect.begin();
		std::cout << *it <<"\n";
		std::cout << it[0] <<"\n";
		std::cout <<GRN "test a + n\n"RESET;
		// a + n
		ft::vector<int>::iterator ret = it + 3;
		std::cout << "*ret " << *ret << "\n";
		std::cout << "*it " << *it << "\n";
		std::cout <<GRN "test  n + a\n"RESET;
		// n + a
		ft::vector<int>::iterator ret3  = 1 + ret; 
		std::cout << "*ret3 " << *ret3 << "\n";
		std::cout << "*it " << *it << "\n";
		std::cout <<GRN "test  a - n\n"RESET;
		// a - n
		ft::vector<int>::iterator ret4  = ret3 - 1; 
		std::cout << "*ret4 " << *ret4 << "\n";
		std::cout << "*it " << *it << "\n";
		std::cout <<GRN "test  a - b\n"RESET;
		// a - b
		int ret5  = ret4 - it; 
		std::cout << "*ret5 " << ret5 << "\n";
		std::cout << "*it " << *it << "\n";
		std::cout <<GRN "test comparison operators\n"RESET;
		// test comparison operators 
		if (ret == ret4)
			std::cout << *ret << " = " << *ret4 << "\n";
		if (it != ret4)
			std::cout << *it << " != " << *ret4 << "\n";
		if (it < ret4)
			std::cout << *it << " < " << *ret4 << "\n";
		if (ret3 > ret)
			std::cout << *ret3 << " > " << *ret << "\n";
		if (it <= ret4)
			std::cout << *it << " <= " << *ret4 << "\n";
		if (ret3 >= ret)
			std::cout << *ret3 << " >= " << *ret << "\n";
		// a += n
		ft::vector<int>::iterator p  = ret += 1; 
		std::cout << "ret += 1 ==> " << *p << "\n";
		std::cout << "ret ==> " << *ret << "\n";
		// a -= n
		ft::vector<int>::iterator m = ret -= 1;
		std::cout << "ret -= 1 ==> " << *m << "\n";
	 	std::cout << "ret ==> " << *ret << "\n";
	}
	{
		//test constuction reverse iterator
		std::cout << GRN"test constuction reverse iterator" << std::endl<< RESET;
		ft::vector<int> myvector;
		myvector.push_back(43);
		myvector.push_back(55);
		myvector.push_back(6);
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
		std::cout <<GRN "test base iterator" << std::endl << RESET;
		ft::vector<int> myvector;
		myvector.push_back(43);
		myvector.push_back(55);
		myvector.push_back(6);
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
		std::cout << GRN "test operator +" << std::endl << RESET;
		ft::vector<int> myvector;
		myvector.push_back(43);
		myvector.push_back(55);
		myvector.push_back(6);
		myvector.push_back(77);
		myvector.push_back(32);
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
		std::cout << GRN "reverse_iterator::operator-- example\n"RESET;
		ft::vector<int> myvector;
		myvector.push_back(11);
		myvector.push_back(12);
		myvector.push_back(13);
		myvector.push_back(14);
		myvector.push_back(15);

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
	//integral_constant::operator value_type example

	{
		// is_integral<T> inherits from integral_constant
		std::cout <<GRN  "is_integral<T> inherits from integral_constant \n"RESET;
		if ( ft::is_integral<int>() )
			std::cout << "int is an integral type" << std::endl;

		// same result as:
		if ( ft::is_integral<int>::value )
			std::cout << "int is an integral type" << std::endl;
	}
	
	{
		std::cout <<GRN  "enable_if example: two ways of using enable_if \n"RESET;
		// enable_if example: two ways of using enable_if
		short int i = 1;    // code does not compile if type of i is not integral

		std::cout << std::boolalpha;
		std::cout << "i is odd: " << is_odd(i) << std::endl;
	}

	{
		std::cout <<GRN  "test Constructs a container with as many elements as the range \n"RESET;
		//test Constructs a container with as many elements as the range 
		ft::vector<int> second (4,300);                       // four ints with value 100
  		ft::vector<int> third (second.begin(),second.end());  // iterating through second
		ft::vector<int> fourth (third);                       // a copy of third
		for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
    		std::cout << ' ' << *it;
		std::cout << '\n';
	}

	{
		std::cout <<GRN  "comparing size, capacity and max_size vector\n"RESET;
		// comparing size, capacity and max_size
		ft::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		std::cout << "size: " << myvector.size() << "\n";
		std::cout << "capacity: " << myvector.capacity() << "\n";
		std::cout << "max_size: " << myvector.max_size() << "\n";
	}

	{
		std::cout <<GRN  "resizing vector\n"RESET;
		ft::vector<int> myvector;

		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);
		std::cout << "size : " << myvector.size() << " capacity :" << myvector.capacity() << "\n"; 
		std::cout << "myvector contains:";
		for (size_t i=0;i<myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

	}

	{
		std::cout <<GRN  "vector::reserve\n"RESET;
		ft::vector<int>::size_type sz;

		ft::vector<int> foo;
		sz = foo.capacity();
		std::cout << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
			}
		}
		 try {
			// vector throws a length_error if resized above max_size
				ft::vector<int> bar;
				sz = bar.capacity();
				bar.reserve(4611686018427387906);   // this is the only difference with foo above
				std::cout << "making bar grow:\n";
				for (int i=0; i<100; ++i) {
					bar.push_back(i);
					if (sz!=bar.capacity()) {
					sz = bar.capacity();
					std::cout << "capacity changed: " << sz << '\n';
					}
				}
  			}		
  		catch (const std::length_error& le) {
	  		std::cerr << "Length error: " << le.what() << '\n';
  		}
		
	}

	{
		std::cout <<GRN  "test vector::empty\n"RESET;
		ft::vector<int> myvector;
		int sum (0);

		for (int i=1;i<=10;i++) myvector.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}

		std::cout << "total: " << sum << '\n';
	}

	{
		//test vector back
		std::cout <<GRN  "test vector back\n"RESET;
		ft::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}

	{
		std::cout <<GRN  "test vector::front\n"RESET;
		// test vector::front
		ft::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		std::cout << "myvector.front() is now " << myvector.front() << '\n';
	}

	{
		std::cout <<GRN  "test vector::at\n"RESET;
		try
		{
			//test vector::at
			ft::vector<int> myvector (10);   // 10 zero-initialized ints

			// assign some values:
			for (unsigned i=0; i<myvector.size(); i++)
				myvector.at(i)=i;

			//std::cout << "myvector contains:";
			for (unsigned i=0; i<myvector.size(); i++)
				std::cout << ' ' << myvector.at(30);
			std::cout << '\n';
		}
		catch(const std::out_of_range& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout <<GRN  "vector assign\n"RESET;
		ft::vector<int> first;
		ft::vector<int> second;
		ft::vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		ft::vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		std::cout << "Size of third: " << int (third.size()) << '\n';
	}
	
	{
		std::cout <<GRN  "vector insert\n"RESET;
		ft::vector<int> myvector (3,100);
		ft::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );

		myvector.insert (it,2,300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		ft::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		std::cout << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	{
		std::cout <<GRN  "vector erase\n"RESET;
		ft::vector<int> myvector;
		ft::vector<int>::iterator it;
		ft::vector<int>::iterator it1;
		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		// erase the 6th element
	//	myvector.erase (myvector.begin()+5);


		
		it = myvector.erase (myvector.begin()+5);
		std::cout << "iterator pointing to the new location " << *it << "\n";
		 // erase the first 3 elements:
		it1 = myvector.erase (myvector.begin(),myvector.begin()+3);
		std::cout << "it1 " << *it1 << "\n";
		std::cout << "myvector contains:";
		std::cout << myvector.size() << "\n";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}

	{
		std::cout <<GRN  "swap vectors test\n"RESET;
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << '\n';

		std::cout << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << '\n';
	}

	{
		std::cout << GRN "vector::get_allocator\n" RESET;
		ft::vector<int> myvector;
		int * p;
		unsigned int i;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

		std::cout << "The allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];
		std::cout << '\n';

		// destroy and deallocate:
		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p,5);
	}

	{
		std::cout <<GRN  "vector comparisons\n" RESET;
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (2,200);   // two ints with a value of 200

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}

	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_it;

		std::cout <<  *myvector.rbegin() << "\n";
		rev_it = 3 + myvector.rbegin();

		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
	}

	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		ft::reverse_iterator<ft::vector<int>::iterator> from,until;

		from = myvector.rbegin();
		until = myvector.rend();

		std::cout << "myvector has " << (until-from) << " elements.\n";
	}

	{
		std::cout << GRN "lexicographical_compare test\n" RESET;

		char foo[]="Apple";
		char bar[]="apartment";

		std::cout << std::boolalpha;

		std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

		std::cout << "Using default comparison (operator<): ";
		std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
		std::cout << '\n';

		std::cout << "Using mycomp as comparison object: ";
		std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
		std::cout << '\n';
	}

	{
		ft::vector<int> b(70, 70);
		b.clear();
		b.assign(5, 0);
		std::cout << "b c ==> " << b.capacity() << "\n";
	}
	system("leaks ft_vector");
    return 0;
}