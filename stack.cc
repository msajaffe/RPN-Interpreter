#include "stack.h"
#include <iostream>
Expression * ExpressionStack::top(){
	return list[size-1];	//returns most recently added expression
}
int ExpressionStack::push(Expression * exp){
	if (size <= 9){	//adds new expression if size is less than 9 (allows for 10 expressions to be added)
		list[size] = exp; 
		size++;
		return 1;
	} else {
		std::cerr << "Stack Overflow";
		return 0;
	}
}
void ExpressionStack::pop(){
	size--;
}