#include <vector>
#include <iostream>
#include "vector.hpp"

#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
#include "is_integral.hpp"
#include "enable_if.hpp"
#include "lexicographical_compare.hpp"
#include <iomanip> 
#include "AVLTree.hpp"

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))


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
// template < class T,
//            class = typename ft::enable_if<std::is_integral<T>::value>::type>
// bool is_even (T i) {return !bool(i%2);}
// a case-insensitive comparison function:
bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }
void vector_tests(void)
{
    std::cout << "\033[1;36m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< vector tests >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n";
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " fill constructor "
              << "] --------------------]\t\t\033[0m";
    {
        /*--------------- fill tow vectors with a 10 strings ------*/
        ft::vector<std::string> my_v(10, "fill constructor test");
        std::vector<std::string> v(10, "fill constructor test");
        /*---------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, my_res;
        /*---------------------------------------------------------*/
        for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) // fill res from std::vector
            res += *it;

        for (ft::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it) // fill my_res from ft::vector
            my_res += *it;
        EQUAL(res == my_res);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " range constructor "
              << "] --------------------]\t\t\033[0m";
    {
        /*--------------- fill std::vector with 10 strings and ft::vector with range of iterators ------*/
        std::vector<std::string> v(10, "range constructor test");
        ft::vector<std::string> my_v(10, "range constructor test");
        ft::vector<std::string> my_v1(my_v.begin(), my_v.end()); // this one is to check if the range works with ft::vector
        /*----------------------------------------------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, my_res, my_res1;
        /*--------------------------------------------------------*/
        for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) // fill res from std::vector
            res += *it;

        for (ft::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it) // fill my_res from ft::vector
            my_res += *it;

        for (ft::vector<std::string>::iterator it = my_v1.begin(); it != my_v1.end(); ++it) // fill my_res1 from ft::vector
            my_res1 += *it;
        EQUAL(res == my_res && my_res == my_res1);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor "
              << "] --------------------]\t\t\033[0m";
    {
        /*---------------------------- declare a vector and fill with 'a', and create a copy of it ------------------*/
        ft::vector<char> v1(10, 'a');
        ft::vector<char> copy_v(v1);
        /*-----------------------------------------------------------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, res1;
        /*--------------------------------------------------------*/
        for (ft::vector<char>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for (ft::vector<char>::iterator it = copy_v.begin(); it != copy_v.end(); ++it) // fill res from copy_v
            res1 += *it;
        EQUAL(res == res1);
    }
    /*------------------------------------------ = operator tests --------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 1 : test with equale size vecotrs ----------------------------------------------------------------------*/
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (lhs.size = rhs.size) "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string1");
        std::vector<std::string> v2(10, "string2");
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string1");
        ft::vector<std::string> ft_v2(10, "string2");
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

        EQUAL(res == ft_res);
    }
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 2 : test with diff size vecotrs ----------------------------------------------------------------------*/
   std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (lhs.size < rhs.size) "
             << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string1");
        std::vector<std::string> v2(20, "string2");
        v1 = v2;
	//	std::cout << "size v1 " << v1.size() << "\n";
	//	std::cout << "size v2 " << v2.size() << "\n";
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string1");
        ft::vector<std::string> ft_v2(20, "string2");
        ft_v1 = ft_v2;
		//std::cout << "size ft_v1 " << ft_v1.size() << "\n";
		//std::cout << "size ft_v2 " << ft_v2.size() << "\n";
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

		//std::cout << "size ft_v1 " << res.size() << "\n";
		//std::cout << "size ft_v2 " << ft_res.size() << "\n";

        EQUAL(res == ft_res);
    }
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 3 : test with diff size vecotrs ----------------------------------------------------------------------*/
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (lhs.size > rhs.size) "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(20, "string1");
        std::vector<std::string> v2(10, "string2");
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(20, "string1");
        ft::vector<std::string> ft_v2(10, "string2");
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

        EQUAL(res == ft_res);
    }
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 4 : test with one empty vector ----------------------------------------------------------------------*/
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (lhs.size = 0) "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1;
        std::vector<std::string> v2(10, "string2");
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1;
        ft::vector<std::string> ft_v2(10, "string2");
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

        EQUAL(res == ft_res);
    }
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 5 : test with one empty vector ----------------------------------------------------------------------*/
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (rhs.size = 0) "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");
        std::vector<std::string> v2;
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<std::string> ft_v2;
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

        EQUAL(res == ft_res);
    }
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " begin and end methods "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");
        std::vector<std::string> const v2(10, "string2");
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<std::string> const ft_v2(10, "string2");
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res, c_res, c_ft_res;
        /*----------------------------------------------------*/
        for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;
        for (std::vector<std::string>::const_iterator rit = v2.begin(); rit != v2.end(); ++rit) // fill c_res from const v1
            c_res += *rit;

        for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;
        for (ft::vector<std::string>::const_iterator rit = ft_v2.begin(); rit != ft_v2.end(); ++rit) // fill c_ft_res from const ft_v1
            c_ft_res += *rit;

        EQUAL(res == ft_res && c_res == c_ft_res);
    }
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rbegin and rend methods "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");
        std::vector<std::string> const v2(10, "string2");
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<std::string> const ft_v2(10, "string2");
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res, c_res, c_ft_res;
        /*----------------------------------------------------*/
        for (std::vector<std::string>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); ++rit) // fill res from v1
            res += *rit;
        for (std::vector<std::string>::const_reverse_iterator rit = v2.rbegin(); rit != v2.rend(); ++rit) // fill c_res from const v1
            c_res += *rit;

        for (ft::vector<std::string>::reverse_iterator rit = ft_v1.rbegin(); rit != ft_v1.rend(); ++rit) // fill ft_res from ft_v1
            ft_res += *rit;
        for (ft::vector<std::string>::const_reverse_iterator rit = ft_v2.rbegin(); rit != ft_v2.rend(); ++rit) // fill c_ft_res from const ft_v1
            c_ft_res += *rit;

        EQUAL(res == ft_res && c_ft_res == c_res);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " size method "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");          // fill constructor
        std::vector<std::string> v2;                         // empty constructor
        std::vector<std::string> v3(v1.begin(), v1.end());   // range constructor with normal iterators
        std::vector<std::string> v4(v3);                     // copy constructor
        std::vector<std::string> v5(v1.rbegin(), v1.rend()); // range constructor with reverse iterators
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<std::string> ft_v2;
        ft::vector<std::string> ft_v3(ft_v1.begin(), ft_v1.end());
        ft::vector<std::string> ft_v4(ft_v1);
        ft::vector<std::string> ft_v5(ft_v1.rbegin(), ft_v1.rend());
        /*----------------------------------------------------*/
        EQUAL(v1.size() == ft_v1.size() && v2.size() == ft_v2.size() && v3.size() == ft_v3.size() && v4.size() == ft_v4.size() && v5.size() == ft_v5.size());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " capacity method "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");          // fill constructor
        std::vector<std::string> v2;                         // empty constructor
        std::vector<std::string> v3(v1.begin(), v1.end());   // range constructor with normal iterators
        std::vector<std::string> v4(v3);                     // copy constructor
        std::vector<std::string> v5(v1.rbegin(), v1.rend()); // range constructor with reverse iterators
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<std::string> ft_v2;
        ft::vector<std::string> ft_v3(ft_v1.begin(), ft_v1.end());
        ft::vector<std::string> ft_v4(ft_v1);
        ft::vector<std::string> ft_v5(ft_v1.rbegin(), ft_v1.rend());
        /*----------------------------------------------------*/
        EQUAL(v1.capacity() == ft_v1.capacity() && v2.capacity() == ft_v2.capacity() && v3.capacity() == ft_v3.capacity() && v4.capacity() == ft_v4.capacity() && v5.capacity() == ft_v5.capacity());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " max_size method "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/

        std::vector<std::string> v1(10, "string");
        std::vector<int> v2;
        std::vector<double> v4;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<int> ft_v2;
        ft::vector<double> ft_v4;
        /*----------------------------------------------------*/
        EQUAL(v1.max_size() == ft_v1.max_size() && v2.max_size() == ft_v2.max_size() && v4.max_size() == ft_v4.max_size());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " resize method "
              << "] --------------------]\t\t\033[0m";
    {
        /*
         * Strings to store the results
         */
        std::string s1, s2, s3, s4, ft_s1, ft_s2, ft_s3, ft_s4;
        std::string sit1, sit2, sit3, ft_sit1, ft_sit2, ft_sit3; // strings to store the result by iterators
        /*
         * Var to store the size and the capacity
         */
        size_t z1, z2, z3, z4, ft_z1, ft_z2, ft_z3, ft_z4;
        size_t c1, c2, c3, c4, ft_c1, ft_c2, ft_c3, ft_c4;
        /*
         * iterators to check the iterator validity
         *  it : iterator, eit : iterator to the end
         */
        std::vector<std::string>::iterator valid_it, valid_eit;
        ft::vector<std::string>::iterator ft_valid_it, ft_valid_eit;
        /*
         * test with n greater than vector capacity
         */
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");
        v1.resize(1e6, "hello");
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft_v1.resize(1e6, "hello");

        z1 = v1.size();
        ft_z1 = ft_v1.size();
        c1 = v1.capacity();
        ft_c1 = ft_v1.capacity();
        for (size_t i = 0; i < v1.size(); ++i)
            s1 += v1[i];

        for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
            ft_s1 += *it;
        /*----------------------------------------------------*/
        /*
         *	test with n lesser than capacity and greater than size
         */
        /*------------------ std::vectors ---------------------*/
        v1.resize(20);
        valid_it = v1.begin();
        valid_eit = v1.end();
        v1.resize(1e5);
        /*------------------ ft::vectors ---------------------*/
        ft_v1.resize(20);
        ft_valid_it = ft_v1.begin();
        ft_valid_eit = ft_v1.end();
        ft_v1.resize(1e5);
        ft_valid_eit = ft_v1.end();
        ft_valid_it = ft_v1.begin();

        z2 = v1.size();
        ft_z2 = ft_v1.size();
        c2 = v1.capacity();
        ft_c2 = ft_v1.capacity();
        for (size_t i = 0; i < v1.size(); ++i)
            s2 += v1[i];

        for (; valid_it != valid_eit; ++valid_it)
            sit1 += *valid_it;

        for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
            ft_s2 += *it;

        for (; ft_valid_it != ft_valid_eit; ++ft_valid_it)
            ft_sit1 += *ft_valid_it;
        /*----------------------------------------------------*/
        /*
         * test with n lesser than capacity and lesser an size
         */
        /*------------------ std::vectors ---------------------*/
        valid_it = v1.begin();
        v1.resize(50);
        /*------------------ ft::vectors ---------------------*/
        ft_valid_it = ft_v1.begin();
        ft_v1.resize(50);

        ft_valid_it = ft_v1.begin();
        z3 = v1.size();
        ft_z3 = ft_v1.size();
        c3 = v1.capacity();
        ft_c3 = ft_v1.capacity();
        for (size_t i = 0; i < v1.size(); ++i)
            s3 += v1[i];

        for (; valid_it != v1.end(); ++valid_it)
            sit2 += *valid_it;

        for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
            ft_s3 += *it;

        for (; ft_valid_it != ft_v1.end(); ++ft_valid_it)
            ft_sit2 += *ft_valid_it;
        /*----------------------------------------------------*/
        /*
         * test with n = 0
         */
        /*------------------ std::vectors ---------------------*/
        valid_it = v1.begin();
        v1.resize(0, "string4");
        /*------------------ ft::vectors ---------------------*/
        ft_valid_it = ft_v1.begin();
        ft_v1.resize(0, "string4");

        z4 = v1.size();
        ft_z4 = ft_v1.size();
        c4 = v1.capacity();
        ft_c4 = ft_v1.capacity();
        for (size_t i = 0; i < v1.size(); ++i)
            s4 += v1[i];

        for (; valid_it != v1.end(); ++valid_it)
            sit3 += *valid_it;

        for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
            ft_s4 += *it;

        for (; ft_valid_it != ft_v1.end(); ++ft_valid_it)
            ft_sit3 += *ft_valid_it;
        /*----------------------------------------------------*/
        EQUAL((s1 == ft_s1 && z1 == ft_z1 && c1 == ft_c1 && sit1 == ft_sit1) && (s2 == ft_s2 && z2 == ft_z2 && c2 == ft_c2) && (s3 == ft_s3 && z3 == ft_z3 && c3 == ft_c3 && sit2 == ft_sit2) && (s4 == ft_s4 && z4 == ft_z4 && c4 == ft_c4 && sit3 == ft_sit3));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " empty method "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");
        std::vector<int> v2;
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<int> ft_v2;

        EQUAL(v1.empty() == ft_v1.empty() && v2.empty() == ft_v2.empty());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " reserve method "
              << "] --------------------]\t\t\033[0m";
    {
        /*
         * Strings to store the results
         */
        std::string s1, s2, s3, ft_s1, ft_s2, ft_s3;
        std::string sit1, ft_sit1; // strings to store the result by iterators
        /*
         * Var to store the size and the capacity
         */
        size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
        size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
        /*
         * iterators to check the iterator validity
         *  it : iterator, eit : iterator to the end
         */
        std::vector<std::string>::iterator valid_it, valid_eit;
        ft::vector<std::string>::iterator ft_valid_it, ft_valid_eit;
        // bool to check if the function throw or not
        bool exec_throwed = false;
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");
        std::vector<char> v2;
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<char> ft_v2;
        try
        {
            ft_v1.reserve(ft_v1.max_size() + 1);
        }
        catch (std::length_error const &e)
        {
            (void)e;
            exec_throwed = true;
        }
        v1.reserve(100);
        ft_v1.reserve(100);

        z1 = v1.size();
        ft_z1 = ft_v1.size();
        c1 = v1.capacity();
        ft_c1 = ft_v1.capacity();

        for (size_t i = 0; i < v1.size(); ++i)
            s1 += v1[i];

        ft_valid_it = ft_v1.begin();
        for (; ft_valid_it != ft_v1.end(); ++ft_valid_it)
            ft_s1 += *ft_valid_it;

        valid_it = v1.begin();
        valid_eit = v1.end();
        ft_valid_it = ft_v1.begin();
        ft_valid_eit = ft_v1.end();
        v1.reserve(50);
        ft_v1.reserve(50);

        z2 = v1.size();
        ft_z2 = ft_v1.size();
        c2 = v1.capacity();
        ft_c2 = ft_v1.capacity();

        for (size_t i = 0; i < v1.size(); ++i)
            s2 += v1[i];

        for (; valid_it != valid_eit; ++valid_it)
            sit1 += *valid_it;

        for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
            ft_s2 += *it;

        for (; ft_valid_it != ft_valid_eit; ++ft_valid_it)
            ft_sit1 += *ft_valid_it;

        v2.reserve(200);
        ft_v2.reserve(200);
        z3 = v2.size();
        ft_z3 = ft_v2.size();
        c3 = v2.capacity();
        ft_c3 = ft_v2.capacity();

        for (size_t i = 0; i < v2.size(); ++i)
            s3 += v2[i];

        for (ft::vector<char>::iterator it = ft_v2.begin(); it != ft_v2.end(); ++it)
            ft_s3 += *it;

        EQUAL((s1 == ft_s1 && z1 == ft_z1 && c1 == ft_c1 && sit1 == ft_sit1) && (s2 == ft_s2 && z2 == ft_z2 && c2 == ft_c2) && (s3 == ft_s3 && z3 == ft_z3 && c3 == ft_c3) && exec_throwed);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator[] method "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");
        std::vector<char> const v2(10, '9');
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<char> const ft_v2(10, '9');
        /*
         * Strings to store the results
         */
        std::string s1, s2, ft_s1, ft_s2;

        for (size_t i = 0; i < v1.size(); ++i)
        {
            if (i == v1.size() - 1)
                v1[i] = "other";
            s1 += v1[i];
        }

        for (size_t i = 0; i < ft_v1.size(); ++i)
        {
            if (i == ft_v1.size() - 1)
                ft_v1[i] = "other";
            ft_s1 += ft_v1[i];
        }

        for (size_t i = 0; i < v2.size(); ++i)
            s2 += v2[i];

        for (size_t i = 0; i < ft_v2.size(); ++i)
            ft_s2 += ft_v2[i];

        EQUAL(s1 == ft_s1 && s2 == ft_s2);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " at method "
              << "] --------------------]\t\t\033[0m";
    {
        
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");
        std::vector<char> const v2(10, '9');
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<char> const ft_v2(10, '9');
        /*
         * Strings to store the results
         */
        std::string s1, s2, ft_s1, ft_s2;
        // bool to check if an exception is throwed
        bool exce_throwed = false;

        try
        {
            ft_v1.at(20);
        }
        catch (std::out_of_range const &e)
        {
            (void)e;
            exce_throwed = true;
        }
        for (size_t i = 0; i < v1.size(); ++i)
        {
            if (i == v1.size() - 1)
                v1.at(i) = "other";
            s1 += v1.at(i);
        }

        for (size_t i = 0; i < ft_v1.size(); ++i)
        {
            if (i == ft_v1.size() - 1)
                ft_v1.at(i) = "other";
            ft_s1 += ft_v1.at(i);
        }

        for (size_t i = 0; i < v2.size(); ++i)
            s2 += v2.at(i);
        for (size_t i = 0; i < ft_v2.size(); ++i)
            ft_s2 += ft_v2.at(i);

        EQUAL(s1 == ft_s1 && s2 == ft_s2 && exce_throwed);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " front method "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");
        std::vector<int> const v2(10, 9);
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<int> const ft_v2(10, 9);

        v1.front() = "LEET";
        ft_v1.front() = "LEET";
        EQUAL(v1.front() == ft_v1.front() && v2.front() == ft_v2.front());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " back method "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");
        std::vector<int> const v2(10, 9);
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<int> const ft_v2(10, 9);

        v1.back() = "LEET";
        ft_v1.back() = "LEET";
        EQUAL(v1.back() == ft_v1.back() && v2.back() == ft_v2.back());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " assign(fill) method "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");
        std::vector<char> v2;
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<char> ft_v2;
        /*
         * Strings to store the results
         */
        std::string s1, s2, s3, ft_s1, ft_s2, ft_s3;
        /*
         * Var to store the size and the capacity
         */
        size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
        size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
        // test for n greater than the vector capactiy
        v1.assign(20, "assign");
        ft_v1.assign(20, "assign");

        z1 = v1.size();
        ft_z1 = ft_v1.size();
        c1 = v1.capacity();
        ft_c1 = ft_v1.capacity();
        for (size_t i = 0; i < v1.size(); ++i)
            s1 += v1.at(i);

        for (size_t i = 0; i < ft_v1.size(); ++i)
            ft_s1 += ft_v1.at(i);
        // test for n lesser than the vector capactiy
        v1.assign(10, "less");
        ft_v1.assign(10, "less");

        z2 = v1.size();
        ft_z2 = ft_v1.size();
        c2 = v1.capacity();
        ft_c2 = ft_v1.capacity();
        for (size_t i = 0; i < v1.size(); ++i)
            s3 += v1.at(i);

        for (size_t i = 0; i < ft_v1.size(); ++i)
            ft_s3 += ft_v1.at(i);
        // test for empty vectors
        v2.assign(20, 'h');
        ft_v2.assign(20, 'h');

        z3 = v2.size();
        ft_z3 = ft_v2.size();
        c3 = v2.capacity();
        ft_c3 = ft_v2.capacity();
        for (size_t i = 0; i < v2.size(); ++i)
            s2 += v2.at(i);

        for (size_t i = 0; i < ft_v2.size(); ++i)
            ft_s2 += ft_v2.at(i);

        EQUAL((s1 == ft_s1 && z1 == ft_z1 && c1 == ft_c1) && (s2 == ft_s2 && z2 == ft_z2 && c2 == ft_c2) && (s3 == ft_s3 && z3 == ft_z3 && c3 == ft_c3));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " assign(range) method "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(20, "less");
        std::vector<std::string> v2;
        std::vector<std::string> v3(10, "string2");
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string> ft_v1(20, "less");
        ft::vector<std::string> ft_v2;
        ft::vector<std::string> ft_v3(10, "string2");
        /*
         * Strings to store the results
         */
        std::string s1, s2, s3, ft_s1, ft_s2, ft_s3;
        /*
         * Var to store the size and the capacity
         */
        size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
        size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
        // test for n greater than the vector capactiy
        v3.assign(v1.begin(), v1.end());
        ft_v3.assign(v1.begin(), v1.end());

        z1 = v3.size();
        c1 = v3.capacity();
        ft_z1 = ft_v3.size();
        ft_c1 = ft_v3.capacity();
        for (size_t i = 0; i < v3.size(); ++i)
            s1 += v3.at(i);

        for (size_t i = 0; i < ft_v3.size(); ++i)
            ft_s1 += ft_v3.at(i);
        // test for n lesser than the vector capactiy
        v1.assign(v3.begin(), v3.end());
        ft_v1.assign(ft_v3.begin(), ft_v3.end());

        z2 = v1.size();
        c2 = v1.capacity();
        ft_z2 = ft_v1.size();
        ft_c2 = ft_v1.capacity();
        for (size_t i = 0; i < v1.size(); ++i)
            s3 += v1.at(i);

        for (size_t i = 0; i < ft_v1.size(); ++i)
            ft_s3 += ft_v1.at(i);
        // test for empty vectors
        v2.assign(v1.begin(), v1.end());
        ft_v2.assign(ft_v1.begin(), ft_v1.end());

        z3 = v2.size();
        c3 = v2.capacity();
        ft_z3 = ft_v2.size();
        ft_c3 = ft_v2.capacity();
        for (size_t i = 0; i < v2.size(); ++i)
            s2 += v2.at(i);

        for (size_t i = 0; i < ft_v2.size(); ++i)
            ft_s2 += ft_v2.at(i);

        EQUAL((s1 == ft_s1 && z1 == ft_z1 && c1 == ft_c1) && (s2 == ft_s2 && z2 == ft_z2 && c2 == ft_c2) && (s3 == ft_s3 && z3 == ft_z3 && c3 == ft_c3));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " push_back method "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v;
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string> ft_v;
        /*
         * Strings to store the results
         */
        std::string s1, s2, s3, ft_s1, ft_s2, ft_s3;
        /*
         * Var to store the size and the capacity
         */
        size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
        size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
        ft::vector<std::string>::iterator ft_it;
        // test for an empty vector
        v.push_back("hello");
        ft_v.push_back("hello");
        ft_it = ft_v.begin();
        ft_it->length();

        z1 = v.size();
        c1 = v.capacity();
        ft_z1 = ft_v.size();
        ft_c1 = ft_v.capacity();
        for (size_t i = 0; i < v.size(); ++i)
            s1 += v.at(i);

        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_s1 += ft_v.at(i);
        /*---------------------------------------------*/
        // test for a vector with capacity >= size + the new element
        v.reserve(30);
        ft_v.reserve(30);
        v.push_back("string");
        ft_v.push_back("string");
        v.push_back("string");
        ft_v.push_back("string");

        z2 = v.size();
        c2 = v.capacity();
        ft_z2 = ft_v.size();
        ft_c2 = ft_v.capacity();
        for (size_t i = 0; i < v.size(); ++i)
            s2 += v.at(i);

        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_s2 += ft_v.at(i);
        /*---------------------------------------------------------*/
        // test for a vector with capactiy < size + the new element
        for (size_t i = 0; i < 100; ++i)
            v.push_back("string");

        for (size_t i = 0; i < 100; ++i)
            ft_v.push_back("string");

        z3 = v.size();
        c3 = v.capacity();
        ft_z3 = ft_v.size();
        ft_c3 = ft_v.capacity();
        for (size_t i = 0; i < v.size(); ++i)
            s3 += v.at(i);

        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_s3 += ft_v.at(i);

        EQUAL((s1 == ft_s1 && z1 == ft_z1 && c1 == ft_c1) && (s2 == ft_s2 && z2 == ft_z2 && c2 == ft_c2) && (s3 == ft_s3 && z3 == ft_z3 && c3 == ft_c3));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " pop_back method "
              << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v(20, "string");
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string> ft_v(20, "string");
        /*
         * Strings to store the results
         */
        std::string s1, ft_s1;
        /*
         * Var to store the size and the capacity
         */
        size_t z1, ft_z1;
        size_t c1, ft_c1;
        v.pop_back();
        ft_v.pop_back();
        z1 = v.size();
        ft_z1 = ft_v.size();
        c1 = v.capacity();
        ft_c1 = ft_v.capacity();
        for (size_t i = 0; i < v.size(); ++i)
            s1 += v[i];
        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_s1 += ft_v[i];
        EQUAL(z1 == ft_z1 && c1 == ft_c1 && s1 == ft_s1);
    }
   std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " insert method (single element) "
             << "] --------------------]\t\t\033[0m";
    {
        /*
         * strings to store the resutls
         */
        std::string str, ft_str;
        /*
         * var to store the size and the capacity
         */
        ft::vector<std::string>::size_type s, ft_s;
        ft::vector<std::string>::size_type c, ft_c;
        ft::vector<std::string>::iterator ft_it;
        std::vector<std::string>::iterator it;
        /*
         * bool to store the comparison
         */
        bool cond;

        /*------------------------------- test 1: empty vector ----------------------------------------*/
        // insert at the begin
        {
            std::vector<std::string> v;
            ft::vector<std::string> ft_v;
            it = v.insert(v.begin(), "hello");
            ft_it = ft_v.insert(ft_v.begin(), "hello");
            ft_it->length();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            //std::cout << "size " << s << " capacity " << c << *it << "\n";
          //  std::cout << "ft::size " << ft_s << " ft::capacity " << ft_c << "\n";
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = ((str == ft_str) && (s == ft_s) && (c == ft_c) && (*ft_it == *it));
        }
        // insert at the end
        {
            std::vector<std::string> v;
            ft::vector<std::string> ft_v;

            it = v.insert(v.end(), "hello");
            ft_it = ft_v.insert(ft_v.end(), "hello");
            ft_it->length();

            str.clear();
            ft_str.clear();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it));
        }
        /*---------------------------------------------------------------------------------------------------*/
        /*------------------------------- test 2: the vector capacity >= size + the new element ----------------------------------------*/
        {
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");
            ft::vector<std::string>::iterator valid_it;

            v.reserve(30);
            ft_v.reserve(30);
            valid_it = ft_v.begin();
            it = v.insert(v.begin() + 10, "hello");
            ft_it = ft_v.insert(ft_v.begin() + 10, "hello");
            ft_it->length();

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it) && (&(*valid_it) == &(*ft_v.begin())));
        }
        /*---------------------------------------------------------------------------------------------------*/
        /*------------------------------- test 3: the vector capacity < size + the new element ----------------------------------------*/
        {
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");

            it = v.insert(v.begin() + 10, "hello");
            ft_it = ft_v.insert(ft_v.begin() + 10, "hello");
            ft_it->length();

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it));
        }
        /*---------------------------------------------------------------------------------------------------*/
        EQUAL(cond);
   }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " insert method (fill) "
              << "] --------------------]\t\t\033[0m";
    {
        /*
         * strings to store the resutls
         */
        std::string str, ft_str;
        /*
         * var to store the size and the capacity
         */
        ft::vector<std::string>::size_type s, ft_s;
        ft::vector<std::string>::size_type c, ft_c;
        /*
         * bool to store the comparison
         */
        bool cond;

        /*------------------------------- test 1: empty vector ----------------------------------------*/
        // insert at the begin
        {
            std::vector<std::string> v;
            ft::vector<std::string> ft_v;
            v.insert(v.begin(), 100, "hello");
            ft_v.insert(ft_v.begin(), 100, "hello");
            ft_v.begin()->length();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            //std::cout << "size " << s << " capacity " << c  << "\n";
            //std::cout << "ft::size " << ft_s << " ft::capacity " << ft_c << "\n";
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        // insert at the end
        {
            std::vector<std::string> v;
            ft::vector<std::string> ft_v;

            v.insert(v.end(), "hello");
            ft_v.insert(ft_v.end(), "hello");
            ft_v.begin()->length();

            str.clear();
            ft_str.clear();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        // /*---------------------------------------------------------------------------------------------------*/
        // /*------------------------------- test 2: the vector capacity >= size + n ----------------------------------------*/
        {
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");
            ft::vector<std::string>::iterator valid_it;

            v.reserve(100);
            ft_v.reserve(100);
            valid_it = ft_v.begin();
            v.insert(v.begin() + 15, 70, "hello");
            ft_v.insert(ft_v.begin() + 15, 70, "hello");

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (&(*valid_it) == &(*ft_v.begin())));
        }
        // /*---------------------------------------------------------------------------------------------------*/
        // /*------------------------------- test 3: the vector capacity < size + n && n > size ----------------------------------------*/
        {
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");

            v.insert(v.begin() + 10, 100, "hello");
            ft_v.insert(ft_v.begin() + 10, 100, "hello");

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        // /*---------------------------------------------------------------------------------------------------*/
        // /*------------------------------- test 4: the vector capacity < size + n && n <= size ----------------------------------------*/
        {
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");

            v.insert(v.begin() + 10, 15, "hello");
            ft_v.insert(ft_v.begin() + 10, 15, "hello");

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        // /*---------------------------------------------------------------------------------------------------*/
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " insert method (range) "
              << "] --------------------]\t\t\033[0m";
    {
        /*
         * strings to store the resutls
         */
        std::string str, ft_str;
        /*
         * var to store the size and the capacity
         */
        ft::vector<std::string>::size_type s, ft_s;
        ft::vector<std::string>::size_type c, ft_c;
        /*
         * bool to store the comparison
         */
        bool cond;

        /*------------------------------- test 1: empty vector ----------------------------------------*/
        // insert at the begin
        {
            std::vector<std::string> v1(300, "string");
            std::vector<std::string> v;
            ft::vector<std::string> ft_v;
            v.insert(v.begin(), v1.begin(), v1.end());
            ft_v.insert(ft_v.begin(), v1.begin(), v1.end());
            ft_v.begin()->length();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        // insert at the end
        {
            std::vector<std::string> v;
            ft::vector<std::string> v1(300, "string");
            ft::vector<std::string> ft_v;

            v.insert(v.end(), v1.begin(), v1.end());
            ft_v.insert(ft_v.end(), v1.begin(), v1.end());
            ft_v.begin()->length();

            str.clear();
            ft_str.clear();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        /*---------------------------------------------------------------------------------------------------*/
        /*------------------------------- test 2: the vector capacity >= size + n ----------------------------------------*/
        {
            std::vector<std::string> v1(70, "hello");
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");
            ft::vector<std::string>::iterator valid_it;

            v.reserve(100);
            ft_v.reserve(100);
            valid_it = ft_v.begin();
            v.insert(v.begin() + 15, v1.begin(), v1.end());
            ft_v.insert(ft_v.begin() + 15, v1.begin(), v1.end());

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (&(*valid_it) == &(*ft_v.begin())));
        }
        /*---------------------------------------------------------------------------------------------------*/
        /*------------------------------- test 3: the vector capacity < size + n && n > size ----------------------------------------*/
        {
            ft::vector<std::string> v1(100, "hello");
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");

            v.insert(v.begin() + 10, v1.begin(), v1.end());
            ft_v.insert(ft_v.begin() + 10, v1.begin(), v1.end());

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        /*---------------------------------------------------------------------------------------------------*/
        /*------------------------------- test 4: the vector capacity < size + n && n <= size ----------------------------------------*/
        {
            std::vector<std::string> v1(15, "hello");
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");

            v.insert(v.begin() + 10, v1.begin(), v1.end());
            ft_v.insert(ft_v.begin() + 10, v1.begin(), v1.end());

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        /*---------------------------------------------------------------------------------------------------*/
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " erase method (single element) "
              << "] --------------------]\t\t\033[0m";
    {
        /*
         * strings to store the resutls
         */
        std::string str, ft_str;
        /*
         * var to store the size and the capacity
         */
        ft::vector<std::string>::size_type s, ft_s;
        ft::vector<std::string>::size_type c, ft_c;
        /*
         * bool to store the comparison
         */
        bool cond;

        std::vector<std::string> v(200, "hello");
        ft::vector<std::string> ft_v(200, "hello");
        ft::vector<std::string>::iterator valid_it;
        std::vector<std::string>::iterator it;
        ft::vector<std::string>::iterator ft_it;
        valid_it = ft_v.begin() + 99;
        it = v.erase(v.begin() + 100);
        ft_it = ft_v.erase(ft_v.begin() + 100);
        ft_it->length();

        s = v.size();
        ft_s = ft_v.size();
        c = v.capacity();
        ft_c = ft_v.capacity();
        for (size_t i = 0; i < v.size(); ++i)
            str += v[i];
        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_str += ft_v[i];
        cond = ((str == ft_str) && (s == ft_s) && (c == ft_c) && (&(*valid_it) == &(*(ft_v.begin() + 99))));
        cond = (cond && (std::distance(v.begin(), it) == std::distance(ft_v.begin(), ft_it)));
        EQUAL(cond);
    }

    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " erase method (range) "
              << "] --------------------]\t\t\033[0m";
    {
        /*
         * strings to store the resutls
         */
        std::string str, ft_str;
        /*
         * var to store the size and the capacity
         */
        ft::vector<std::string>::size_type s, ft_s;
        ft::vector<std::string>::size_type c, ft_c;
        std::vector<std::string>::iterator it;
        ft::vector<std::string>::iterator ft_it;
        /*
         * bool to store the comparison
         */
        bool cond;
        /*------------------ test 1: erase from the begin to end -------------------*/
        {
            std::vector<std::string> v(100, "hello");
            ft::vector<std::string> ft_v(100, "hello");

            it = v.erase(v.begin(), v.end());
            ft_it = ft_v.erase(ft_v.begin(), ft_v.end());

            s = v.size();
            ft_s = ft_v.size();
            c = v.size();
            ft_c = ft_v.size();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
            cond = (cond && (std::distance(v.begin(), it) == std::distance(ft_v.begin(), ft_it)));
        }

        /*--------------------------------------------------------------------------*/
        /*------------------ test 2: erase from the begin to begin + 70 -------------------*/
        {
            std::vector<std::string> v(100, "hello");
            ft::vector<std::string> ft_v(100, "hello");

            it = v.erase(v.begin(), v.begin() + 70);
            ft_it = ft_v.erase(ft_v.begin(), ft_v.begin() + 70);
            ft_it->length();

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.size();
            ft_c = ft_v.size();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            cond = (cond && (std::distance(v.begin(), it) == std::distance(ft_v.begin(), ft_it)));
        }
        /*--------------------------------------------------------------------------*/
        /*------------------ test 3: erase from the begin + 60 to end -------------------*/

        {
            std::vector<std::string> v(100, "hello");
            ft::vector<std::string> ft_v(100, "hello");

            it = v.erase(v.begin() + 60, v.end());
            ft_it = ft_v.erase(ft_v.begin() + 60, ft_v.end());

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.size();
            ft_c = ft_v.size();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            cond = (cond && (std::distance(v.begin(), it) == std::distance(ft_v.begin(), ft_it)));
        }

        /*--------------------------------------------------------------------------*/
        /*------------------ test 4: erase from the begin + 20 to end - 30 -------------------*/
        {
            std::vector<std::string> v(100, "hello");
            ft::vector<std::string> ft_v(100, "hello");

            it = v.erase(v.begin() + 20, v.end() - 30);
            ft_it = ft_v.erase(ft_v.begin() + 20, ft_v.end() - 30);
            ft_it->length();

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.size();
            ft_c = ft_v.size();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            cond = (cond && (std::distance(v.begin(), it) == std::distance(ft_v.begin(), ft_it)));
        }
        /*--------------------------------------------------------------------------*/
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " swap method "
              << "] --------------------]\t\t\033[0m";
    {
        /*
         * strings to store the resutls
         */
        std::string str, ft_str;
        /*
         * var to store the size and the capacity
         */
        ft::vector<std::string>::size_type s, ft_s;
        ft::vector<std::string>::size_type c, ft_c;
        ft::vector<std::string>::iterator b1, b2;
        /*
         * bool to store the comparison
         */
        bool cond;

        /*---------------------------------- test 1: equal size vectors ----------------------*/
        {
            std::vector<std::string> v(200, "hello");
            std::vector<std::string> v1(200, "string");
            ft::vector<std::string> ft_v(200, "hello");
            ft::vector<std::string> ft_v1(200, "string");

            b1 = ft_v.begin();
            b2 = ft_v1.begin();

            v.swap(v1);
            ft_v.swap(ft_v1);

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];

            cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
            cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
            cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
        }
        /*--------------------------------------------------------------------------------------------*/
        /*---------------------------------- test 2: lhs > rhs ----------------------*/
        {
            std::vector<std::string> v(200, "hello");
            std::vector<std::string> v1(50, "string");
            ft::vector<std::string> ft_v(200, "hello");
            ft::vector<std::string> ft_v1(50, "string");

            b1 = ft_v.begin();
            b2 = ft_v1.begin();

            v.swap(v1);
            ft_v.swap(ft_v1);

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];

            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
            cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
        }
        /*--------------------------------------------------------------------------------------------*/
        /*---------------------------------- test 2: lhs < rhs ----------------------*/
        {
            std::vector<std::string> v(50, "hello");
            std::vector<std::string> v1(200, "string");
            ft::vector<std::string> ft_v(50, "hello");
            ft::vector<std::string> ft_v1(200, "string");

            b1 = ft_v.begin();
            b2 = ft_v1.begin();

            v.swap(v1);
            ft_v.swap(ft_v1);

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];

            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
            cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
        }
        /*--------------------------------------------------------------------------------------------*/
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " clear method "
              << "] --------------------]\t\t\033[0m";
    {
        /*
         * strings to store the resutls
         */
        std::string str, ft_str;
        /*
         * var to store the size and the capacity
         */
        ft::vector<std::string>::size_type s, ft_s;
        ft::vector<std::string>::size_type c, ft_c;
        /*
         * bool to store the comparison
         */
        bool cond;

        /*---------------------------------- test 1: equal size vectors ----------------------*/
        {
            std::vector<std::string> v(200, "hello");
            ft::vector<std::string> ft_v(200, "hello");

            v.clear();
            ft_v.clear();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];

            cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
        }
        /*--------------------------------------------------------------------------------------------*/
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " get_allocator method "
              << "] --------------------]\t\t\033[0m";
    {
        std::vector<std::string> v(200, "hello");
        ft::vector<std::string> ft_v(200, "hello");

        EQUAL(v.get_allocator().max_size() == ft_v.get_allocator().max_size());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator== "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond;
        /*------------------------------------------ test 1: lhs.size == rhs.size ------------------*/
        {
            std::vector<int> v(100, 5);
            std::vector<int> v1(100, 5);
            ft::vector<int> ft_v(100, 5);
            ft::vector<int> ft_v1(100, 5);

            cond = ((v == v1) == (ft_v == ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v == v1) == (ft_v == ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v == v1) == (ft_v == ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 2: lhs.size < rhs.size ------------------*/
        {
            std::vector<int> v(50, 5);
            std::vector<int> v1(100, 5);
            ft::vector<int> ft_v(50, 5);
            ft::vector<int> ft_v1(100, 5);

            cond = (cond && (v == v1) == (ft_v == ft_v1));
            v[40] = 4;
            ft_v[40] = 4;
            cond = (cond && ((v == v1) == (ft_v == ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v == v1) == (ft_v == ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 3: lhs.size > rhs.size ------------------*/
        {
            std::vector<int> v(100, 5);
            std::vector<int> v1(50, 5);
            ft::vector<int> ft_v(100, 5);
            ft::vector<int> ft_v1(50, 5);

            cond = (cond && (v == v1) == (ft_v == ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v == v1) == (ft_v == ft_v1)));
            v1[40] = 3;
            ft_v1[40] = 3;
            cond = (cond && ((v == v1) == (ft_v == ft_v1)));
        }
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator!= "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond;
        /*------------------------------------------ test 1: lhs.size == rhs.size ------------------*/
        {
            std::vector<int> v(100, 5);
            std::vector<int> v1(100, 5);
            ft::vector<int> ft_v(100, 5);
            ft::vector<int> ft_v1(100, 5);

            cond = ((v != v1) == (ft_v != ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v != v1) == (ft_v != ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v != v1) == (ft_v != ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 2: lhs.size < rhs.size ------------------*/
        {
            std::vector<int> v(50, 5);
            std::vector<int> v1(100, 5);
            ft::vector<int> ft_v(50, 5);
            ft::vector<int> ft_v1(100, 5);

            cond = (cond && (v != v1) == (ft_v != ft_v1));
            v[40] = 4;
            ft_v[40] = 4;
            cond = (cond && ((v != v1) == (ft_v != ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v != v1) == (ft_v != ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 3: lhs.size > rhs.size ------------------*/
        {
            std::vector<int> v(100, 5);
            std::vector<int> v1(50, 5);
            ft::vector<int> ft_v(100, 5);
            ft::vector<int> ft_v1(50, 5);

            cond = (cond && (v != v1) == (ft_v != ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v != v1) == (ft_v != ft_v1)));
            v1[40] = 3;
            ft_v1[40] = 3;
            cond = (cond && ((v != v1) == (ft_v != ft_v1)));
        }
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator< "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond;
        /*------------------------------------------ test 1: lhs.size == rhs.size ------------------*/
        {
            std::vector<int> v(100, 5);
            std::vector<int> v1(100, 5);
            ft::vector<int> ft_v(100, 5);
            ft::vector<int> ft_v1(100, 5);

            cond = ((v < v1) == (ft_v < ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v < v1) == (ft_v < ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v < v1) == (ft_v < ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 2: lhs.size < rhs.size ------------------*/
        {
            std::vector<int> v(50, 5);
            std::vector<int> v1(100, 5);
            ft::vector<int> ft_v(50, 5);
            ft::vector<int> ft_v1(100, 5);

            cond = (cond && (v < v1) == (ft_v < ft_v1));
            v[40] = 4;
            ft_v[40] = 4;
            cond = (cond && ((v < v1) == (ft_v < ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v < v1) == (ft_v < ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 3: lhs.size > rhs.size ------------------*/
        {
            std::vector<int> v(100, 5);
            std::vector<int> v1(50, 5);
            ft::vector<int> ft_v(100, 5);
            ft::vector<int> ft_v1(50, 5);

            cond = (cond && (v < v1) == (ft_v < ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v < v1) == (ft_v < ft_v1)));
            v1[40] = 3;
            ft_v1[40] = 3;
            cond = (cond && ((v < v1) == (ft_v < ft_v1)));
        }
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator<= "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond;
        /*------------------------------------------ test 1: lhs.size == rhs.size ------------------*/
        {
            std::vector<int> v(100, 5);
            std::vector<int> v1(100, 5);
            ft::vector<int> ft_v(100, 5);
            ft::vector<int> ft_v1(100, 5);

            cond = ((v <= v1) == (ft_v <= ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v <= v1) == (ft_v <= ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v <= v1) == (ft_v <= ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 2: lhs.size < rhs.size ------------------*/
        {
            std::vector<int> v(50, 5);
            std::vector<int> v1(100, 5);
            ft::vector<int> ft_v(50, 5);
            ft::vector<int> ft_v1(100, 5);

            cond = (cond && (v <= v1) == (ft_v <= ft_v1));
            v[40] = 4;
            ft_v[40] = 4;
            cond = (cond && ((v <= v1) == (ft_v <= ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v <= v1) == (ft_v <= ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 3: lhs.size > rhs.size ------------------*/
        {
            std::vector<int> v(100, 5);
            std::vector<int> v1(50, 5);
            ft::vector<int> ft_v(100, 5);
            ft::vector<int> ft_v1(50, 5);

            cond = (cond && (v <= v1) == (ft_v <= ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v <= v1) == (ft_v <= ft_v1)));
            v1[40] = 3;
            ft_v1[40] = 3;
            cond = (cond && ((v <= v1) == (ft_v <= ft_v1)));
        }
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator> "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond;
        /*------------------------------------------ test 1: lhs.size == rhs.size ------------------*/
        {
            std::vector<int> v(100, 5);
            std::vector<int> v1(100, 5);
            ft::vector<int> ft_v(100, 5);
            ft::vector<int> ft_v1(100, 5);

            cond = ((v > v1) == (ft_v > ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 2: lhs.size < rhs.size ------------------*/
        {
            std::vector<int> v(50, 5);
            std::vector<int> v1(100, 5);
            ft::vector<int> ft_v(50, 5);
            ft::vector<int> ft_v1(100, 5);

            cond = (cond && (v > v1) == (ft_v > ft_v1));
            v[40] = 4;
            ft_v[40] = 4;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 3: lhs.size > rhs.size ------------------*/
        {
            std::vector<int> v(100, 5);
            std::vector<int> v1(50, 5);
            ft::vector<int> ft_v(100, 5);
            ft::vector<int> ft_v1(50, 5);

            cond = (cond && (v > v1) == (ft_v > ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
            v1[40] = 3;
            ft_v1[40] = 3;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
        }
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator>= "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond;
        /*------------------------------------------ test 1: lhs.size == rhs.size ------------------*/
        {
            std::vector<int> v(100, 5);
            std::vector<int> v1(100, 5);
            ft::vector<int> ft_v(100, 5);
            ft::vector<int> ft_v1(100, 5);

            cond = ((v >= v1) == (ft_v >= ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v >= v1) == (ft_v >= ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v >= v1) == (ft_v >= ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 2: lhs.size < rhs.size ------------------*/
        {
            std::vector<int> v(50, 5);
            std::vector<int> v1(100, 5);
            ft::vector<int> ft_v(50, 5);
            ft::vector<int> ft_v1(100, 5);

            cond = (cond && (v >= v1) == (ft_v >= ft_v1));
            v[40] = 4;
            ft_v[40] = 4;
            cond = (cond && ((v >= v1) == (ft_v >= ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v >= v1) == (ft_v >= ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 3: lhs.size > rhs.size ------------------*/
        {
            std::vector<int> v(100, 5);
            std::vector<int> v1(50, 5);
            ft::vector<int> ft_v(100, 5);
            ft::vector<int> ft_v1(50, 5);

            cond = (cond && (v >= v1) == (ft_v >= ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v >= v1) == (ft_v >= ft_v1)));
            v1[40] = 3;
            ft_v1[40] = 3;
            cond = (cond && ((v >= v1) == (ft_v >= ft_v1)));
        }
        EQUAL(cond);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " swap "
              << "] --------------------]\t\t\033[0m";
    {
        /*
         * strings to store the resutls
         */
        std::string str, ft_str;
        /*
         * var to store the size and the capacity
         */
        ft::vector<std::string>::size_type s, ft_s;
        ft::vector<std::string>::size_type c, ft_c;
        ft::vector<std::string>::iterator b1, b2;
        /*
         * bool to store the comparison
         */
        bool cond;

        /*---------------------------------- test 1: equal size vectors ----------------------*/
        {
            std::vector<std::string> v(200, "hello");
            std::vector<std::string> v1(200, "string");
            ft::vector<std::string> ft_v(200, "hello");
            ft::vector<std::string> ft_v1(200, "string");

            b1 = ft_v.begin();
            b2 = ft_v1.begin();

            swap(v, v1);
            swap(ft_v, ft_v1);

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];

            cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
            cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
            cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
        }
        /*--------------------------------------------------------------------------------------------*/
        /*---------------------------------- test 2: lhs > rhs ----------------------*/
        {
            std::vector<std::string> v(200, "hello");
            std::vector<std::string> v1(50, "string");
            ft::vector<std::string> ft_v(200, "hello");
            ft::vector<std::string> ft_v1(50, "string");

            b1 = ft_v.begin();
            b2 = ft_v1.begin();

            swap(v, v1);
            swap(ft_v, ft_v1);

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];

            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
            cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
        }
        /*--------------------------------------------------------------------------------------------*/
        /*---------------------------------- test 2: lhs < rhs ----------------------*/
        {
            std::vector<std::string> v(50, "hello");
            std::vector<std::string> v1(200, "string");
            ft::vector<std::string> ft_v(50, "hello");
            ft::vector<std::string> ft_v1(200, "string");

            b1 = ft_v.begin();
            b2 = ft_v1.begin();

            swap(v, v1);
            swap(ft_v, ft_v1);

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];

            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
            cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
        }
        /*--------------------------------------------------------------------------------------------*/
        EQUAL(cond);
    }
    std::cout << "\033[1;36m\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n";
} // vec_end

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
		// a + n
		ft::vector<int>::iterator ret = it + 3;
		std::cout << "*ret " << *ret << "\n";
		std::cout << "*it " << *it << "\n";
		// n + a
		ft::vector<int>::iterator ret3  = 1 + ret; 
		std::cout << "*ret3 " << *ret3 << "\n";
		std::cout << "*it " << *it << "\n";
		// a - n
		ft::vector<int>::iterator ret4  = ret3 - 1; 
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
		ft::vector<int>::iterator p  = ret += 1; 
		std::cout << "ret += 1 ==> " << *p << "\n";
		std::cout << "ret ==> " << *ret << "\n";
		// a -= n
		ft::vector<int>::iterator m = ret -= 1;
		std::cout << "ret -= 1 ==> " << *m << "\n";
	 	std::cout << "ret ==> " << *ret << "\n";
	}
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

	// {
	// 	// is_integral<T> inherits from integral_constant

	// 	if ( ft::is_integral<int>() )
	// 		std::cout << "int is an integral type" << std::endl;

	// 	// same result as:
	// 	if ( ft::is_integral<int>::value )
	// 		std::cout << "int is an integral type" << std::endl;
	// }
	// {
	// 	 std::cout << factorial<5>::value;  // constexpr (no calculations on runtime)
	// }

	// {
	// 	// enable_if example: two ways of using enable_if
	// 	short int i = 1;    // code does not compile if type of i is not integral

	// 	std::cout << std::boolalpha;
	// 	std::cout << "i is odd: " << is_odd(i) << std::endl;
	// 	std::cout << "i is even: " << is_even(i) << std::endl;
	// }

	// {
	// 	//test Constructs a container with as many elements as the range 
	// 	ft::vector<int> second (4,300);                       // four ints with value 100
  	// 	ft::vector<int> third (second.begin(),second.end());  // iterating through second
	// 	ft::vector<int> fourth (third);                       // a copy of third
	// 	for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
    // 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }

	// {
	// 	ft::vector<int> foo (3,0);
	// 	ft::vector<int> bar (5,0);

	// 	bar = foo;
	// 	foo = ft::vector<int>();

	// 	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	// 	std::cout << "Size of bar: " << int(bar.size()) << '\n';
	// }

	// {
	// 	// comparing size, capacity and max_size
	// 	ft::vector<int> myvector;

	// 	// set some content in the vector:
	// 	for (int i=0; i<100; i++) myvector.push_back(i);

	// 	std::cout << "size: " << myvector.size() << "\n";
	// 	std::cout << "capacity: " << myvector.capacity() << "\n";
	// 	std::cout << "max_size: " << myvector.max_size() << "\n";
	// }

	{
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

	// {
	// 	ft::vector<int> myvector;
	// 	int sum (0);

	// 	for (int i=1;i<=10;i++) myvector.push_back(i);

	// 	while (!myvector.empty())
	// 	{
	// 		sum += myvector.back();
	// 		myvector.pop_back();
	// 	}

	// 	std::cout << "total: " << sum << '\n';
	// }

	{
		//test vector back
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
		// test vector::front
		ft::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		std::cout << "myvector.front() is now " << myvector.front() << '\n';
	}

	{
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
		// ft::vector<int> myvector (3,100);
		// ft::vector<int>::iterator it;

		// it = myvector.begin();
		// std::cout << *it << "\n";
		// it = myvector.insert ( it , 200 );

		//  myvector.insert (it + 2, 5,300);

		// // "it" no longer valid, get a new one:
		// it = myvector.begin();

		// ft::vector<int> anothervector (4,400);
		// myvector.insert (it+2,anothervector.begin(),anothervector.end());

		// int myarray [] = { 501,502,503 };
		// myvector.insert (myvector.begin(), myarray, myarray+3);
		// std::cout << *it << "\n";
		// std::cout << "myvector contains:";
		// for (it=myvector.begin(); it<myvector.end(); it++)
		// 	std::cout << ' ' << *it;
		// std::cout << '\n';
	}

	{
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
		std::cout << "swap vectors test\n";
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
		std::cout << "vector::get_allocator\n";
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
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (2,200);   // two ints with a value of 200

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
	vector_tests();
	{
		// lexicographical_compare test
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
		//test bst 
		AVLTree<std::string> a;
		a.insert("11");
		a.insert("32");
		a.insert("54");
		a.insert("77");
		a.insert("88");
		a.insert("8");
		a.traverse();
	}
	
    return 0;
}