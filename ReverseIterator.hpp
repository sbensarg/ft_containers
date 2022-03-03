#include "iterators_traits.hpp"

#pragma once
namespace ft
{
	template <class Iterator> class reverse_iterator;
}

template <class Iterator>

class ft::reverse_iterator 
{
public:
	typedef Iterator iterator_type;
	typedef typename ft::iterator_traits<Iterator>::iterator_category 		iterator_category;
	typedef typename ft::iterator_traits<Iterator>::value_type 				value_type;
	typedef typename ft::iterator_traits<Iterator>::reference 				reference;
	typedef typename ft::iterator_traits<Iterator>::pointer					pointer;
	typedef typename ft::iterator_traits<Iterator>::difference_type			difference_type;

	reverse_iterator() : _it(nullptr)
	{

	}

	explicit reverse_iterator (iterator_type it) :_it(it)
	{

	}

	template <class Iter>
	reverse_iterator (const reverse_iterator<Iter>& rev_it)
	{
		this->_it = rev_it.base();
	}

	iterator_type base() const
	{
		return (_it);
	}
	reference operator*() const
	{
		iterator_type tmp = _it;
        return (*(--tmp));
	}
	reference operator[] (difference_type n) const
	{
		return (base()[-n-1]);
	}
	reverse_iterator& operator--()
	{
		_it++;
		return (*this);
	}

	reverse_iterator  operator--(int)
	{
		 reverse_iterator tmp = *this;
		--(*this);
		return (tmp);
	}

	reverse_iterator& operator++()
	{
		_it--;
        return (*this);
	}

	reverse_iterator  operator++(int)
	{
		reverse_iterator tmp = *this;
		++(*this);
		return (tmp);
	}
	reverse_iterator operator+ (difference_type n) const
	{
		return reverse_iterator(_it - n);
	}

	reverse_iterator operator- (difference_type n) const
	{
		return reverse_iterator(_it + n);
	}

	reverse_iterator& operator+= (difference_type n)
	{
		_it -= n;
		return (*this);
	}
	reverse_iterator& operator-= (difference_type n)
	{
		_it += n;
		return (*this);
	}

	private:
		iterator_type _it;
	
};

//std::relational operators (reverse_iterator)	
template <class Iterator>
bool operator== (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <class Iterator>
bool operator!= (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() != rhs.base());
}

	
template <class Iterator>
bool operator<  (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() > rhs.base());
}

template <class Iterator>
bool operator<= (const ft:: reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template <class Iterator>
bool operator>  (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() < rhs.base());
}

template <class Iterator>
bool operator>= (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() <= rhs.base());
}

// Addition operator
template <class Iterator>
ft::reverse_iterator<Iterator> operator+ ( typename ft::reverse_iterator<Iterator>::difference_type n,
            const ft::reverse_iterator<Iterator>& rev_it)
{
	return ft::reverse_iterator<Iterator>(n + rev_it.base());
}

//Subtraction operator

template <class Iterator>
ft::reverse_iterator<Iterator> operator- ( typename ft::reverse_iterator<Iterator>::difference_type n,
            const ft::reverse_iterator<Iterator>& rev_it)
{
	return ft::reverse_iterator<Iterator>(n - rev_it.base());
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::difference_type operator- (
    const ft::reverse_iterator<Iterator>& lhs,
    const ft::reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() - rhs.base());
}
