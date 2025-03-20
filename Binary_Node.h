#ifndef _BINARY_NODE_H_
#define _BINARY_NODE_H_


#include "Node.h"
#include "Visitor.h"


class Binary_Node : public Node
{
	public:
		Binary_Node();
		Binary_Node(int priority);
		~Binary_Node();
		int getPriority();
		Node* getLeft();
		Node* getRight();
		void setLeft(Node* left);
		void setRight(Node* right);
		void accept(Visitor* v);
		virtual int evaluate(int n1, int n2) = 0;

	private:
		Node *left_;
		Node *right_;
		int priority_;

};

#endif // !defined _BINARY_NODE_H_
