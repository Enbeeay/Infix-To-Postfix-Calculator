#ifndef MODULUS_NODE_H
#define MODULUS_NODE_H

#include "Binary_Node.h"
class Modulus_Node : public Binary_Node
{
	public:
		Modulus_Node();
		~Modulus_Node();
		int evaluate(int num1, int num2);
};

#endif // !defined MODULUS_NODE_H
