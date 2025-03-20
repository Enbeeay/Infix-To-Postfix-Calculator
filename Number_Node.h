#ifndef _NUMBER_NODE_H_
#define _NUMBER_NODE_H_

#include "Node.h"
#include "Visitor.h"

class Number_Node : public Node {
	public:
		Number_Node();
		Number_Node(int number);
		~Number_Node();
		int getNumber();
		void accept(Visitor* v);

	private:
		int number_;
};

#endif // !defined NUMBER_NODE_H
