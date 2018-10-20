/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 3 - A

A program that asks the user to
input a string representing the date (in MM/DD/YYYY format),
and prints out the East basin storage on that day.. */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;
int main() {


  ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }

  string junk;        // new string variable
  getline(fin, junk); // read one line from the file


  string date, date1;
  cout << "Enter date: ";
  cin >> date1;

  double eastSt, eastE1, westSt, westE1;
  while(fin >> date >> eastSt >> eastE1 >> westSt >> westE1) {
      // this loop reads the file line-by-line
      // extracting 5 values on each iteration

      fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                            //ignorring the remaining columns

      // for example, to print the date and East basin storage:
      if (date == date1) {
        cout << "East basin storage: " << eastSt << " billion gallons" << endl;
        fin.close();
      }
    }














}
