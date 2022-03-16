
#include <vector>
#include <iostream>


template <typename T>
void print_vector(const std::vector<T>& vector)
{
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << std::endl;
		std::cout << "-------------------" << std::endl;
}
int main()
{
	// {
	// 	std::vector<std::string> vec;
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
	
	// {
	// 	std::vector<int> second (4,100);                       // four ints with value 100
  	// 	std::vector<int> third (second.begin(),second.end());  // iterating through second
	// 	for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
    // 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }

	// //test iterator_traits
	// typedef std::iterator_traits<int*> traits;
  	// if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
    // 	std::cout << "int* is a random-access iterator\n";
	
	// std::cout << "1 ---------------" << "\n";
    // std::vector<int> vect;
    // vect.push_back(13);
    // vect.push_back(11);
    // vect.push_back(3);
    // std::cout << vect[0] << "\n";
    // std::cout << vect[1] << "\n";
    // std::cout << vect[2] << "\n";

    // std::cout << "2 ---------------" << "\n";
    // //test iterator

    // std::vector<int>::iterator it = vect.begin();

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

    // std::vector<int> vect1;
    // vect1.push_back(1);
    // vect1.push_back(-5);

    // std::vector<int>::iterator it1 = vect1.begin();

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
    // std::vector<int>::iterator it2(it1);
    // std::cout << *it2 << "\n";

    // std::cout << "5 ---------------" << "\n";

    // std::vector<int> vect2;
    // vect2.push_back(100);
    // vect2.push_back(200);
    // vect2.push_back(300);

    // std::vector<int>::iterator it3 = vect2.begin();

    // int a = 3;
    // a = *it3++;

    // std::cout << "a : " << a << "\n";
    // std::cout << "a : " << *it3 << "\n";

    // std::cout << "6 ---------------" << "\n";
    // //test pre-increment ++a

    // ++it3;
    // std::cout << *it3 << "\n";

    // std::cout << "7 ---------------" << "\n";

    // std::vector<std::string> myVector;
    // myVector.push_back("safa");
    // myVector.push_back("barka");
    // myVector.push_back("Inas");
    // myVector.push_back("soukaina");
    // myVector.push_back("sara");

    // std::vector<std::string>::iterator myIt1 = myVector.begin();
    // std::vector<std::string>::iterator myIt2 = myIt1++;

    // std::cout <<  "myIt1 :" << *myIt1 << "\n";
    // std::cout << "myIt2 :"  << *myIt2 << "\n";

    // std::vector<std::string>::iterator myIt3 = ++myIt1;

    // std::cout <<  "myIt1 :" << *myIt1 << "\n";
    // std::cout << "myIt3 :"  << *myIt3 << "\n";
	// std::cout << "8 ---------------" << "\n";
	// {
	// 	std::vector<int> vect;
	// 	vect.push_back(10);
	// 	vect.push_back(11);
	// 	vect.push_back(43);
	// 	vect.push_back(66);
	// 	vect.push_back(90);
	// 	std::vector<int>::iterator it = vect.begin();
	// 	std::cout << *it <<"\n";
	// 	std::cout << it[0] <<"\n";
	// 	// a + n
	// 	std::vector<int>::iterator ret = it + 3;

	// 	std::cout << "*ret " << *ret << "\n";
	// 	std::cout << "*it " << *it << "\n";
	// 	// n + a
	// 	std::vector<int>::iterator ret3  = 1 + ret; 
	// 	std::cout << "*ret3 " << *ret3 << "\n";
	// 	std::cout << "*it " << *it << "\n";
	// 	// a - n
	// 	std::vector<int>::iterator ret4  = ret3 - 1; 
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
	// 	std::vector<int>::iterator p  = ret += 1; 
	// 	std::cout << "ret += 1 ==> " << *p << "\n";
	// 	std::cout << "ret ==> " << *ret << "\n";
	// 	// a -= n
	// 	std::vector<int>::iterator m = ret -= 1;
	// 	std::cout << "ret -= 1 ==> " << *m << "\n";
	// 	std::cout << "ret ==> " << *ret << "\n";

	// }

	// {
	// 	//test constuction reverse iterator
	// 	std::cout << "test constuction reverse iterator" << std::endl;
	// 	std::vector<int> myvector;
	// 	for (int i=0; i<10; i++) myvector.push_back(i);

	// 	typedef std::vector<int>::iterator iter_type;
	// 															// ? 0 1 2 3 4 5 6 7 8 9 ?
	// 	iter_type from (myvector.begin());                     //   ^
	// 															//         ------>
	// 	iter_type until (myvector.end());                      //                       ^
	// 															//
	// 	std::reverse_iterator<iter_type> rev_until (from);     // ^
	// 															//         <------
	// 	std::reverse_iterator<iter_type> rev_from (until);     //                     ^

	// 	std::cout << "myvector:";
	// 	while (rev_from != rev_until)
	// 		std::cout << ' ' << *rev_from++;
	// 	std::cout << '\n';
	// }
	{
		// comparing size, capacity and max_size
		std::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		std::cout << "size: " << myvector.size() << "\n";
		std::cout << "capacity: " << myvector.capacity() << "\n";
		std::cout << "max_size: " << myvector.max_size() << "\n";
	}

	{
		std::vector<int> myvector;

		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);
		std::cout << "size : " << myvector.size() << " capacity :" << myvector.capacity() << "\n"; 
		std::cout << "myvector contains:";
		for (int i=0;i<myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

	}
	{
		std::vector<int>::size_type sz;

		std::vector<int> foo;
		sz = foo.capacity();
		std::cout << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
			}
		}
	}

	{
		std::vector<int>::size_type sz;

		std::vector<int> foo;
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
				std::vector<int> bar;
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
		std::vector<int> myvector;
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
		try
		{
		
			std::vector<int> myvector (10);   // 10 zero-initialized ints

			// assign some values:
			for (unsigned i=0; i<myvector.size(); i++)
				myvector.at(i)=i;
			//	std::cout << "myvector contains:";
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
		std::vector<int> first;
		std::vector<int> second;
		std::vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		std::vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		std::cout << "Size of third: " << int (third.size()) << '\n';
	}

	{
		std::vector<int> myvector (3,100);
		std::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );

		myvector.insert (it + 2,5,300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		std::vector<int> anothervector (4,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);
		std::cout << *it << "\n";
		std::cout << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	{
		std::vector<int> myvector;
		std::vector<int>::iterator it;
		std::vector<int>::iterator it1;
		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		// erase the 6th element
		it = myvector.erase (myvector.begin()+5);
		std::cout << "iterator pointing to the new location " << *it << "\n";
		// // erase the first 3 elements:
		it1 = myvector.erase (myvector.begin(),myvector.begin()+3);
			std::cout << "it1 " << *it1 << "\n";

		std::cout << "myvector contains:";
		std::cout << myvector.size() << "\n";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}

	{
		std::cout << "swap vectors test\n";
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (5,200);   // five ints with a value of 200

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
		std::cout << "vector::get_allocator\n";
		std::vector<int> myvector;
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
}