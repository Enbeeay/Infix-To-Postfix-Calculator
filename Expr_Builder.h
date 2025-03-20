#ifndef EXPR_BUILDER_H
#define EXPR_BUILDER_H

#include "Math_Expr.h"

class Expr_Builder
{
	public:
		Expr_Builder(void);
		virtual ~Expr_Builder(void) = 0;
		virtual void start_expression(void) = 0;
		virtual void build_number(int n) = 0;
		virtual void build_add_operator(void) = 0;
		virtual void build_subtract_operator(void) = 0;
		virtual void build_multiply_operator(void) = 0;
		virtual void build_divide_operator(void) = 0;
		virtual void build_modulus_operator(void) = 0;
		virtual void build_open_parenthesis(void) = 0;
		virtual void build_closed_parenthesis(void) = 0;
		virtual Math_Expr * get_expression(void) = 0;
		virtual void end_expression(void) = 0;

};

#endif