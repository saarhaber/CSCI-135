/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4 - D

prints bottom-half of a square
**/

#include <iostream>
#include <string>

using namespace std;

int main() {

int length; //declaring length
cout << "Input side length: " << endl;
cin >> length;

cout << "Shape: " << endl;

for (int row=0; row<length; row++) { // lines
  for (int col=0; col<length; col++) { // stars
    if (col <= row) {
      cout << "*";
    }
  }
  cout << endl;
}



}
