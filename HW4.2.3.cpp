/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 4.2.3
*/

#include <iostream>
using namespace std;

int main()
{
   cout << "Enter a positive integer: " << endl;
   int n;
   cin >> n;

  while (n>0) {
    int digit = n % 10;
    cout << digit;
    n=n/10;
  }

   cout << endl;

   return 0;
}
