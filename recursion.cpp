/*
Author: Saar Haber
Course: CSCI-136
Instructor: Genady Maryashg
Assignment: LAB 11 A, B, C, D, E

A:
defining a function
void printRange(int left, int right);
that prints all numbers in range
left ≤   x   ≤ right, separated by spaces.

B:
defining a function
int sumRange(int left, int right);
that computes the sum of all numbers in range left ≤   x   ≤ right

C:
int sumArray(int *arr, int size);
which receives an array (as a pointer to
its first element) and the size of the array,
and should return the sum of its elements.

D:
bool isAlphanumeric(string s);
which returns true if all characters
in the string are letters and digits, otherwise returns false

E:
bool nestedParens(string s);
which returns true if the string is a sequence of nested parentheses

F:
bool divisible(int *prices, int size);
which returns true if the collection is divisible,
and false otherwise. The prices are provided in the
array prices, and size is the number of items in the array.


*/

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

//A
void printRange(int left, int right);

//B
int sumRange(int left, int right);

//C
int sumArray(int *arr, int size);

//D
bool isAlphanumeric(string s);

//E
bool nestedParens(string s);

//F
bool divisible(int *prices, int size);

int main() {

  //A
  printRange(-2,10);

  //B
  int x = sumRange(1, 3);
  cout << "This is " << x << endl;   // 6

  int y = sumRange(-2, 10);
  cout << "That is " << y << endl;   // 52

  int z = sumRange(7, 3);
  cout << "That is " << z << endl;   // 0

  //C
  int size = 10;
  int *arr = new int[size]; // allocate array dynamically
  arr[0] = 12;
  arr[1] = 17;
  arr[2] = -5;
  arr[3] = 3;
  arr[4] = 7;
  arr[5] = -15;
  arr[6] = 27;
  arr[7] = 5;
  arr[8] = 13;
  arr[9] = -21;

  int sum1 = sumArray(arr, size); // Add all elements
  cout << "Sum is " << sum1 << endl;  // Sum is 43

  int sum2 = sumArray(arr, 5); // Add up first five elements
  cout << "Sum is " << sum2 << endl;  // Sum is 34

  delete[] arr;         // deallocate it

  //D
  cout << isAlphanumeric("ABCD") << endl;        // true (1)
  cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
  cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)

  cout << endl;
  //E
  cout << nestedParens("((()))") << endl;      // true (1)
  cout << nestedParens("()") << endl;          // true (1)
  cout << nestedParens("") << endl;            // true (1)

  cout << nestedParens("(((") << endl;         // false (0)
  cout << nestedParens("(()") << endl;         // false (0)
  cout << nestedParens(")(") << endl;          // false (0)
  cout << nestedParens("a(b)c") << endl;       // false (0)

  //F
  int prices [] = {10, 15, 12, 18, 19, 17, 13, 35, 33};

  cout << endl;
  cout << divisible(prices, 9);
}

//B
void printRange(int left, int right) {
  if (left<=right) {
    cout << left << " ";
    printRange (left+1, right);
  }
}


//B
int sumRange(int left, int right) {
  if (left > right) { return 0;}
  if (left == right) {
    return right;
    // if the range is empty I return the last number which is thr right one
  }
  else {
    return (left + sumRange(left+1,right));
  }
}

//C
int sumArray(int *arr, int size) {
  if (size != 0) {
    return (arr[size-1] + sumArray(arr, size-1));
  }
  else {
    return 0;
  }
}

//D
bool isAlphanumeric(string s) {
  if (s.empty()) {
    return true;
  }
  else {
    return (isalnum(s[0]) &&  isAlphanumeric(s.substr(1, s.length())));
        }
}

//E
bool nestedParens(string s) {
  if (s.empty()) {
    return true;
  }
  else if (isAlphanumeric(s)) {
    return false;
  }
  else if (s[0] != '(' && s[0]!=')') {
    return false;
  }

  else if (s.length()%2!=0) {
    return false;
  }
  else if (s.length()==2 && s[0] == '(' && s[s.length()-1] == ')') {
    return true;
  }
  else if (s.length()==2 && s[0] == ')' && s[s.length()-1] == '(') {
    return false;
  }
   else if (((s[0] == '(' && s[s.length()-1] == ')')
   || (s[0] != '(' && s[s.length()-1] != ')' )))
  {
        return (nestedParens(s.substr(1,s.length()-2)));
  }
  else {
    return false;
  }
}

//F
bool divisible(int *prices, int size) {
int Bob, Alice = 0;

if (Bob + prices[0] == Alice) {
  Bob += prices[0];

  divisible(prices+1, size-1);
  return true;
}

else if (Alice + prices[0] == Bob) {
  Alice += prices[0];

  divisible (prices+1, size-1);
  return true;
}

else {
  return false;
}

}
