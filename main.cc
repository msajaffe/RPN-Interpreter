#include <iostream>
#include "expression.h"
#include "stack.h"
#include <string>
#include <sstream>
using namespace std;
int main(){
	ExpressionStack stack;
	int n;
	char c;
	string s;
	while (true){
		if(cin.eof()) break;
		while (cin >> n){	//if a number is encountered
			Expression * li = new LoneInt(n);	//convert it into a lone integer
			if(!stack.push(li)) break; 		// push the new lone integer onto the stack
											// if stack.push(li) returns true(1), that means stack overflow
		}									//keep doing this until encounter character/eof
		if(cin.eof()) break;	//if you reach the end of the file, then good day.
		cin.clear();			//if not then cin >> n had an error and you have to clear it
		cin.seekg(-sizeof(char), ios::cur); 	//move the cin back one character since it went forward into an int last time
		while (cin >> c){						//now cin for characters
		if(cin.eof()) break;
			if (c >= '0' && c<= '9') { 					//if the character is actually a number..
				cin.seekg(-sizeof(char), ios::cur); 	//then move the cin back so it can get that number again later
				break; 		//and break out of the character loop
			}
			switch(c){		// else, c can either be 'A', 'N', or on the binary operations (+, -, *, or /)
				case 'A':{	// c == 'A' implies the rest of the word will be BS
					UnaryOperation * uo = new UnaryOperation(stack.top(), "ABS");	//create the expression
					stack.pop();	//pop last expression
					stack.push(uo); //push new one
					cin.ignore(256,' '); //move to next word in input
					break;
				} case 'N': {	//same idea
					UnaryOperation * uo = new UnaryOperation(stack.top(), "NEG");
					stack.pop();
					stack.push(uo);
					cin.ignore(256,' ');
					break;
				}	
				default:	//same idea
						Expression * li1 = stack.top();
						stack.pop();
						Expression * li2 =  stack.top();
						stack.pop();
						BinaryOperation * bo = new BinaryOperation(li2, li1, c);
						stack.push(bo);
			}
		}
		if(cin.eof()) break;
		cin.clear();
	}
	stack.top()->prettyprint();	// onceall input has been read, the top of the stack contains the expression that contains all expressions
	cout << endl;
	cout << "= " << stack.top()->evaluate() << endl; // so you print and evaluate it.
	//gg
}