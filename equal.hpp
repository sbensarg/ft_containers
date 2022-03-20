#pragma once 

namespace ft
{
	// equality
	template <class InputIterator1, class InputIterator2>
 	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1)
		{
			if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
				return false;
			++first1; ++first2;
		}
		return true;
	}
	// predicate
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
  	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1!=last1)
		{
			if (!pred(*first1,*first2))   // or: if (!pred(*first1,*first2)), for version 2
				return false;
			++first1; ++first2;
		}
		return true;
	}

}
