/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: recursion function of string.
E5.21
**/

#include <iostream>
#include <string>

using namespace std;

string reverse(string str);

int main() {

string word = "flow";
string word2 = reverse(word);
cout << word2;
//works!

 }


 string reverse(string str) {

   string word = "";

   if (str.length()>1)
    {
      word = (str[str.length()-1] + reverse(str.substr(0,str.length()-1)));
    }
  else
  {
    word = str[0];
  }

   return word;

 }
