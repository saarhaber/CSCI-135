/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 4.2.6
*/


#include <iostream>
#include <string>

using namespace std;

int main()
{
   cout << "Enter a word: " << endl;
   string s;
   string r="";
   cin >> s;
   int i=0;
   char c;

   while (i < s.length()) {
      c = s[i];
      r = c + r;
      i++;
    }
   cout << r;

   return 0;
}
