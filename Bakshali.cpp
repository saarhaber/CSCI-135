#include <iostream>  //The built-in library for input/output
using namespace std; //The names of standard definitions
#include <math.h>
#include <iomanip>


int main (){

double S, guess, d, r, a;

cout << "Enter a positive integer ";
cin >> S;
if (S<1)
  {
  cout << "Error: Number is not positive";
  return 0;
  }

guess = S/2;

for (int i=0; i<5; i++) {
  d = S - pow(guess,2);
  r = d / (guess*2);
  a= guess + r;
  guess = a - (pow(r,2)/(2*a));
}

cout << "Guess of sqrt of " << S << " is ";
std::cout.precision(10);
std::cout << std::fixed << guess;
return 0;

}
