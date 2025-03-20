#include "Subtraction_Node.h"

Subtraction_Node::Subtraction_Node()
	: Binary_Node(1)
{

}

Subtraction_Node::~Subtraction_Node()
{

}

int Subtraction_Node::evaluate(int num1, int num2)
{
	return num1 - num2;
}

