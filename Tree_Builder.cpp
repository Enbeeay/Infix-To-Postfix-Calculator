#include "Tree_Builder.h"
#include <stdexcept>
#include <sstream>

Tree_Builder::Tree_Builder()
	: Expr_Builder(), expr_tree_(new Tree())
{
	
}

Tree_Builder::~Tree_Builder()
{
	delete expr_tree_;
}

void Tree_Builder::start_expression(void)
{
	expr_tree_ = new Tree();
}

void Tree_Builder::build_number(int n)
{
	Number_Node * num = new Number_Node(n);
	
	operand_stack.push(num);
}

void Tree_Builder::insert_binary_operator(Binary_Node* node)
{

	if (operator_stack.is_empty())
	{
		operand_stack.push(node);
	}

	while (!operator_stack.is_empty())
	{
		if(operator_stack.top()->getPriority() < node->getPriority())
		{ 
			operator_stack.push(node);
		}
		else
		{
			Binary_Node * temp = operator_stack.top();
			operator_stack.pop();
			temp->setRight(operand_stack.top());
			operand_stack.pop();
			temp->setLeft(operand_stack.top());
			operand_stack.pop();
			operand_stack.push(temp);
		}
	}
	
}


void Tree_Builder::build_open_parenthesis(void)
{
	std::string infix;

	Calculator c;

	// Start a new expression tree for the parenthesis

	// Find first closing parenthesis in infix that matches the open parenthesis

	int open_parenthesis = 1;
	int close_parenthesis = 0;
	int i = 0;
	while (open_parenthesis != close_parenthesis)
	{
		if (infix[i] == '(')
		{
			open_parenthesis++;
		}
		else if (infix[i] == ')')
		{
			close_parenthesis++;
		}
	}

	std::string sub_infix = infix.substr(1, i - 1);

	int result = c.evaluate_expression(infix);

	Number_Node * num = new Number_Node(result);

	operand_stack.push(num);

	std::stringstream ss;

	ss << infix.substr(i);
}

void Tree_Builder::build_closed_parenthesis(void)
{
	while (operator_stack.top()->getPriority() != 0)
	{
		Binary_Node * temp = operator_stack.top();
		operator_stack.pop();
		temp->setRight(operand_stack.top());
		operand_stack.pop();
		temp->setLeft(operand_stack.top());
		operand_stack.pop();
		operand_stack.push(temp);
	}
}

void Tree_Builder::build_add_operator(void)
{
	Addition_Node * add = new Addition_Node();
	insert_binary_operator(add);
}

void Tree_Builder::build_subtract_operator(void)
{
	Subtraction_Node * sub = new Subtraction_Node();
	insert_binary_operator(sub);
}

void Tree_Builder::build_multiply_operator(void)
{
	Multiplication_Node * mult = new Multiplication_Node();
	insert_binary_operator(mult);
}

void Tree_Builder::build_divide_operator(void)
{
	Division_Node * div = new Division_Node();
	insert_binary_operator(div);
}

void Tree_Builder::build_modulus_operator(void)
{
	Modulus_Node * mod = new Modulus_Node();
	insert_binary_operator(mod);
}

void Tree_Builder::end_expression(void)
{
	while (!operator_stack.is_empty())
	{
		Binary_Node * temp = operator_stack.top();
		operator_stack.pop();
		temp->setRight(operand_stack.top());
		operand_stack.pop();
		temp->setLeft(operand_stack.top());
		operand_stack.pop();
		operand_stack.push(temp);
	}

	expr_tree_->set_root(operand_stack.top());
}

Tree* Tree_Builder::get_expression(void)
{
	return expr_tree_;
}
