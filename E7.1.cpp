/**
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E7.1

void sort2(double* p, double* q)
that receives two pointers and sorts the values to which they point.
When calling sort2(&x, &y)
then x <= y after the call. */

#include <iostream>
#include <string>
using namespace std;

void sort2(double *p, double *q);

int main() {

double x = 3;
double y = 1;

sort2 (&x, &y);
cout << x << " " << y;

}

void sort2(double *p, double *q) {


  if (*p > *q) {
    double temp = *q;
    *q = *p;
    *p = temp;
  }


}
