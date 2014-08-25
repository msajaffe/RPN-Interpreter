#ifndef __STACK_H__
#define __STACK_H__
#include "expression.h"

class ExpressionStack{
	Expression ** list;	//list of expression pointers
	int size;	// num of expressions in stack
	public:
	ExpressionStack():size(0), list(new Expression*[10]){}
	~ExpressionStack(){
		delete [] list;
	}
	//standard stack functions
	Expression * top();
	int push(Expression *);
	void pop();
};
#endif