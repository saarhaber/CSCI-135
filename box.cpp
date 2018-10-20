/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4 - A


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

for (int i=0; i<height; i++) { //loop for number of lines
  for (int k=0; k<width; k++) { //loop for number of stars
    cout << "*";
  }
  cout << endl;
}



}
