/*
Author: Saar Haber
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Lab1A

A program that asks the user to input two integer numbers,
and prints out the smaller of the two.
*/

#include <iostream>

using namespace std;

int main()

{
int Num1;
int Num2;

cout << "Enter the first number: " << endl;
cin >> Num1;

cout << "Enter the second number: " << endl;
cin >> Num2;

if (Num1<Num2)
  cout << "The smaller number is " << Num1 << endl;
else if (Num2<Num1)
  cout << "The smaller number is " << Num2 << endl;
else
  cout << "The numbers are equal " << endl;
return 0;
}
