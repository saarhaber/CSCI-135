/*
Author: Saar Haber
Course: CSCI135
Instructor: Gennady Maryash
Assignment: Project1-Task D
a calculator that does squaring as well
*/
//include libraries
#include <iostream>
#include <string>
using namespace std;

int main (){
	char s; //sign
	int sum, num1;
	bool operation = true;
	cin >> num1;
	sum = num1; //first time

	while (cin>> s){
		if ((s == '+') || (s == '-') || (s == '^') || (s == ';')){
			if ( s == '^'){
				if (operation == true) {
					sum = sum - num1;
					num1 = num1 * num1;
					sum = sum + num1;
				}
				if (operation == false){
					sum = sum + num1;
					num1 = num1 * num1;
					sum = sum - num1;
				}
			}
			else if ( s == '+'){		//+ operation
				cin >> num1;
				operation = true;
				sum = sum + num1;
			}
			else if ( s == '-'){		// - operation
				cin >> num1;
				operation = false;
				sum = sum - num1;
			}
			else if (s == ';'){
				operation = true;
				cout << sum << endl;
				sum = 0;
				cin>> num1;
				sum = num1;
			}
		}
	}
	return 0;
}
