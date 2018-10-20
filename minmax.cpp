/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 3 - B

A program that finds the minimum and
maximum storage in East basin in 2016. */

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


  double min = 9999999, max = 0.0;

  double eastSt, eastE1, westSt, westE1; //declaring the variables that are in the loop
  string date;

  while(fin >> date >> eastSt >> eastE1 >> westSt >> westE1) {
      // this loop reads the file line-by-line
      // extracting 5 values on each iteration

      fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                            //ignorring the remaining columns

      if (eastSt < min) {
        min = eastSt;
      }
      if (eastSt > max) {
        max = eastSt;
      }

  }

fin.close();

cout << "Minimum storage in East basin: " << min << " billion gallons " << endl;
cout << "Maximum storage in East basin: " << max << " billion gallons " << endl;

    }
