/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project1-Task B

A simple calculator that can add and subtract integers. */

#include <iostream>
#include <string>

using namespace std;
int main() {
  int num1;
  int num2;
  char opr;
  int sum=0;

  cin >> num1 >> opr >> num2;
   //first time
    if (opr == '-')
      sum = num1 - num2;
    else if (opr == '+')
      sum = num1 + num2;

    // in case there is only one input
    else {
      sum = num1;
    }

  while(cin >> opr >> num2) { // While the reading operation is a success
    if (opr == '-')
      sum = sum - num2;
    if (opr == '+')
      sum = sum + num2;
  }
  cout << sum;


}
