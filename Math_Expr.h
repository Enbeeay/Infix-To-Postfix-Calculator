#ifndef MATH_EXPR_H
#define MATH_EXPR_H

class Math_Expr
{
	public:	
		Math_Expr(void);
		virtual ~Math_Expr(void);
		virtual int evaluate(void) = 0;
};

#endif // !defined MATH_EXPR_H

