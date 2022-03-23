#include <memory>
#include "RandomAccessIterator.hpp"
#include "ReverseIterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"
#include <stdexcept>
#include <algorithm>
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
	typedef T														value_type;
	typedef Allocator												allocator_type;
	typedef T*														pointer;
	typedef const T*												const_pointer;
	typedef T&														reference;
	typedef const T&												const_reference;
	typedef std::size_t												size_type;
	typedef std::ptrdiff_t											difference_type;
	typedef RandomAccessIterator<value_type> 						iterator;
	typedef RandomAccessIterator<const value_type>					const_iterator;
	typedef ft::reverse_iterator<iterator>							reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
	typedef typename Allocator::template rebind<value_type>::other	alloc_type;


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
	template <class InputIterator>
    vector (InputIterator first, InputIterator last, 
		const allocator_type& alloc = allocator_type()
		, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = nullptr)
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
		{
			m_Allocator.construct(&m_Data[i], x.m_Data[i]);
		}
	}

	~vector()
	{
		clear();
		m_Allocator.deallocate(m_Data, m_Capacity);
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
			m_Allocator.construct(&m_Data[i], x.m_Data[i]);
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
			for(size_type i = n - 1; i < m_Size; i++)
				m_Allocator.destroy(&m_Data[i]);
			this->m_Size = n;
		}
		else if (n > this->m_Size)
		{
			if (n >= m_Capacity)
				ReAlloc(n);
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
		// Add element at the end
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

	const_iterator begin() const
	{
		return const_iterator(m_Data);
	}

	iterator end()
	{
		return iterator(m_Data + m_Size);
	}

	const_iterator end() const
	{
		return const_iterator(m_Data + m_Size);
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(end());
	}

	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(end());
	}

	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	}

	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(begin());
	}

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = nullptr)
	{
		// the new contents are elements constructed from each of the elements in the range between first and last, in the same order.
		clear();
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
	
	void assign (size_type n, const value_type& val)
	{
		// the new contents are n elements, each initialized to a copy of val.
		if (this->m_Size < n)
		{
			m_Allocator.deallocate(m_Data, m_Capacity * sizeof(value_type));
			m_Data = m_Allocator.allocate(n);
			if(m_Capacity < m_Size)
			{
				this->m_Capacity = n;
			}
		}
		this->m_Size = n;
		for(size_type i = 0; i < m_Size; i++)
			m_Allocator.construct(&m_Data[i], val);
		if (m_Capacity < m_Size)
			m_Capacity = m_Size;
	}

	iterator insert (iterator position, const value_type& val)
	{
		/* insert() also needs to grow the array, if needed. 
		It can then figure out the index where the new value should go, 
		shift all of the elements after that index up one slot in the array, 
		and then assign the new value to the element at that index. */
		int index = position - begin();
		
		if (m_Size >= m_Capacity)
            ReAlloc(!m_Capacity ? 1 : m_Capacity * 2);
	
		for (int i = this->m_Size - 1; i >= index; --i)
		{
			m_Allocator.construct(&m_Data[i + 1], m_Data[i]);
		}
		m_Allocator.construct(&m_Data[index], val);
		++m_Size;
		return iterator (m_Data + index);
		//return (position);
	}

	void insert (iterator position, size_type n, const value_type& val)
	{
		int index = position - begin();
		if ((m_Size + n) > m_Capacity)
		{
			if (n > m_Size)
				ReAlloc(m_Size + n);
			else
				ReAlloc(m_Capacity * 2);
		}
		else if (m_Size == 0)
			ReAlloc(n);
		for (int i = m_Size - 1; i >= index; i--)
			m_Allocator.construct(&m_Data[i + n], m_Data[i]);
		for (size_type i = 0; i < n; i++)
			m_Allocator.construct(&m_Data[index++], val);
		this->m_Size += n;
	}

	template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = nullptr)
	{
		int index = position - begin();
		size_type n = last - first;
		if ((m_Size + n) > m_Capacity)
		{
			if (n > m_Size)
				ReAlloc(m_Size + n);
			else
				ReAlloc(m_Capacity * 2);
		}
		else if (m_Size == 0)
			ReAlloc(n);
		for (int i = m_Size - 1; i >= index; i--)
			m_Allocator.construct(&m_Data[i + n], m_Data[i]);
		for (size_type i = 0; i < n; i++)
			m_Allocator.construct(&m_Data[index++], *first);
		this->m_Size += n;
	}

	iterator erase (iterator position)
	{
		std::copy(position + 1, end(), position);
		resize (size() - 1);
		return position;
	}

	iterator erase (iterator first, iterator last)
	{
		size_type n = last - first;
		std::copy(last, end(), first);
		resize(size() - n);
		return first;
	}

	void swap (vector& x)
	{
		std::swap(m_Size, x.m_Size);
		std::swap(m_Capacity, x.m_Capacity);
		std::swap(m_Data, x.m_Data);
	}

	//Allocator:

	allocator_type get_allocator() const
	{
		return m_Allocator;
	}

private:
	pointer			m_Data;
	size_type		m_Size; 	// nbr of element inside the vector, keep track of how many element we have
	size_type		m_Capacity;	//how much memory we have allocated
	alloc_type		m_Allocator;

	void ReAlloc(size_type newCapacity)
	{
		// 1. allocate a new block of memory
		// 2. copy/construct old elements into new block
		// 3. call destruct the previous one with the destructor

		pointer newBlock = m_Allocator.allocate(newCapacity);
		
		if (newCapacity < m_Size)
			m_Size = newCapacity;

		for (size_type i = 0; i < m_Size; i++)
			m_Allocator.construct(&newBlock[i], m_Data[i]);

		for (size_type i = 0; i < m_Size; i++)
			m_Allocator.destroy(&m_Data[i]);
		
		m_Allocator.deallocate(m_Data, m_Capacity);
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

};

	/********Non-member function overloads*******/
	// relational operators (vector)
	template <class Tp, class Alloc>
	bool operator== (const ft::vector<Tp,Alloc>& lhs, const ft::vector<Tp,Alloc>& rhs)
	{
		/*The equality comparison (operator==) is performed by first comparing sizes,
		and if they match, the elements are compared sequentially using operator==,
		stopping at the first mismatch (as if using algorithm equal). */
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Tp, class Alloc>
	bool operator!= (const ft::vector<Tp,Alloc>& lhs, const ft::vector<Tp,Alloc>& rhs)
	{
		// Based on operator==
		return !(lhs == rhs);
	}

	template <class Tp, class Alloc>
	bool operator<  (const ft::vector<Tp,Alloc>& lhs, const ft::vector<Tp,Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(),
											rhs.begin(), rhs.end());
	}

	template <class Tp, class Alloc>
	bool operator<= (const ft::vector<Tp,Alloc>& lhs, const ft::vector<Tp,Alloc>& rhs)
	{
		// Based on operator<
		return !(rhs < lhs);
	}

	template <class Tp, class Alloc>
	bool operator>  (const ft::vector<Tp,Alloc>& lhs, const ft::vector<Tp,Alloc>& rhs)
	{
		/// Based on operator<
		return rhs < lhs;
	}

	template <class Tp, class Alloc>
	bool operator>= (const ft::vector<Tp,Alloc>& lhs, const ft::vector<Tp,Alloc>& rhs)
	{
		// Based on operator<
		return !(lhs < rhs); 

	}

	//swap (vector)
	template <class Tp, class Alloc>
	void swap (ft::vector<Tp,Alloc>& x, ft::vector<Tp,Alloc>& y)
	{
		x.swap(y);
	}
