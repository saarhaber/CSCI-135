/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E5.15

a function sort3(int& a, int& b, int& c)
that swaps its three arguments to arrange them
in sorted order.
**/

void sort2(int& a, int& b);
void sort3(int& a, int& b, int& c);

#include <iostream>
#include <string>

using namespace std;

  int main() {
  int v = 3;
  int w = 4;
  int x = 1;
  sort3(v, w, x); // v is now 1, w is now 3, x is now 4
  cout << "v is: " << v << endl;
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


void sort3(int& a, int& b, int& c) {
  sort2 (a, c);
  sort2 (b, c);
  sort2 (a, b);
}
