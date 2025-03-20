// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_range exception

#define DEFAULT_MAX_SIZE 20

template <typename T>
Array <T>::Array(void)
    : Base_Array <T>(),
    max_size_(DEFAULT_MAX_SIZE)  
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array(size_t length)
    : Base_Array <T>(length)
{

}

//
// Array (size_t, T)
//
template <typename T>
Array <T>::Array(size_t length, T fill)
    : Base_Array <T>(length)
{
    for (size_t i = 0; i < length; i++)
    {
		this->data_[i] = fill;
	}   
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array(const Array& array)
    : Base_Array <T>(array.size_)
{
    for (size_t i = 0; i < array.size_; i++)
    {
        this->data_[i] = array.data_[i];
    }   
}

//
// Operator =
//
//
// operator =
//
template <typename T>
const Array <T>& Array <T>::operator = (const Array& rhs)
{
    // Check for same address
    if (this == &rhs)
    {
        return *this;
    }

    delete[] this->data_;

    // Allocate new memory and fill with rhs data_
    this->data_ = new T[rhs.size_];

    for (size_t i = 0; i < rhs.cur_size; i++)
    {
        this->data_[i] = rhs.data_[i];
    }

    this->size_ = rhs.size_;
    this->max_size_ = rhs.max_size_;

    return *this;

}


//
// max_size
//
template <typename T>
size_t Array <T>::max_size(void) const
{
	return max_size_;
}

//
// Resize
//
template <typename T>
void Array <T>::resize(size_t new_size)
{
    // check if new size is less than current size
    if (new_size < this->size_)
    {
        this->size_ = new_size;
    }
    else
    {
        T* temp = new T[new_size];

        for (size_t i = 0; i < this->size_; i++)
        {
            temp[i] = this->data_[i];
        }

        delete[] this->data_;
        this->data_ = temp;
        this->size_ = new_size;
        this->max_size_ = new_size * 2;
    }
}

template <typename T>
void Array<T>::shrink(void)
{
    if (this->size_ == 0)
    {
		throw std::out_of_range("Array is empty");
	}
    else if (this->max_size_ / 2 < this->size_)
    {
        resize(this->size_);
    }
}

