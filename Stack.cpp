// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//

#define EMPTY_STACK -1
#define DEFAULT_SIZE 10

#include "Stack.h"

template <typename T>
Stack <T>::Stack (void)
	:arr_(new Array<T>(DEFAULT_SIZE)),
	top_(EMPTY_STACK)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
	:arr_(new Array<T>(*stack.arr_)),
	top_(stack.top_)
{
	for(int i = 0; i < stack.top_; i++)
	{
		arr_->set(i, stack.arr_->get(i));
	}
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
	delete arr_;
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	top_++;
	if(top_ >= arr_->size())
	{
		arr_->resize(arr_->max_size());
	}
	
	arr_->set(top_, element);

}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	if (this->is_empty())
	{
		throw empty_exception("Cannot pop from empty stack");
	}
	
	top_--;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if(this != &rhs)
	{
		delete arr_;
		arr_ = new Array<T>(rhs.arr_->size());
		top_ = rhs.top_;
		for(int i = 0; i < rhs.top_; i++)
		{
			arr_->set(i, rhs.arr_->get(i));
		}
	}
	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear(void)
{
	top_ = EMPTY_STACK;
	arr_->resize(DEFAULT_SIZE);
}
