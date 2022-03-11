#include <memory>
#include "RandomAccessIterator.hpp"
#include "ReverseIterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include <stdexcept>
#pragma once
namespace ft
{
	template<
    class T,
    class Allocator = std::allocator<T>
> class vector;
}

// Defining class outside
template<
    class T,
    class Allocator
>
class ft::vector
{
public:
	// Attributes
	typedef T									value_type;
	typedef Allocator							allocator_type;
	typedef T*									pointer;
	typedef const T*							const_pointer;
	typedef T&									reference;
	typedef const T&							const_reference;
	typedef std::size_t							size_type;
	typedef std::ptrdiff_t						difference_type;
	typedef RandomAccessIterator<T> 			iterator;
	typedef ft::reverse_iterator<iterator>		reverse_iterator;

	// Constructors/Destructor
	explicit vector (const allocator_type& alloc = allocator_type()) : m_Allocator(alloc)
	{	
		// Constructs an empty container, with no elements.
		this->m_Size = 0;
		this->m_Capacity = 0;
		m_Data = m_Allocator.allocate(m_Capacity);
	}


	explicit vector (size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) 
		: m_Allocator(alloc)
	{
		// Constructs a container with n elements. Each element is a copy of val.
		this->m_Size = n;
		this->m_Capacity = n;
		m_Data = m_Allocator.allocate(m_Capacity);
		for(size_type i = 0; i < m_Size; i++)
			m_Allocator.construct(&m_Data[i], val);
	}
	// the second template argument is only valid if InputIterator is not an integral type:
	template <class InputIterator, class = typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*>
    vector (InputIterator first, InputIterator last, 
		const allocator_type& alloc = allocator_type())
		: m_Allocator(alloc)
	{
		/*Constructs a container with as many elements as the range [first,last),
		with each element constructed from its corresponding element in that range, in the same order.*/
		this->m_Size = 0;
		InputIterator tmp(first);
		while(tmp != last)
		{
			tmp++;
			m_Size++;
		}
		
		m_Capacity = m_Size;
		m_Data = m_Allocator.allocate(m_Capacity);
		for(size_type i = 0; first != last; first++)
		{
			m_Allocator.construct(&m_Data[i], *first);
			i++;
		}
	}
	vector (const vector& x)
	{
		//Constructs a container with a copy of each of the elements in x, in the same order.
		this->m_Allocator = x.m_Allocator;
		this->m_Size = x.m_Size;
		this->m_Capacity = x.m_Capacity;
		m_Data = m_Allocator.allocate(m_Capacity);
		for(size_type i = 0; i < m_Size; i++)
			this->m_Data[i] = x.m_Data[i];
	}

	~vector()
	{
		clear();
		m_Allocator.deallocate(m_Data, m_Capacity * sizeof(value_type));
	}

	//Assignment operator
	vector& operator= (const vector& x)
	{
		// Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
		this->m_Allocator = x.m_Allocator;
		this->m_Size = x.m_Size;
		this->m_Capacity = x.m_Capacity;
		m_Data = m_Allocator.allocate(m_Capacity);
		for(size_type i = 0; i < m_Size; i++)
			this->m_Data[i] = x.m_Data[i];
		return (*this);
	}

	size_type max_size() const
	{
		//Returns the maximum number of elements that the vector can hold.
		return m_Allocator.max_size();
	}

	void resize (size_type n, value_type val = value_type())
	{
		// Resizes the container so that it contains n elements.
		
		if (n < this->m_Size)
		{
			this->m_Size = n;
		}
		else if (n > this->m_Size)
		{
			if (m_Size >= m_Capacity)
            	ReAlloc(!m_Capacity ? 1 : m_Capacity * 2);
			while (m_Size < n)
			{
				m_Allocator.construct(&	m_Data[m_Size++], val);
			}
		}
	}

	void reserve (size_type n)
	{
		//Request a change in capacity
		if (n > max_size())
			throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
			
		if (n > m_Capacity)
		{
			this->m_Capacity = n;
			ReAlloc(m_Capacity);
		}
	}

	bool empty() const
	{
		//Test whether vector is empty
		if (this->m_Size == 0)
			return (true);
		else
			return (false);
	}

	size_type size() const
	{
		return (this->m_Size);
	}
	//Capacity
	size_type capacity() const
	{
		return (this->m_Capacity);
	}

	void push_back (const value_type& val)
	{
		if (m_Size >= m_Capacity)
            ReAlloc(!m_Capacity ? 1 : m_Capacity * 2);
		m_Allocator.construct(&	m_Data[m_Size++], val);
	}

	void pop_back()
	{
		if (m_Size > 0)
		{
			m_Size--;
			m_Data[m_Size].~T();
		}
	}

	void clear()
	{
		for (size_type i = 0; i < m_Size; i++)
		{
			m_Data[i].~T();
		}
		m_Size = 0;
	}

	const_reference operator[](size_type index) const
	{
		if (index >= m_Size)
		{
			//assert
		}
		return m_Data[index];
	}

	reference operator[](size_type index)
	{
		if (index >= m_Size)
		{
			
		}
		return m_Data[index];
	}

	reference at (size_type n)
	{
		//Returns a reference to the element at position n in the vector.
		if (n >= this->m_Size)
			throw std::out_of_range("vector");
		return m_Data[n];
	}

	const_reference at (size_type n) const
	{
		if (n >= this->m_Size)
			throw std::out_of_range("vector");
		return m_Data[n];
	}

	reference front()
	{
		//Returns a reference to the first element in the vector.
		return m_Data[0];
	}

	const_reference front() const
	{
		return m_Data[0];
	}

	reference back()
	{
		//Returns a reference to the last element in the vector.
		return m_Data[m_Size - 1];
	}
	const_reference back() const
	{
		return m_Data[m_Size - 1];
	}

	iterator begin()
	{
		return iterator(m_Data);
	}
	iterator end()
	{
		return iterator(m_Data + m_Size);
	}
	reverse_iterator rbegin()
	{
		return reverse_iterator(end());
	}
	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	}

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last)
	{
		for( ; first != last; first++)
		{
			push_back(*first);
		}
	}


 private:
	pointer			m_Data;
	size_type		m_Size; // nbr of element inside the vector, keep track of how many element we have
	size_type		m_Capacity; //how much memory we have allocated
	allocator_type	m_Allocator;

	void ReAlloc(size_type newCapacity)
	{
		// 1. allocate a new block of memory
		// 2. copy/construct old elements into new block
		// 3. call destruct the previous one with the destructor

		pointer newBlock = m_Allocator.allocate(newCapacity * sizeof(value_type));
		
		if (newCapacity < m_Size)
			m_Size = newCapacity;

		for (size_type i = 0; i < m_Size; i++)
			m_Allocator.construct(&newBlock[i], m_Data[i]);

		for (size_type i = 0; i < m_Size; i++)
		{
			m_Data[i].~T();
		}

		m_Allocator.deallocate(m_Data, m_Capacity * sizeof(value_type));
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

};