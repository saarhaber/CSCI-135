/*
Author: Saar Haber
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Lab1A

A program that asks the user to input the year and the month (1-12)
and prints the number of days in that month (taking into account leap years).
You may not use switch case or arrays even if you know these language constructs.
*/

#include <iostream>

using namespace std;

int main()

{
int year;
int month;

cout << "Enter year: " << endl;
cin >> year;

cout << "Enter month: " << endl;
cin >> month;

if (year%4!=0 && month==2)
  cout << "28";
else if (year%100!=0 && month==2)
  cout << "29";
else if (year%400!=0 && month==2)
  cout << "28";
else if (month==2)
  cout << "29";
else if ((month%2!=0 && month<8) || (month>7 && month%2==0))
  cout << "31 days" ;
else
  cout << "30 days" ;

return 0;
}
