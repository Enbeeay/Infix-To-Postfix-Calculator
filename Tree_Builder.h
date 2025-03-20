#ifndef TREE_BUILDER_H
#define TREE_BUILDER_H


#include "Expr_Builder.h"
#include "Number_Node.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"
#include "Stack.h"
#include "Tree.h"
#include "Calculator.h"

class Tree_Builder : public Expr_Builder
{
	public:
		Tree_Builder();
		~Tree_Builder();
		void start_expression(void);
		void build_number(int n);
		void build_add_operator(void);
		void build_subtract_operator(void);
		void build_multiply_operator(void);
		void build_divide_operator(void);
		void build_modulus_operator(void);
		void build_open_parenthesis(void);
		void build_closed_parenthesis(void);
		void insert_binary_operator(Binary_Node* node);
		void end_expression(void);
		Tree * get_expression(void);
	private:
		Stack<Binary_Node *> operator_stack;
		Stack<Node *> operand_stack;
		Tree * expr_tree_;

};

#endif
