#include "Base_Array.h"

#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>

#define DEFAULTSIZE 10

template <typename T>
Base_Array <T>::Base_Array(void)
	: data_(new T[DEFAULTSIZE]),
	size_(DEFAULTSIZE)
{

}

template <typename T>
Base_Array <T>::Base_Array(size_t length)
	: data_(new T[length]),
	size_(length)
{

}


template <typename T>
Base_Array<T>::~Base_Array()
{
	delete[] data_;
}

template <typename T>
size_t Base_Array<T>::size(void) const
{
	return size_;
}

template <typename T>
T & Base_Array<T>::operator[](size_t index)
{
	if (index >= size_)
	{
		throw std::out_of_range("Index out of range");
	}
	return data_[index];
}

template <typename T>
const T & Base_Array<T>::operator[](size_t index) const
{
	if (index >= size_)
	{
		throw std::out_of_range("Index out of range");
	}
	return data_[index];
}

template <typename T>
T Base_Array<T>::get(size_t index) const
{
	if (index >= size_)
	{
		throw std::out_of_range("Index out of range");
	}
	return data_[index];
}

template <typename T>
void Base_Array<T>::set(size_t index, T value)
{
	if (index >= size_)
	{
		throw std::out_of_range("Index out of range");
	}
	data_[index] = value;
}

template <typename T>
int Base_Array<T>::find(T element, size_t start) const
{
	if (start >= size_)
	{
		throw std::out_of_range("Index out of range");
	}
	for (size_t i = start; i < size_; i++)
	{
		if (element == data_[i])
		{
			return i;
		}
	}

	return -1;
}

template <typename T>
bool Base_Array<T>::operator == (const Base_Array& rhs) const
{
	// Check for same address
	if (this == &rhs)
	{
		return true;
	}
	if (this->size_ != rhs.size_)
	{
		return false;
	}
	for (size_t i = 0; i < size_; i++)
	{
		if (this->data_[i] != rhs.data_[i])
		{
			return false;
		}
	}

	return true;
}

template <typename T>
bool Base_Array<T>::operator != (const Base_Array& rhs) const
{
	return !(*this == rhs);
}

template <typename T>
void Base_Array<T>::fill(T element)
{
	for (size_t i = 0; i < this->size_; i++)
	{
		this->data_[i] = element;
	}
}
