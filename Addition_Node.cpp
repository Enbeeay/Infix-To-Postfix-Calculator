#include "Addition_Node.h"

Addition_Node::Addition_Node()
	: Binary_Node(1)
{

}

Addition_Node::~Addition_Node()
{

}

int Addition_Node::evaluate(int num1, int num2)
{
	return num1 + num2;
}
