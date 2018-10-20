/*
Author: Saar Haber
Course: CSCI-136
Instructor: Gewenel Gatto
Assignment: Lab2A

a program which asks the user to input an integer in the range 0 < n < 100. If the number is out of range, the program keep asking to re-enter until a valid number is input.

After a valid value is obtained, prints this number n squared.
*/

#include <iostream>
using namespace std;
int main() {

	int n;
	cout << "Enter a number between 0 and 100: ";
	cin >> n;

	while (n<=0 || n>=100) {
	cout << "please re-enter: ";
	cin >> n;
	}

	//ns is n squared
	int ns;
	ns=n*n;
	cout << "Number squared is: " << ns;

}
