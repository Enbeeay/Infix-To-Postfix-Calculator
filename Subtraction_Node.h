#ifndef SUBTRACTION_NODE_H
#define SUBTRACTION_NODE_H

#include "Binary_Node.h"

class Subtraction_Node : public Binary_Node
{
	public:
		Subtraction_Node();
		~Subtraction_Node();
		int evaluate(int n1, int n2);
};

#endif // !defined SUBTRACTION_NODE_H

