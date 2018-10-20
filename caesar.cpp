/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 6 - B;

A program caesar.cpp with functions implementing Caesar cipher encryption

**/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift);

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift);

int main () {

string s;
cout << "Enter plaintext: ";
getline (cin, s);

int shift;
cout << "Enter shift: ";
cin >> shift;

cout << "Ciphertext: ";
cout << encryptCaesar(s, shift);


}

char shiftChar(char c, int rshift){

  if (!isalpha(c)) // if not a letter it returns the char back
    return c;
  int position = int(c);
    if ((position < 91) && (position > 64)) { //uppercase letters
      while ((position + rshift) > 90) {
        position -= 26;
      }
    }
    else if ((position < 123) && (position > 96)) { // lowercase letters
      while ((position + rshift) > 122) {
        position -= 26;
        }
      }

    return char(position + rshift);

}

string encryptCaesar(string plaintext, int rshift){

  string t= "";
  for (int i=0; i<plaintext.length(); i++) { // iterate the string 
    t += shiftChar(plaintext[i], rshift);
  }

  return t;

}
