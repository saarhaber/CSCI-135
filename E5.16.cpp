/*
/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E 5.16

A function that computes the weekday of a given date,
using a formula known as Zeller’s congruence. Let
d = the day of the month
mm = the modified month (3 = March, ..., 12 = December, 13 = January, 14 = February)
w = the weekday (0 = Monday, 1 = Tuesday, ..., 6 = Sunday)
then Zeller's congruence.
**/

#include <iostream>
#include <string>

using namespace std;


string zeller (int day, int month, int year);

int main() {

  int day, month, year;
  cout << "Insert Day:" << endl;
  cin >> day;
  cout << "Insert Month:" << endl;
  cin >> month;
  cout << "Insert Year:" << endl;
  cin >> year;

  cout << zeller(day, month, year);
}

/**
  Zeller's congruence
  @param day day of the date
  @param month month of the date
  @param year year of the date
  @return the day in the week
*/
string zeller (int d, int mn, int y) {

  string weekday_name;
  int w;
  if (mn == 1)
  {
    mn = 13;
    y -= 1;
  }
  if (mn == 2)
  {
    mn = 14;
    y -= 1;
  }

 w = (d + 5 +
    (26 * (mn+1))/10 +
    5*(y%100)/4 +
    21*(y/100)/4 ) % 7;

switch (w)
{
   case 6: weekday_name = "Sunday"; break;
   case 0: weekday_name = "Monday"; break;
   case 1: weekday_name = "Tuesday"; break;
   case 2: weekday_name = "Wednesday"; break;
   case 3: weekday_name = "Thursday"; break;
   case 4: weekday_name = "Friday"; break;
   case 5: weekday_name = "Saturday"; break;
   default: weekday_name = "Error"; break;
}

return weekday_name;
}
