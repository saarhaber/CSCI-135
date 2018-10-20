/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 6 - A;

 A program test-ascii.cpp that asks the user to input a line of text
 (which may possibly include spaces). The program should report all
 characters from the input line together with their ASCII codes.

**/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main () {

string s;
cout << "Input: ";
getline(cin, s);
cout << endl;

for (int i=0; i<s.length(); i++)  {
  cout << s[i] << " " << int(s[i]) << endl;
}

}
