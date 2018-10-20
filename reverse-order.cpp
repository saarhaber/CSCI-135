/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 3 - D

A program which asks the user to input two dates (earlier
date then later date). The program should report the West
basin elevation for all days in the interval in the reverse
chronological order (from the later date to the earlier). */

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


  string dateE, dateL;
  cout << "Enter earlier date: ";
  cin >> dateE;
  cout << "Enter later date: ";
  cin >> dateL;

  double eastSt, eastE1, westSt, westE1; //declaring variabels of the loop
  string date;

  const int COUNT = 370;
  double elevation[COUNT]; //arrays for the data
  string dates[COUNT];
  int i=0;


  while(fin >> date >> eastSt >> eastE1 >> westSt >> westE1) {
      // this loop reads the file line-by-line
      // extracting 5 values on each iteration

      fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                            //ignorring the remaining columns
  if (date == dateE){
    elevation [i] = westE1;
    dates [i] = date;

    if (dateE != dateL) { //in case of only one date;

      i++;

  while(fin >> date >> eastSt >> eastE1 >> westSt >> westE1) {
      // this loop reads the file line-by-line
      // extracting 5 values on each iteration


      fin.ignore(INT_MAX, '\n'); //skips to the end of line,
                            //ignorring the remaining columns
      elevation [i] = westE1;
      dates [i] = date;
      i++;

      if (date == dateL) {
        i--;
        fin.close();
      }

    }
  }
  }

}

    for (int k = i; k>-1; k--) {
      cout << dates[k] << " " << elevation[k] << " ft" << endl;
    }

}
