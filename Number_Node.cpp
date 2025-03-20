#include "Number_Node.h"

Number_Node::Number_Node()
	: number_(0)
{

}

Number_Node::Number_Node(int number)
	: number_(number)
{

}

Number_Node::~Number_Node()
{

}

int Number_Node::getNumber()
{
	return number_;
}

void Number_Node::accept(Visitor* v)
{
	v->visit(*this);
}