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
	//cout << fst << " " << lst;
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

bool isFunction(string input){
	int index = 0;
	if(isalpha(input[index])){
		switch(input[index]){
			case 's':{if(input == "sqrt"){return true;}else if(input == "sin"){return true;};break;}
			case 'c':{if(input == "cos"){return true;} break;}
			default: {return false; break;}
		}
	}
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
double doFunction(string func, double var){
	const double pi = 3.14159265;
	switch(func[0]){
		case 's': {
		if(func[1] == 'q'){
			return sqrt(var);
			break;
		}else if(func[1] == 'i'){
			return sin((var * pi)/180);
		}
			break;
		}	
		case 'c': {
			return cos((var*pi)/180);
			break;
		}
	/**	case "sqrt":{
			return sqrt(var);
			break;
		}**/
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
		else if(isalpha(input[i])){
			int pos = i + 1;
			int size = 1;
			while(isalpha(input[pos]) && input[pos] != '('){
				pos++;
				size++;
			}
			
			string temp;
			temp.append(input.substr(i, size));
			string temp2;
			if(isFunction(temp)){
				size = 0;
				while(input[pos] != ')' && pos != input.length()){
					if(input[pos] == '('){
						pos++;
					}else{
						if(isdigit(input[pos])){
							size++;
							i = pos;
							pos++;
						}
					}
				}
				pos++;
				temp2.append(input.substr(i, size));
				double tempD = atof(temp2.c_str());
				stk.push(doFunction(temp, tempD));
				
			}
			//double tempD = atof(temp.c_str());
			//stk.push(atof(temp.c_str()));
			i = pos;
			
		}

	}
	return stk.top();
}


int main(){
	string userInput;
	string q;
	bool exit = false;
try{
	
	while(!exit){
	
	cout << "please input postfix string"<<endl;
	getline(cin, userInput);
	cout << "= " << evaluatePFexpression(userInput) << endl;
	cout << "press \'q\' to quit or any other button to input another expression" << endl;
	cout << "? ";
	cin >> q;
	if(q == "q"){
		exit = true;
	}else{
		exit = false;
		userInput = "";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	
	
	}
}
catch(string exceptionString){
	cout << exceptionString << endl;
}
		

	
	return 0;
}
