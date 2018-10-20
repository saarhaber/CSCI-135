/*
Author: Saar Haber
Course: CSCI-136
Instructor: Gewenel Gatto
Assignment: Lab2B

a program hat asks the user to input two integers L and U
(representing the lower and upper limits of the interval), and print
out all integers in the range L ≤ i < U separated by spaces.
We include the lower limit, but exclude the upper limit.
*/

#include <iostream>
using namespace std;
int main() {

int L;
int U;

cout << "Enter L: " << endl;
cin >> L;

cout << "Enter u: " << endl;
cin >> U;

for (int i=L; i<U; i++) {
cout << i << " ";
}

}
