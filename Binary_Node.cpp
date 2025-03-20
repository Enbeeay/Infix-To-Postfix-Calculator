#include "Binary_Node.h"

Binary_Node::Binary_Node()
	: Node(), priority_(0), left_(nullptr), right_(nullptr)
{

}

Binary_Node::Binary_Node(int priority)
	: Node(), priority_(priority), left_(nullptr), right_(nullptr)
{

}

Binary_Node::~Binary_Node()
{

}

Node* Binary_Node::getLeft()
{
	return left_;
}

Node* Binary_Node::getRight()
{
	return right_;
}

void Binary_Node::setLeft(Node* left)
{
	left_ = left;
}

void Binary_Node::setRight(Node* right)
{
	right_ = right;
}

int Binary_Node::getPriority()
{
	return priority_;
}

void Binary_Node::accept(Visitor* v)
{
	v->visit(*this);
}
