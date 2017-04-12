#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

bool isOperator(char op){
	string opStr = "*-+/%";
	for(int i =0; i<opStr.length(); i++){
		if(op==opStr[i]){
			cout << op;
			return true;
			break;
		}
	}
	return false;
}
double doExpression(char op, double lst, double fst){
	switch(op){
		case '*': {return lst*fst; break;}
		case '-': {return fst - lst; break;}
		case '/': {return fst / lst; break;}
		case '%': //{return fst % lst; break;}
		default: {return fst + lst; break;}
	}
}
double evaluatePFexpression(string input){
	stack<double> stk;
	stk.push(1);
	stk.push(2); 
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
			}
			
		}
		/**else if(isdigit(input[i])){
			int pos = i + 1;
			int size = 1;
			while(isdigit(input[pos])){
				pos++;
				size++;
			}
			string temp;
			//temp.resize(size);
			temp.append(input.substr(i, size));
			//temp.erase(remove(input.begin(), input.end(), " "),input.end());
			double tempD = atof(temp.c_str());
			cout << "temp:"<< temp;
			cout << "tempD: "<<tempD;
			stk.push(atof(temp.c_str()));
		}**/
	}
	return stk.top();
	
}


int main(){
	string userInput;
	cout << "please input postfix string"<<endl;
	cin >> userInput;
	cout << "= " << evaluatePFexpression(userInput) << endl;
	
	return 0;
}
