#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
double power(double fst, double lst){
	double value = fst;
	cout << fst << " " << lst;
	for(int i = 0; i < lst -1; i++){
		value *= fst;
	}
	return value;
}

bool isOperator(char op){
	string opStr = "*-+/%^";
	for(int i =0; i<opStr.length(); i++){
		if(op==opStr[i]){
			//cout << op;
			return true;
			//break;
		}
	}
	
	return false;
}
double doExpression(char op, double lst, double fst){
	switch(op){
		case '*': {return lst*fst; break;}
		case '-': {return fst - lst; break;}
		case '/': {return fst / lst; break;}
		case '^': {double val = power(fst, lst); return val; break;}
		default: {return fst + lst; break;}
	}
}
double evaluatePFexpression(string input){
	stack<double> stk;
	for(int i = 0; i < input.length(); i++){
		if(isOperator(input[i])){
			if(stk.empty()){
				throw "stack underflow. check you input and try again";
			}else{
				double num1, num2;
				num1 = stk.top();
				stk.pop();
				num2 = stk.top();
				stk.pop();
				stk.push(doExpression(input[i], num1, num2));
			//	cout << num1 << " lst" << endl;
			//	cout << num2 << 
			}
			
		}
		else if(isdigit(input[i])){
			int pos = i + 1;
			int size = 1;
			while(isdigit(input[pos])){
				pos++;
				size++;
			}
			string temp;
			temp.append(input.substr(i, size));
			double tempD = atof(temp.c_str());
			stk.push(atof(temp.c_str()));
			i = pos;
		}
	}
	return stk.top();
}


int main(){
	string userInput;
	cout << "please input postfix string"<<endl;
	getline(cin, userInput);
	try{
		cout << "= " << evaluatePFexpression(userInput) << endl;	
	}
	catch(string exceptionString){
		cout << exceptionString << endl;
	}
	
	return 0;
}
