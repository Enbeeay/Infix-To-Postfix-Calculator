#ifndef _NODE_H_
#define _NODE_H_

#include "Visitor.h"

class Node
{
	public:
		Node();
		~Node();
		virtual void accept(Visitor* v) = 0;
};

#endif // !defined _NODE_H_

