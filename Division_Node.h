#ifndef DIVISION_NODE_H
#define DIVISION_NODE_H

#include "Binary_Node.h"

class Division_Node : public Binary_Node
{
	public:
		Division_Node();
		~Division_Node();
		int evaluate(int num1, int num2);
};

#endif // !defined DIVISION_NODE_H