/*
Author: Saar Haber
Course: CSCI-136
Instructor: Gewenel Gatto
Assignment: Lab2C

A program  that creates an array of 10 integers,
and provides the user with an interface to edit any of its elements.
*/

#include <iostream>
using namespace std;
int main() {

int myData[10];
int i,v;
for (i=0; i<10; i++){
	myData[i]=1;
}


do {
for (i=0; i<10; i++){
	cout << myData[i] << " ";
	}

cout << endl;
cout << "Input index: ";
cin >> i;
cout << "Input value: ";
cin >> v;

if (i<10 && i>=0)
	myData[i]=v;
else
	return 0;

} while (i<10 && i>=0);


}
