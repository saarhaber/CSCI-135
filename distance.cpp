// my first cpp program
/* this program asks a user for the coordinates of two points and then tells them the distance
between those points */

#include <iostream>  //The built-in library for input/output
#include <string> // library of string
#include <math.h>
using namespace std; //The names of standard definitions


int Maximum1 (int x, int y);
int Manhattan1 (int x, int y);
double Euclidean1 (int x, int y);

int main ()          //C++ programs all have a main() function
{ cout << "This program will calculate the distance between two points" << endl;
  cout << "Enter coordinates of first point. x then y \n";

  int x1;
  int y1;
  int x2;
  int y2;

  cin >> x1;
  cin >> y1;

  cout << "First point is: (" << x1 << "," << y1 << ")\n";
  cout << "Enter coordinates of second point. x then y. \n";

  cin >> x2;
  cin >> y2;

  cout << "Second point is: (" << x2 << "," << y2 << ")\n";

  string dist;
  cout << "Enter command: Euclidean, Manhattan or Max\n";
  cin >> dist;

  int x3 = x2-x1;
  int y3 = y2-y1;

  double result;

  if (dist == "Maximum")
    result = Maximum1 (x3,y3);
  if (dist == "Manhattan")
    result = Manhattan1 (x3,y3);
  if (dist == "Euclidean")
    result = Euclidean1 (x3,y3);


  cout << "the distance between the points is: " << result;

  return 0;          //Standard way to end function
}

int Maximum1 (int x, int y) {
int a;
int b = abs(x);
int c = abs(y);
a = max(b,c);
return a;
}

int Manhattan1 (int x, int y) {
int a;
a = x + y;
return a;
}

double Euclidean1 (int x, int y) {
double a;
a = sqrt(pow(x,2) - pow(y,2));
return a;
}
