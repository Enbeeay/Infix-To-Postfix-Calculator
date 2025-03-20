#ifndef ADDITION_NODE_H
#define ADDITION_NODE_H

#include "Binary_Node.h"

class Addition_Node : public Binary_Node
{
	public:
		Addition_Node();
		~Addition_Node();
		int evaluate(int n1, int n2);
};

#endif // !defined ADDITION_NODE_H