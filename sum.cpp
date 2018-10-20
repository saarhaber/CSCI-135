/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project1-Task A

 a program that reads a sequence of integers from cin, and reports their sum.*/

#include <iostream>
#include <string>

using namespace std;
int main() {
    int s;
    int sum=0;
    while(cin >> s) { // While the reading operation is a success
        sum = sum + s;  // adding numbers to sum
    }
    cout << sum;
}
