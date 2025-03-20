#ifndef TREE_VISITOR_H
#define TREE_VISITOR_H

#include "Binary_Node.h"
#include "Number_Node.h"


class Tree_Visitor : public Visitor
{
	public:
		Tree_Visitor();
		~Tree_Visitor();
		void visit(Binary_Node& node);
		void visit(Number_Node& node);
		int result() const;

	private:
		Stack<int> stack_;

};

#endif // !defined TREE_VISITOR_H