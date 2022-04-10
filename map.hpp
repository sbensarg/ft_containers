#pragma once 
#include "pair.hpp"
#include "AVLTree.hpp"
#include "iterator_map.hpp"
#include "ReverseIterator.hpp"
#include "vector.hpp"
#include <memory>

namespace ft
{
template <	class Key,                                      // map::key_type
			class T,                                        // map::mapped_type
			class Compare = std::less<Key>,                 // map::key_compare
			class Alloc = std::allocator<pair<const Key,T> >// map::allocator_type
			> 	
class map
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
    typedef typename AVLTree<key_type, mapped_type, Compare, Alloc>::tree_s* avlpointer;
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
    base_type       *base_tree;
    alloc_base       baseallocator;
    key_compare      comp;
    allocator_type   alloc;
    size_type        _size;

public:
	explicit map (const key_compare& com = key_compare(),
              const allocator_type& alctr = allocator_type())
    {
		this->base_tree = baseallocator.allocate(1);
		baseallocator.construct(this->base_tree, base_type());
		this->alloc = alctr;
		this->comp = com;
		this->_size = 0;
    }

    template <class InputIterator>
    map (InputIterator first, InputIterator last,
       const key_compare& com = key_compare(),
       const allocator_type& alctr = allocator_type())
    {
		this->alloc = alctr;
		this->comp = com;
		this->base_tree = baseallocator.allocate(1);
		baseallocator.construct(this->base_tree, base_type());
		this->_size = 0;
		insert(first, last);
    }
    map (const map& x)
    {
		this->base_tree = baseallocator.allocate(1);
		baseallocator.construct(this->base_tree, *(x.base_tree));
		this->alloc = x.alloc;
		this->_size = x._size;
		this->comp = x.comp;
    }

    map& operator= (const map& x)
    {
		this->alloc = x.alloc;
		this->comp = x.comp;
		this->clear();
		baseallocator.destroy(this->base_tree);
		baseallocator.construct(this->base_tree, *(x.base_tree));
		this->_size = x._size;
		return (*this);
    }

private:
	iterator ret_iter(const key_type& k)
    {
      if (base_tree->root != NULL)
      {
        treepointer *tmp = base_tree->root;
        while (tmp)
        {
          if (comp(k, tmp->getData().first) == true)
            tmp = tmp->getLeftChild();
          else if (comp(tmp->getData().first, k) == true)
            tmp = tmp->getRightChild();
          else {
            return (iterator(base_tree->root, tmp, base_tree->last_elem));
          }
        }
      }
      return (end());
    }

    const_iterator ret_iter(const key_type& k) const
    {
      if (base_tree->root != NULL)
      {
        treepointer *tmp = base_tree->root;
        while (tmp)
        {
          if (comp(k, tmp->getData().first) == true)
            tmp = tmp->getLeftChild();
          else if (comp(tmp->getData().first, k) == true)
            tmp = tmp->getRightChild();
          else {
            return (iterator(base_tree->root, tmp, base_tree->last_elem));
          }
        }
      }
      return (end());
    }
public:
	// single element (1)
	ft::pair<iterator,bool>insert (const value_type& val)
    {
		/* return a pair, with its member pair::first 
		set to an iterator pointing to either the newly 
		inserted element or to the element with an equivalent 
		key in the map. The pair::second element in the pair 
		is set to true if a new element was inserted or false 
		if an equivalent key already existed. */
      if (ret_iter(val.first) == end())
      {
        base_tree->insert(val);
        _size++;
        return(ft::make_pair(ret_iter(val.first), 1));
      }
      return(ft::make_pair(ret_iter(val.first), 0));
    }

