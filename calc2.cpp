/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project1-Task C

A simple calculator that can add and subtract integers. */

#include <iostream>
#include <string>

using namespace std;
int main() {
  int num;
  char opr;
  int sum=0;
 //first time
  cin >> num;
  sum = num;

  while(cin >> opr >> num) { // While the reading operation is a success
    if (opr == '-')
      sum = sum - num;
    else if (opr == '+')
      sum = sum + num;
    else
      { //when a line ends
      cout << sum << endl;
      sum = num;
      }
  }
cout << sum; //printing the last one
}
