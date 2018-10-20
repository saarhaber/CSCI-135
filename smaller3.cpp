/*
Author: Saar Haber
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Lab1A

A program that asks the user to input three integer numbers,
and prints out the smallest of the three.
*/

#include <iostream>

using namespace std;

int main()

{
int Num1;
int Num2;
int Num3;
int Temp;

cout << "Enter the first number: " << endl;
cin >> Num1;

cout << "Enter the second number: " << endl;
cin >> Num2;

cout << "Enter the third number: " << endl;
cin >> Num3;

//checking which number is smaller between the first two//
if (Num1<Num2)
  Temp=Num1;
else
  Temp=Num2;

//what is smaller between Temp and Num3//
if (Temp<Num3)
  cout << "The smaller of the three is " << Temp;
else
  cout << "The smaller of the three is " << Num3;

return 0;
}
