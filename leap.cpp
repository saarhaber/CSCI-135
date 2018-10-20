/*
Author: Saar Haber
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Lab1c

A program that asks the user to input an integer
representing a year number (1999, 2016, etc.).
If the input year is a leap year according to the
modern Gregorian calendar, it should print Leap year,
otherwise, print Common year.
*/

#include <iostream>

using namespace std;

int main()

{
int year;

cout << "Enter year: " << endl;
cin >> year;

if (year%4!=0)
  cout << "Common year";
else if (year%100!=0)
  cout << "Leap year";
else if (year%400!=0)
  cout << "Common year";
else
  cout << "Leap year";

return 0;
}
