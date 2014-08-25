#include <iostream>
#include "expression.h"
#include <string>
using namespace std;
int Expression::evaluate(){
	return 0;	//default return value, never used
}
void Expression::prettyprint(){}	//never used
int LoneInt::evaluate(){
	return num;	
}
void LoneInt::prettyprint(){
	cout << num;
}
int UnaryOperation::evaluate(){
	num = expChild->evaluate();
	if (op == "ABS"){	//return abs value of num
		if(num > 0) return num;
		num *= -1;
	} else if (op == "NEG") {
		num *= -1;	//return negative value of num
	}
	return num;
}
void UnaryOperation::prettyprint(){
	if (op == "ABS"){
		cout << "|";	//print the expression inside this one as absolute
		expChild->prettyprint();
		cout << "|";
	} else if (op == "NEG") {
		cout << "-";
		expChild->prettyprint(); //print the expresion inside this one as negative
	}
}
int BinaryOperation::evaluate(){
	switch(op){	//return the operation performed on the two children expressions
		case '+':
			num = expChild1->evaluate() + expChild2->evaluate();
			break;
		case '-':
			num = expChild1->evaluate() - expChild2->evaluate();
			break;
		case '*':
			num = expChild1->evaluate() * expChild2->evaluate();
			break;
		case '/':
			num = expChild1->evaluate() / expChild2->evaluate();
			break;
	}
	return num;
}
void BinaryOperation::prettyprint() {
	cout << "(";	//print the children expressions with the operation around brackets
	expChild1->prettyprint();
	cout << " " << op << " ";
	expChild2->prettyprint();
	cout << ")";
}
