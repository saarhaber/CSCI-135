/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 3 - C

A that asks the user to input two dates (the beginning and
the end of the interval). The program should check each day
in the interval and report which basin had higher elevation
on that day by printing “East” or “West”, or print “Equal”
if both basins are at the same level. */

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


  string date1, date2;
  cout << "Enter starting date: ";
  cin >> date1;
  cout << "Enter ending date: ";
  cin >> date2;

  double eastSt, eastE1, westSt, westE1; //declaring variabels of the loop
  string date;

  while(fin >> date >> eastSt >> eastE1 >> westSt >> westE1) {
      // this loop reads the file line-by-line
      // extracting 5 values on each iteration

      fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                            //ignorring the remaining columns
      if (date == date1) {                          //if the begining date
        if (eastE1 > westE1) {                       // doing it once
          cout << date << " East" << endl;
        }
        else if (eastE1 < westE1) {
          cout << date << " West" << endl;
        }
        else {
          cout << date << " Equal" << endl;
        }
        if (date1!=date2)
        while(fin >> date >> eastSt >> eastE1 >> westSt >> westE1) { //loop of the rest of the dates
            // this loop reads the file line-by-line
            // extracting 5 values on each iteration

            fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                                  //ignorring the remaining columns
            if (eastE1 > westE1) {
              cout << date << " East" << endl;
            }
            else if (eastE1 < westE1) {
              cout << date << " West" << endl;
            }
            else {
              cout << date << " Equal" << endl;
            }
            if (date == date2) {    //stops if got to the ending date
              fin.close();
            }
      }
    }

    }


}
