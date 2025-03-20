#ifndef MULTIPLICATION_NODE_H
#define MULTIPLICATION_NODE_H

#include "Binary_Node.h"
class Multiplication_Node : public Binary_Node
{
	public:
	Multiplication_Node();
	~Multiplication_Node();
	int evaluate(int num1, int num2);
};

#endif // !defined MULTIPLICATION_NODE_H
