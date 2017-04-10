#include <string>
#include <iostream>
#include <stack>
#include <cctype>
#include <cstdlib>
using namespace std;

stack<int> numStack;
stack<char> operatorStack;

const char white =' ';
const char leftP = '(';
const char rightP = ')';
string operators = "+-*/";

bool isOperator(char op){
	for(unsigned i = 0; i < operators.length();i++ ){
		if(op == operators[i]){
			return true;
		}
	}
	return false;
}
void scanString(string input){
	string digit ="";
	unsigned int start = 0;
	while(start < input.length()){
		if(input[start]== leftP){
			start++;
			while(isdigit(input[start])){
				digit.append(input,start,1);
				start++;
			}
			numStack.push(atoi(digit.c_str()));
			digit = "";
		}
		else if(input[start] == white){
			start++;
		}
		else if(isOperator(input[start])){
			operatorStack.push(input[start]);
			start++;
		}
		else if(input[start] == rightP){
			/**int num1,num2;
			char op;
			num1 = numStack.top();
			numStack.pop();
			num2 = numStack.top();
			numStack.pop();
			op = operatorStack.top();
			operatorStack.pop();
			numStack.push(pop(op, num1, num2));
			start++;**/
		}else{
			start++;
		}
		
	}
}

