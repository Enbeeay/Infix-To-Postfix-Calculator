#include "Calculator.h"
#include <iostream>
#include <sstream>

Calculator::Calculator(void) 
	: builder_(new Tree_Builder())
{ }

Calculator::Calculator(Expr_Builder * builder)
	: builder_(builder)
{ }

Calculator::~Calculator(void) { }

void Calculator::mainloop(void)
{
	std::string infix;

	while (true)
	{
		// Get input from user
		std::cout << "Enter expression: ";
		std::getline(std::cin, infix);
		if (infix == "QUIT")
		{
			break;
		}
		else
		{
			std::cout << evaluate_expression(infix) << std::endl;
			
		}
	}
}



int Calculator::evaluate_expression(std::string infix)
{

	std::stringstream input(infix);
	std::string token;
	builder_->start_expression();
	while (getline(input, token, ' '))
	{
		if (token == "+")
		{
			builder_->build_add_operator();
		}
		else if (token == "-")
		{
			builder_->build_subtract_operator();
		}
		else if (token == "*")
		{
			builder_->build_multiply_operator();
		}
		else if (token == "/")
		{
			builder_->build_divide_operator();
		}
		else if (token == "%")
		{
			builder_->build_modulus_operator();
		}
		else if (token == "(")
		{
			builder_->build_open_parenthesis();
		}
		else if (token == ")")
		{
			builder_->build_closed_parenthesis();
		}
		else
		{
			int number;
			std::istringstream(token) >> number;
			builder_->build_number(number);
		}
	}

	builder_->end_expression();

	Math_Expr * expr = builder_->get_expression();

	return expr->evaluate();

}
