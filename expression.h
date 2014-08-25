#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__
#include <string>
class LoneInt;
class Expression{
	public:
		virtual int evaluate(); //returns value of expression
		virtual void prettyprint(); //prints the expression
};
class LoneInt: public Expression{
	int num; //num is the value of all expressions
	public:
		void prettyprint();
		int evaluate();
		LoneInt(int num): num(num){}
		~LoneInt(){}
};
class UnaryOperation: public Expression{ 
	int num;
	Expression * expChild;	//the expression to apply the op too
	std::string op;	//type of unary op
	public:
		void prettyprint();
		int evaluate();
		UnaryOperation(Expression * exp, std::string op): expChild(exp), op(op){}
		~UnaryOperation() {
			delete expChild;
		}
		
};
class BinaryOperation: public Expression{ //same idea
	int num;
	Expression * expChild1;
	Expression * expChild2;
	char op;
	public:
		void prettyprint();
		int evaluate();
		BinaryOperation(Expression * exp1, Expression * exp2,  char op): expChild1(exp1), expChild2(exp2), op(op){}
		~BinaryOperation() {
			delete expChild1;
			delete expChild2;
		}
};
#endif