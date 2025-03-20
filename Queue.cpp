//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
 //==============================================================================


#include "Queue.h"
#include "Array.h"
#define DEFAULT_SIZE 10

//
// Queue
//
template <typename T>
Queue <T>::Queue(void)
	:arr_(new Array<T>(DEFAULT_SIZE)),
	front_(0),
	rear_(0)
{

}

//
// Queue
//
template <typename T>
Queue <T>::Queue(const Queue& q)
	:arr_(new Array<T>(*q.arr_)),
	front_(q.front_),
	rear_(q.rear_)
{
	for(int i = front_; i < rear_; i++)
	{
		arr_->set(i, q.arr_->get(i));
	}
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue(void)
{
	delete arr_;
}

//
// operator =
//
template <typename T>
const Queue<T> & Queue <T>::operator = (const Queue& rhs)
{
	if(this != &rhs)
	{
		delete arr_;
		arr_ = new Array<T>(*rhs.arr_);
		front_ = rhs.front_;
		rear_ = rhs.rear_;
	}
	return *this;
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue(T element)
{
    // COMMENT You are resizing the queue, but you are wasting space at the front of
    // the array. Fix your design so you use all the space in the array.
    
	if(rear_ >= arr_->size())
	{
		arr_->resize(arr_->max_size());
	}
	arr_->set(rear_, element);
	++rear_;

}

//
// dequeue
//
template <typename T>
void Queue <T>::dequeue(void)
{
    // COMMENT This solution will work, but you are wasting space at the front
    // of the array since those "unused" spaces will never be used again. Please
    // come up with a better design that uses memory more efficiently.
    
	if(this->is_empty())
		throw empty_exception();
	else
	{
		++front_;
	}


}

//
// front
//
template <typename T>
T Queue <T>::front(void)
{
	if (this->is_empty())
	{
		throw empty_exception();
	}	
	return arr_->get(front_);
}


//
// rear
//
template <typename T>
T Queue <T>::rear(void) 
{
	if (this->is_empty())
	{
		throw empty_exception();
	}
	return arr_->get(rear_-1);
}


//
// is_empty
//
template <typename T>
bool Queue <T>::is_empty(void)
{
	if(front_ == rear_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//
// size
//
template <typename T>
size_t Queue <T>::size(void) const
{
	return rear_ - front_;
}

//
// clear
//
template <typename T>
void Queue <T>::clear(void)
{
	front_ = 0;
	rear_ = 0;
	arr_->resize(DEFAULT_SIZE);
}
