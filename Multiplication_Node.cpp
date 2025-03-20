#include "Multiplication_Node.h"

Multiplication_Node::Multiplication_Node()
	: Binary_Node(2)
{

}

Multiplication_Node::~Multiplication_Node()
{

}

int Multiplication_Node::evaluate(int num1, int num2)
{
	return num1 * num2;
}
