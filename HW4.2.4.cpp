/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 4.2.4
*/

#include <iostream>
using namespace std;

int main()
{
   cout << "Enter an integer: " << endl;
   int n;
   cin >> n;
//making n positive if it's negetive to make it easier to preforme
  if (n<0)
    n*=(-1);
  else if (n==0)
    cout << 0;

  while (n>0) {
    int digit = n % 10;
    cout << digit;
    n=n/10;
  }

   cout << endl;

   return 0;
}
