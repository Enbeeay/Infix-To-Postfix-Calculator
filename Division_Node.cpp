#include "Division_Node.h"

Division_Node::Division_Node()
	: Binary_Node(2)
{

}

Division_Node::~Division_Node()
{

}

int Division_Node::evaluate(int num1, int num2)
{
	return num1 / num2;
}

