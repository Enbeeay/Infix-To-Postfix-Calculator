#include "Tree.h"

Tree::Tree(void)
	: root_(nullptr), visitor_(new Tree_Visitor())
{

}

Tree::Tree(Node* root, Tree_Visitor* visitor)
	: root_(root), visitor_(visitor)
{ }

Tree::~Tree()
{
	delete root_;
}

Node* Tree::get_root(void)
{
	return root_;
}

void Tree::set_root(Node* root)
{
	root_ = root;
}

bool Tree::is_empty(void)
{
	return root_ == nullptr;
}

int Tree::evaluate()
{
	root_->accept(visitor_);
	return visitor_->result();
}