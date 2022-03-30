#pragma once 
#include "pair.hpp"
#include "AVLTree.hpp"
#include "iterator_map.hpp"
#include "ReverseIterator.hpp"
#include <memory>

namespace ft
{
template <	class Key,                                      // map::key_type
			class T,                                        // map::mapped_type
			class Compare = std::less<Key>,                 // map::key_compare
			class Alloc = std::allocator<pair<const Key,T> >// map::allocator_type
			> class map;
}

template <class Key, class T, class Compare, class Alloc >
		
class ft::map
{
public:
    typedef Key                                                              key_type;
    typedef T                                                                mapped_type;
    typedef Compare                                                          key_compare;
    typedef Alloc                                                            allocator_type;
    typedef ft::pair<const Key, T>                                           value_type;
    typedef typename allocator_type::pointer                                 pointer;
    typedef typename allocator_type::reference                               reference;
    typedef AVLTree<key_type, mapped_type, Compare, Alloc>                   base_type;
    typedef typename base_type::tree_s                                       treepointer;
    typedef typename allocator_type::template rebind<base_type>::other       alloc_base;
    typedef size_t                                                           size_type;
    typedef typename AvlTree<key_type, mapped_type, Compare, Alloc>::tree_s* avlpointer;
    typedef ft::iterator_map<avlpointer , value_type>                        iterator;
    typedef ft::iterator_map<avlpointer , const value_type>                  const_iterator;
    typedef ft::reverse_iterator<iterator>                                   reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>                             const_reverse_iterator;

	class value_compare
	{
	friend class map;
	protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator() (const value_type& x, const value_type& y) const
		{
		return comp(x.first, y.first);
		}
	};


private:
    base_type       *m_BaseTree;
    alloc_base       m_BaseAlloc;
    key_compare      m_Comp;
	allocator_type	m_Allocator;
	size_type		m_Size;
};

