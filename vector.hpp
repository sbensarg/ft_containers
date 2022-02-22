
namespace ft
{
	template <typename T>
    // Only declaring class here
    class vector;
}
  
// Defining class outside
template <typename T>
class ft::vector
{
public:
	vector() : m_Data(nullptr), m_Size(0), m_Capacity(0)
	{
		ReAlloc(2);
	}
	~vector()
	{
		clear();
		::operator delete(m_Data);
		//::operator delete(m_Data, m_Capacity * sizeof(T));
		//delete[] m_Data;
	}

	void puch_back(const T& value)
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
		for (size_t i = 0; i < m_Size; i++)
		{
			m_Data[i].~T();
		}
		m_Size = 0;
	}
	const T& operator[](size_t index) const
	{
		if (index >= m_Size)
		{
			//assert
		}
		return m_Data[index];
	}

	T& operator[](size_t index)
	{
		if (index >= m_Size)
		{
			
		}
		return m_Data[index];
	}

	size_t Size() const
	{
		return (m_Size);
	}


private:
	T* m_Data;
	size_t m_Size; // nbr of element inside the vector, keep track of how many element we have
	size_t m_Capacity; //how much memory we have allocated

	void ReAlloc(size_t newCapacity)
	{
		// 1. allocate a new block of memory
		// 2. copy/move old elements into new block
		// 3. delete

		//T* newBlock = new T[newCapacity];
		T* newBlock = (T*)::operator new (newCapacity * sizeof(T));
		if (newCapacity < m_Size)
			m_Size = newCapacity;

		for (size_t i = 0; i < m_Size; i++)
			newBlock[i] = m_Data[i];

		for (size_t i = 0; i < m_Size; i++)
		{
			m_Data[i].~T();
		}

		//delete[] m_Data;
		//::operator delete (m_Data, m_Capacity * sizeof(T));
		::operator delete(m_Data);
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

};