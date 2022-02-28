
#include <iostream>
#include "iterators_traits.hpp"
template <typename T>

class RandomAccessIterator : public ft::iterator_traits<T*>
{
private:

	T* _ptr;

public:

	RandomAccessIterator(void)
	{

	}
	RandomAccessIterator(T* ptr) : _ptr(ptr)
	{

	}
	RandomAccessIterator(RandomAccessIterator const & src)
	{
		this = src;
	}
	RandomAccessIterator & operator=(RandomAccessIterator const & rhs)
	{
		this->_ptr = rhs._ptr;
		return (*this);
	}
	
	bool operator==(const RandomAccessIterator & it) const { return this->_ptr == it._ptr; }
	bool operator!=(const RandomAccessIterator & it) const { return this->_ptr != it._ptr; }

	reference operator* () const { return *_ptr; }
	pointer   operator->() const { return  _ptr; }


	RandomAccessIterator & operator++() { _ptr++; return *this; }
	RandomAccessIterator operator++(int) const {RandomAccessIterator tmp(*this); ++_ptr; return tmp;}
	reference operator++(int) const {reference tmp(*this); ++_ptr; return tmp;}
	

    RandomAccessIterator & operator--() { _ptr--; return *this; }
	RandomAccessIterator operator--(int) const {RandomAccessIterator tmp(*this); --_ptr; return tmp;}
	reference operator--(int) const {reference tmp(*this); --_ptr; return tmp;}


	~RandomAccessIterator();
};
