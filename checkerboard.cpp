/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4 - B

rectengular shape of asterisks
**/

#include <iostream>
#include <string>

using namespace std;

int main() {

int width, height; //declaring width and height
cout << "Input width: " << endl;
cin >> width;
cout << "Input height: " << endl;
cin >> height;

cout << "Shape: " << endl;

for (int row=0; row<height; row++) { // lines
  for (int col=0; col<width; col++) { // stars and spaces
    if (row % 2 == 0 && col % 2 == 0) {
      cout << "*";
    }
    else if (row % 2 == 0 && col % 2 != 0) {
      cout << " ";
    }
    else if (row % 2 != 0 && col % 2 == 0) {
      cout << " ";
    }
    else {
      cout << "*";
    }
  }
  cout << endl;
}



}
