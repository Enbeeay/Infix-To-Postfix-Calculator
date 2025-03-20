// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//

#include "Fixed_Array.h"
#define DEFAULT_SIZE 10

template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void) 
	: Array<T>(N)
{

}



//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array(const Fixed_Array <T, N>& arr)
	: Fixed_Array<T,N>()
{
	for (size_t i = 0; i < N; i++)
	{
		this->set(i, arr.get(i));
	}

}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr)
	: Fixed_Array<T, N>()
{
	/*
	*	STATES: 
	*	1. N > M
	*		- When the end of arr is reached, error will be caught
	*	2. N < M
	*		- Copy what can be copied, end will be cut off
	*	3. N = M
	*		- Copy all elements from arr to this->data_
	*/
	try
	{
		for (int i = 0; i < N; i++)
		{
			this->set(i, arr.get(i));
		}
	}
	catch (std::out_of_range& e) {}
	
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
	:Fixed_Array<T,N>()
{
	for (size_t i = 0; i < N; i++)
	{
		this->set(i, fill);
	}
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
	// Base class destructor will be called
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	for (size_t i = 0; i < N; i++)
	{
		this->set(i, rhs.get(i));
	}
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
	try
	{
		for (int i = 0; i < N; i++)
		{
			this->set(i, rhs.get(i));
		}
	}
	catch (std::out_of_range& e) {}

}
