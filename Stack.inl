// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

#define DEFAULT_SIZE 10
#define EMPTY_STACK -1

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return top_ + 1;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	if (this->is_empty())
	{
		throw empty_exception("Cannot return top from empty stack");
	}
	
	return this->arr_->get(top_);
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	if (top_ == EMPTY_STACK)
		return true;
	return false;
}