	// with hint (2)
	iterator insert (iterator position, const value_type& val)
    {
		/*return an iterator pointing to either the newly 
		inserted element or to the element that already 
		had an equivalent key in the map. */
      (void)position;
      return ((this->insert(val)).first);
    }
	//range (3)
	template <class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
      while (first != last)
      {
        this->insert(*first);
        first++;
      }
    }

	iterator begin()
    {
      if (this->empty() == true)
	  {
        return (iterator(base_tree->root, base_tree->last_elem, base_tree->last_elem));
	  }
      return (iterator(base_tree->root, base_tree->mostleft(base_tree->root), base_tree->last_elem));
    }

    const_iterator begin() const
    {
      if (this->empty() == true)
        return (const_iterator(base_tree->root, base_tree->last_elem, base_tree->last_elem));
      return (const_iterator(base_tree->root, base_tree->mostleft(base_tree->root), base_tree->last_elem));
    }

	iterator end()
    {
      return (iterator(base_tree->root, base_tree->last_elem, base_tree->last_elem));
    }

    const_iterator end() const
    {
      return (const_iterator(base_tree->root, base_tree->last_elem, base_tree->last_elem));
    }

	reverse_iterator rbegin()
    {
      return (reverse_iterator(end()));
    }

    const_reverse_iterator rbegin() const
    {
      return (const_reverse_iterator(end()));
    }

    reverse_iterator rend()
    {
      return (reverse_iterator(begin()));
    }

    const_reverse_iterator rend() const
    {
      return (const_reverse_iterator(begin()));
    }

	bool empty() const
    {
      if (base_tree->root == NULL || this->_size == 0)
        return (1);
      return (0);
    }

	size_type size() const
    {
      return (this->_size);
    }

    size_type max_size() const
    {
    	return alloc.max_size();
    }

	mapped_type& operator[] (const key_type& k)
	{
		//take the first from the return of insert which is iterator to the element and dereference it to take the second which is the mapped value
		return ((*((this->insert(ft::make_pair(k,mapped_type()))).first)).second);
    }

	void erase (iterator position)
    {
		if (this->empty() == true)
			return ;
		this->erase((*position).first);
    }

    size_type erase (const key_type& k)
    {
		if(base_tree->root == NULL)
			return 0;
		if (this->empty() == true)
			return 0;
		if (ret_iter(k) == end())
			return 0;
		base_tree->del(k);
		this->_size--;
		return 1;
    }

	void erase (iterator first, iterator last)
    {
		if (this->empty() == true)
			return ;
		ft::vector<key_type> a;
		while (first != last)
		{
			a.push_back(first->first);
			first++;
		}
		for (typename ft::vector<key_type>::iterator it = a.begin(); it != a.end(); it++)
			this->erase(*it);
	}

	void swap (map& x)
	{
		std::swap(_size, x._size);
		std::swap(base_tree, x.base_tree);
	}

	void clear()
	{
   	   if (empty() == true)
        return ;
      base_tree->root = this->base_tree->clear(base_tree->root);
	  //erase(begin(), end());
      this->_size = 0;
    }

	key_compare key_comp() const
    {
		//Returns a copy of the comparison object used by the container to compare keys.
      	return (comp);
    }

	value_compare value_comp() const
    {	
		/*Returns a function object that compares objects of 
		type std::map::value_type (key-value pairs) by using 
		key_comp to compare the first components of the pairs.*/
    	return (value_compare(comp));
    }

	iterator find (const key_type& k)
    {
		/*Searches the container for an element with a key 
		equivalent to k and returns an iterator to it if found,
		 otherwise it returns an iterator to map::end.*/
    	return (ret_iter(k));
    }

    const_iterator find (const key_type& k) const
    {
    	return (ret_iter(k));
    }
	size_type count (const key_type& k) const
    {
		// Searches the container for elements with a key equivalent to k and returns the number of matches.
		if (find(k) != end())
			return 1;
		return 0;
    }

	iterator lower_bound(const key_type& k)
	{
		/*The function returns an iterator pointing
		to the key in the map container which is 
		equivalent to k passed in the parameter.
		In case k is not present in the map container,
		the function returns an iterator pointing
		to the immediate next element which is just greater than k.*/
		iterator i = begin();

		while  (i != end())
		{
			if (!comp(i->first, k))
				break;
			i++;
		}
		return i;
	}
	const_iterator lower_bound (const key_type& k) const
	{
		const_iterator i = begin();

		while  (i != end())
		{
			if (!comp(i->first, k))
				break;
			i++;
		}
		return i;
	}

	iterator upper_bound (const key_type& k)
	{
		/*The function returns an iterator pointing to
		the immediate next element which is just greater than k.*/
		iterator i = begin();

		while (i != end())
		{
			if (comp(k, i->first))
				break;
			i++;
		}
		return i;  
	}

	const_iterator upper_bound (const key_type& k) const
	{
		const_iterator i = begin();

		while (i != end())
		{
			if (comp(k, i->first))
				break;
			i++;
		}
		return i;  
	}

	pair<iterator,iterator> equal_range (const key_type& k)
	{
		// Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
		return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
	}

	pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{
		return ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
	}

	allocator_type get_allocator() const
    {
      return alloc;
    }

    ~map()
	{
		this->clear();
		baseallocator.destroy(this->base_tree);
		baseallocator.deallocate(this->base_tree, 1);
	}
};
}

	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

  	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const ft::map<Key,T,Compare,Alloc>& lhs,
						const ft::map<Key,T,Compare,Alloc>& rhs )
		{
			return (!(lhs == rhs));
		}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const ft::map<Key,T,Compare,Alloc>& lhs,
						const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const ft::map<Key,T,Compare,Alloc>& lhs,
						const ft::map<Key,T,Compare,Alloc>& rhs )
		{
			return !(rhs < lhs);
		}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const ft::map<Key,T,Compare,Alloc>& lhs,
						const ft::map<Key,T,Compare,Alloc>& rhs )
		{
			return rhs < lhs;
		}
	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const ft::map<Key,T,Compare,Alloc>& lhs,
						const ft::map<Key,T,Compare,Alloc>& rhs )
		{
			return !(lhs < rhs);
		}

	template <class Key, class T, class Compare, class Alloc>
	void swap (ft::map<Key,T,Compare,Alloc>& x, ft::map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}
