//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
 //==============================================================================

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <exception>

/**
 * @class Queue
 *
 * Basic queue for abitrary elements.
 */

template <typename T>
class Queue
{
public:
	// Type definition of the type.
	typedef T type;

	/**
    * @class empty_exception
    *
    * Exception thrown to indicate the stack is empty.
    */
	class empty_exception : public std::exception
	{
	public:
		/// Default constructor.
		empty_exception(void)
			: std::exception() { }

		/**
		* Overridden what function 
		* 
		* @return         Error message
		*/
		const char* what() const throw() {
			return "Queue is empty";
		}
	};

	/// Default constructor.
	Queue (void);

	/// Copy constructor.
	Queue (const Queue & q);

	/// Destructor.
	~Queue (void);

	/**
     * Assignment operator
     *
     * @param[in]      rhs           Right-hand side of operator
     * @return         Reference to self
     */
	const Queue & operator = (const Queue& rhs);

	/**
	 * Add a new \a element to the end of the list.
	 *
	 * @param[in]      element       Element to add to the list
	 */
	void enqueue (T element);

	/**
	 * Remove the first element from the list.
	 *
	 * @exception      empty_exception    The queue is empty.
	 */
	void dequeue (void);

	/**
	 * Get the first element in the queue. If the queue is empty, then the
	 * result is undefined.
	 *
	 * @return         Element at the front of the queue
	 */
	T front (void);

	/**
	 * Get the last element in the queue. If the queue is empty, then the
	 * result is undefined.
	 * 
	 * @return         Element at the rear of the queue
	 */
	T rear (void);
	  

	/**
	 * Test is the queue is empty
	 * 
	 * @retval         true          The queue is empty
	 * @retval         false         The queue is not empty
	 */
	bool is_empty (void);


	/**
	 * Number of element in the queue
	 *
	 * @return         Size of the queue
	 */
	size_t size (void) const;

	/**
	 * Remove all elements from the queue
	 */
	void clear (void);

private:
    // COMMENT There is no need to allocate the array on the heap. Always try to
    // allocate on the stack to reduce the complexity of your code.
    
	// FIX Allocated the array on the stack instead of the heap.

	Array<T> * arr_;
	size_t front_;
	size_t rear_;
};

#include "Queue.cpp"
#endif // !defined _QUEUE_H_
