/*
Author: Saar Haber
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Lab2D

A program which uses an array of ints to
compute and print all Fibonacci numbers from F(0) to F(59).
*/

#include <iostream>

using namespace std;

int main()

{
int fib[60];
fib[0]=0;
fib[1]=1;

cout << fib[0] << endl;
cout << fib[1] << endl;

for (int i=2; i<60; i++) {
fib[i] = fib[i-1] + fib[i-2];
cout << fib[i] << endl;
}



}
