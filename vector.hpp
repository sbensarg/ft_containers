#include <memory>
#include "RandomAccessIterator.hpp"
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


	vector() : m_Data(nullptr), m_Size(0), m_Capacity(0)
	{
		ReAlloc(2);
	}
	~vector()
	{
		clear();
		m_Allocator.deallocate(m_Data, m_Capacity * sizeof(value_type));
	}

	void puch_back(const_reference value)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);
	
		m_Data[m_Size] = value;
		m_Size++;
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

 private:
	pointer			m_Data;
	size_type		m_Size; // nbr of element inside the vector, keep track of how many element we have
	size_type		m_Capacity; //how much memory we have allocated
	allocator_type	m_Allocator;

	void ReAlloc(size_type newCapacity)
	{
		// 1. allocate a new block of memory
		// 2. copy/move old elements into new block
		// 3. delete

		pointer newBlock = m_Allocator.allocate(newCapacity * sizeof(value_type));
		
		if (newCapacity < m_Size)
			m_Size = newCapacity;

		for (size_type i = 0; i < m_Size; i++)
			newBlock[i] = m_Data[i];

		for (size_type i = 0; i < m_Size; i++)
		{
			m_Data[i].~T();
		}

		m_Allocator.deallocate(m_Data, m_Capacity * sizeof(value_type));
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

};