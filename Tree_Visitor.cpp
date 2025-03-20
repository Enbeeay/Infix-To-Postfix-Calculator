#include "Tree_Visitor.h"


Tree_Visitor::Tree_Visitor(void)
	: stack_(Stack<int>())
{

}

Tree_Visitor::~Tree_Visitor(void)
{

}

void Tree_Visitor::visit(Binary_Node& node)
{
	node.getLeft()->accept(this);
	node.getRight()->accept(this);

	int right = stack_.top();
	stack_.pop();
	int left = stack_.top();
	stack_.pop();

	stack_.push(node.evaluate(left, right));


}

void Tree_Visitor::visit(Number_Node& node)
{
	stack_.push(node.getNumber());
}

int Tree_Visitor::result(void) const
{
	return stack_.top();
}