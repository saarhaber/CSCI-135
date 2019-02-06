/*
Author: Saar Haber
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Lab 9 D

It should still keep creating poems,
but all dynamically allocated memory
should get deleted when it is not needed.
*/

#include <iostream>
#include <string>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();
        delete p;
        // assume that the poem p is not needed at this point

    }
}
