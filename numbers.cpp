/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 5

is a number divisible by the other?
is the number prime?
**/

#include <iostream>
using namespace std;

int largestTwinPrime(int a, int b);
int nextTwinPrime(int n);
bool isTwinPrime(int n);
int countPrimes(int a, int b);
int nextPrime(int n);
bool isPrime(int n);
bool isDivisibleBy(int n, int d);

int main() {

int a;
int b;
cout << "Enter a number: " << endl;
cin >> a;
cout << "Enter another number: " << endl;
cin >>b;

/*
cout << "Is " << a << " divisible by " << b << " ?" << endl;

if (isDivisibleBy(a, b))
  cout << "Yes";
else
  cout << "No";



cout << "Is " << a << " a prime number?" << endl;

  if (isPrime (a))
    cout << "True";
  else
    cout << "False";



cout << nextPrime(a);

cout << countPrimes(a, b);


if (isTwinPrime(a))
  cout << "True";
else
  cout << "False";



cout <<  nextTwinPrime(a);

**/

cout << largestTwinPrime(a, b);

}

bool isDivisibleBy(int n, int d) {
  if (d == 0)           // checking for 0 because you can't divide by 0
    return false;
  else if (n%d == 0 )
    return true;
  else
    return false;
}


bool isPrime(int n) {
  bool prime = true;
  if (n < 2)
    return false;
  for (int i=2; i<n; i++) {
      if (prime == isDivisibleBy(n, i))
        return false;
  }
  return prime;

}

int nextPrime(int n) {
  int i=n+1;
  bool prime = false;
  while (!prime) {
    prime = isPrime(i);
    i++;
  }
  i--;
  return i;

}

int countPrimes(int a, int b) {
  int count = 0;
  for (int i = a; i <= b; i++ ) {
    if (isPrime(i))
      count++;
  }
  return count;
}

bool isTwinPrime(int n) {
  bool check = false;
  if (isPrime(n) && (isPrime(n+2) || isPrime(n-2)))
    check = true;
  return check;
}

int nextTwinPrime(int n) {
  bool check = false;
  int i = n;
  while (!check) {
    if (isTwinPrime(nextPrime (i)))
      check = true;
    else
      i = nextPrime(i);
  }
  return nextPrime(i);
}

int largestTwinPrime(int a, int b) {
  int twin1 = 0,twin2 = 0;
  for (int i=b; i>=a; i--) {
    if (isTwinPrime(i))
      return i;
    }
    return -1;
}
