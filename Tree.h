#ifndef TREE_H
#define TREE_H

#include "Tree_Visitor.h"
#include "Node.h"
#include "Math_Expr.h"

class Tree : public Math_Expr
{
	public:

		Tree(void);
		Tree(Node* root, Tree_Visitor* visitor);
		~Tree();
		Node* get_root(void);
		void set_root(Node* root);
		bool is_empty(void);
		int evaluate(void);


	private:
		Node* root_;
		Tree_Visitor* visitor_;
		

};

#endif // !defined TREE_H
