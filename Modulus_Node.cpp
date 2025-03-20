#include "Modulus_Node.h"

Modulus_Node::Modulus_Node()
	: Binary_Node(2)
{

}

Modulus_Node::~Modulus_Node()
{

}

int Modulus_Node::evaluate(int num1, int num2)
{
	return num1 % num2;
}

