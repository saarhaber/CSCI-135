
/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E6.7

a function reverse that reverses the sequence of elements in an array
**/


#include <iostream>

using namespace std;
int reverse (int array [], int size);

int main() {

int myArray [] = {1, 4 ,9, 16, 9, 7 ,4 ,9, 11};
reverse (myArray , 9);
for (int i=0; i<9; i++) {
  cout << myArray[i] << " ";
}

}


int reverse (int array [], int size) {

//function that reverse an array of type int

int temp [size]; //array to insert the reverse order

for (int i=0; i<size; i++) {
  temp[i] = array[size-i-1];
}

//entering again from temp to the array
for (int i=0; i<size; i++) {
  array [i] = temp[i];
}
}
