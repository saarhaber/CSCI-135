/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4 - F

prints upside-down trapezoid
**/

#include <iostream>
#include <string>

using namespace std;

int main() {

int height, width; //declaring height, width
cout << "Input width: " << endl;
cin >> width;
cout << "Input height: " << endl;
cin >> height;

int spaces = 0;
int stars = width;

cout << "Shape: " << endl;

if (height*2 <= (width + 1)) {
for (int row=0; row<height; row++) { // lines
    for(int i=0; i<spaces; i++){
        cout << " ";
      }
    for (int k=0; k<stars; k++){
        cout << "*";
    }

    spaces += 1;
    stars -= 2;

    cout << endl;
  }

}
else {
  cout << "Impossible shape!";
}



}
