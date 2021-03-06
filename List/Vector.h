#pragma once
#include <iostream>

template<typename T>
class Vector
{
public:
	Vector();
	~Vector();

	void Add(const T& value);
	void RemoveAt(size_t index);
	const size_t Size() { return size; }
	T& At(size_t index);
	T& operator[](size_t index);
private:
	void Reallocate(size_t capacity);
private:
	T* data;
	size_t size;
	size_t maxCapacity;
};

template<typename T>
inline Vector<T>::Vector()
{
	maxCapacity = 2;
	data = new T[maxCapacity];

	Reallocate(2);
}


template<typename T>
inline Vector<T>::~Vector()
{
	// Delete data when object is destroyed
	delete[] data;
}

template<typename T>
inline void Vector<T>::Add(const T& value)
{
	// Add value to the block of memory at current size
	// Add one to size
	// Reallocate memory
	data[size] = value;
	size++;
	Reallocate(maxCapacity + maxCapacity / 2);
}

template<typename T>
inline void Vector<T>::RemoveAt(size_t index)
{
	int i;
	for (i = 0; i < size; i++)
		if (i == index)
			break;

	if (i < size)
	{
		size--;
		for (int j = i; j < size; j++)
			data[j] = data[j + 1];
	}
}

template<typename T>
inline T& Vector<T>::At(size_t index)
{
	return data[index];
}

template<typename T>
inline T& Vector<T>::operator[](size_t index)
{
	// Return data from index.
	// Made so i can loop through the block
	// Should check if the index is not greater than the size
	return data[index];
}


template<typename T>
inline void Vector<T>::Reallocate(size_t capacity)
{
	// 1. Create a new block of memory
	// 2. If size has reached max capacity we add more
	// 3. Copy old block of memory into new block of memory
	// 4. Delete old block
	// 5. Set old block to new block.

	T* newBlock = new T[capacity];
	if (maxCapacity <= size)
		maxCapacity = capacity;
	for (size_t i = 0; i < capacity; i++)
		newBlock[i] = data[i];

	delete[] data;
	data = newBlock;
}
