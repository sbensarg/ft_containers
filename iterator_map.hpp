#pragma once
#include <cstddef>

namespace ft
{
	template<typename K, typename V> class iterator_map;
}

template<typename K, typename V> 
class iterator_map
{
private:
	/* data */
public:
	typedef K								tree_pointer;
	typedef V								value_type;
    typedef std::ptrdiff_t					difference_type;
    typedef V								*pointer;
    typedef V								&reference;
    typedef std::bidirectional_iterator_tag	iterator_category;
	typedef iterator_map<K, const V>		const_iterator; 

	iterator_map & operator ++ ()
	{

	}

};



