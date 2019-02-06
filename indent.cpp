/*
Author: your name
Course: CSCI-136
Instructor: Genady Maryash
Assignment: LAB 7 - B

Counting blocks opened and closed by { and }, and adding real indentation
*/


#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// removing spaces before string
string removeLeadingSpaces(string line);

//scans the line and returns the number of occurrences of the character c
int countChar(string line, char c);


int main() {

string line;
int opened = 0;
int TabCounter = 0;
int AddToOpen;
char c1 = '{';
char c2 = '}';
string correctLine;

while (getline(cin,line))
{
  //getting line without spaces
  correctLine = removeLeadingSpaces(line);

  //adding a tab if there a new block

    AddToOpen = countChar (correctLine, c1);
    opened += AddToOpen;

  //if the a block was closed then one less tab
  for (int i=0; i<correctLine.length(); i++) {


    if (correctLine[i] == c2) {
      opened--;
    }

  }
  if (correctLine[0] == c2 && AddToOpen<=1) {
    TabCounter--;
  }


  for (int i=0; i<TabCounter; i++){
    cout << "\t";
  }

  TabCounter = opened;

  cout << correctLine << endl;
}
}


// removing spaces before string
string removeLeadingSpaces(string line) {

int i=0;
string correct = "";
while (isspace(line[i])) {
  i++;
}

correct = line.substr(i,line.length());

return correct;

}


//scans the line and returns the number of occurrences of the character c
int countChar(string line, char c) {

  int countOpened = 0;

  for (int i = 0; i < line.length(); i++) {
    if (line[i] == c) {
      countOpened++;
    }
  }

  return countOpened;

}
