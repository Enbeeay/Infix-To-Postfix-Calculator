#ifndef VISITOR_H
#define VISITOR_H

#include "Stack.h"

class Binary_Node;
class Number_Node;


class Visitor
{
	public:
		Visitor();
		~Visitor();

		virtual void visit(Binary_Node& node) = 0;
		virtual void visit(Number_Node& node) = 0;

};

#endif // !defined VISITOR_H

