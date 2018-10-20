/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4 - C

diagonal cross
**/

#include <iostream>
#include <string>

using namespace std;

int main() {

int size; //declaring size
cout << "Input size: " << endl;
cin >> size;

cout << "Shape: " << endl;

for (int row=0; row<size; row++) { // lines
  for (int col=0; col<size; col++) { // stars and spaces
    if (row == col || (row + 1 == size - col)) {
      cout << "*";
    }
    else {
      cout << " ";
    }
  }
  cout << endl;
}



}
