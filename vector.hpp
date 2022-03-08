#include <memory>
#include "RandomAccessIterator.hpp"
#include "ReverseIterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
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
	typedef T								value_type;
	typedef Allocator						allocator_type;
	typedef T*								pointer;
	typedef const T*						const_pointer;
	typedef T&								reference;
	typedef const T&						const_reference;
	typedef std::size_t						size_type;
	typedef std::ptrdiff_t					difference_type;
	typedef RandomAccessIterator<T> 		iterator;
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
		: m_Allocator(alloc), m_Size(n), m_Capacity(n)
	{
		// Constructs a container with n elements. Each element is a copy of val.
		m_Data = m_Allocator.allocate(m_Capacity);
		for(size_type i = 0; i < m_Size; i++)
			m_Allocator.construct(&m_Data[i], val);
	}

	// template <class InputIterator, class = typename ft::enable_if<ft::is_integral<T>::value>::type*>
    // vector (InputIterator first, InputIterator last, 
	// 	const allocator_type& alloc = allocator_type())
	// 	: m_Allocator(alloc)
	// {
	// 	InputIterator tmp(first);
	// 	while(tmp != last)
	// 	{
	// 		tmp++;
	// 		m_Size++;
	// 	}
		
	// 	m_Capacity = m_Size;
	// 	m_Data = m_Allocator.allocate(m_Capacity);
	// 	for(size_type i = 0; first != last; first++)
	// 	{
	// 		m_Allocator.construct(&m_Data[i], *first);
	// 		i++;
	// 	}
	// }

	~vector()
	{
		clear();
		m_Allocator.deallocate(m_Data, m_Capacity * sizeof(value_type));
	}
	
	//Capacity
	size_type size() const
	{
		return (this->m_Size);
	}

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

	size_type Size() const
	{
		return (m_Size);
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