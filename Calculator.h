#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <string>
#include "Math_Expr.h"
#include "Tree_Builder.h"


class Calculator
{
	public: 
		Calculator(void);
		Calculator(Expr_Builder * builder);
		~Calculator(void);
		void mainloop(void);
		int evaluate_expression(std::string infix);
	private:
		Expr_Builder * builder_;

			
		
};

#endif
