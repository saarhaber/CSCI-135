/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E8.3

A program that reads a text file containing floating-point numbers.
Print the average of the numbers in the file.
Allowing the user to specify the file name on the command-line.
If the user doesn’t specify any file name, then prompt the user for the name.
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main () {

string filename;
cout << "Please enter the file name: " << endl;
cin >> filename;
ifstream in_file;

in_file.open(filename.c_str());
while (in_file.fail()) {
  cout << "Error opening file. Enter a file name: " << endl;
  cin >> filename;
  cout << endl;
  in_file.open(filename.c_str());
}

float number;
float sum = 0;
float avg;
float counter = 0;

while (in_file >> number) {
  sum += number;
  counter++;
}

cout << "Avg of floating numbers is: " << sum/counter;


}
