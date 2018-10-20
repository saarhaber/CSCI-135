/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E5.14

a function void sort2(int& a, int& b) that swaps the values
of a and b if a is greater than b and otherwise leaves
a and b unchanged.
**/

void sort2(int& a, int& b);

#include <iostream>
#include <string>

using namespace std;

int main() {
  int u = 2;
  int v = 3;
  int w = 4;
  int x = 1;
  sort2(u, v); // u is still 2, v is still 3
  sort2(w, x); // w is now 1, x is now 4
  cout << "w is: " << w << endl;
  cout << "x is: " << x << endl;
}


void sort2(int& a, int& b) {
  int temp = b;
  if (a > b) {
    b = a;
    a = temp;
  }
}
