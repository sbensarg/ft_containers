
#include "vector"
#include "iostream"


template <typename T>
void print_vector(const std::vector<T>& vector)
{
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << std::endl;
		std::cout << "-------------------" << std::endl;
}
int main()
{
	{
		std::vector<std::string> vec;
		std::vector<std::string> v;
		std::cout << v.capacity() << v.size() <<"\n"; 
		vec.push_back("chicky");
		vec.push_back("akira");
		vec.push_back("test");
		print_vector(vec);
		vec.pop_back();
		print_vector(vec);


		vec.push_back("test2");
		vec.push_back("test3");
		print_vector(vec);
		vec.clear();
		print_vector(vec);
		vec.push_back("test4");
		vec.push_back("test5");
		print_vector(vec);
	}

	//test iterator_traits
	typedef std::iterator_traits<int*> traits;
  	if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
    	std::cout << "int* is a random-access iterator\n";
	
	std::cout << "1 ---------------" << "\n";
    std::vector<int> vect;
    vect.push_back(13);
    vect.push_back(11);
    vect.push_back(3);
    std::cout << vect[0] << "\n";
    std::cout << vect[1] << "\n";
    std::cout << vect[2] << "\n";

    std::cout << "2 ---------------" << "\n";
    //test iterator

    std::vector<int>::iterator it = vect.begin();

    //test dereference
    std::cout << *it << "\n";

    //test post_increment a++
    it++;

    //test dereference
    std::cout << *it << "\n";

    it++;
    std::cout << *it << "\n";

     std::cout << "3 ---------------" << "\n";
    //create other vector

    std::vector<int> vect1;
    vect1.push_back(1);
    vect1.push_back(-5);

    std::vector<int>::iterator it1 = vect1.begin();

    std::cout << *it1 << "\n";
    std::cout << *it << "\n";

    //test assignement
    it = it1;
    std::cout << *it << "\n";

    it++;
    std::cout << *it << "\n";

    std::cout << "4 ---------------" << "\n";

    std::cout << *it1 << "\n";

    //test copy constructor
    std::vector<int>::iterator it2(it1);
    std::cout << *it2 << "\n";

    std::cout << "5 ---------------" << "\n";

    std::vector<int> vect2;
    vect2.push_back(100);
    vect2.push_back(200);
    vect2.push_back(300);

    std::vector<int>::iterator it3 = vect2.begin();

    int a = 3;
    a = *it3++;

    std::cout << "a : " << a << "\n";
    std::cout << "a : " << *it3 << "\n";

    std::cout << "6 ---------------" << "\n";
    //test pre-increment ++a

    ++it3;
    std::cout << *it3 << "\n";

    std::cout << "7 ---------------" << "\n";

    std::vector<std::string> myVector;
    myVector.push_back("safa");
    myVector.push_back("barka");
    myVector.push_back("Inas");
    myVector.push_back("soukaina");
    myVector.push_back("sara");

    std::vector<std::string>::iterator myIt1 = myVector.begin();
    std::vector<std::string>::iterator myIt2 = myIt1++;

    std::cout <<  "myIt1 :" << *myIt1 << "\n";
    std::cout << "myIt2 :"  << *myIt2 << "\n";

    std::vector<std::string>::iterator myIt3 = ++myIt1;

    std::cout <<  "myIt1 :" << *myIt1 << "\n";
    std::cout << "myIt3 :"  << *myIt3 << "\n";
	std::cout << "8 ---------------" << "\n";
	{
		std::vector<int> vect;
		vect.push_back(10);
		vect.push_back(11);
		vect.push_back(43);
		vect.push_back(66);
		vect.push_back(90);
		std::vector<int>::iterator it = vect.begin();
		std::cout << *it <<"\n";
		std::cout << it[0] <<"\n";
		// a + n
		std::vector<int>::iterator ret = it + 3;

		std::cout << "*ret " << *ret << "\n";
		std::cout << "*it " << *it << "\n";
		// n + a
		std::vector<int>::iterator ret3  = 1 + ret; 
		std::cout << "*ret3 " << *ret3 << "\n";
		std::cout << "*it " << *it << "\n";
		// a - n
		std::vector<int>::iterator ret4  = ret3 - 1; 
		std::cout << "*ret4 " << *ret4 << "\n";
		std::cout << "*it " << *it << "\n";
		// a - b
		int ret5  = ret4 - it; 
		std::cout << "*ret5 " << ret5 << "\n";
		std::cout << "*it " << *it << "\n";
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
		std::vector<int>::iterator p  = ret += 1; 
		std::cout << "ret += 1 ==> " << *p << "\n";
		std::cout << "ret ==> " << *ret << "\n";
		// a -= n
		std::vector<int>::iterator m = ret -= 1;
		std::cout << "ret -= 1 ==> " << *m << "\n";
		std::cout << "ret ==> " << *ret << "\n";

	}

	{
		//test constuction reverse iterator
		std::cout << "test constuction reverse iterator" << std::endl;
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
																// ? 0 1 2 3 4 5 6 7 8 9 ?
		iter_type from (myvector.begin());                     //   ^
																//         ------>
		iter_type until (myvector.end());                      //                       ^
																//
		std::reverse_iterator<iter_type> rev_until (from);     // ^
																//         <------
		std::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}
}