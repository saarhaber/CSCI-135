/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 6 - C;

A program vigenere.cpp with functions implementing Vigenere cipher encryption

**/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// vigenere cipher encryption
string encryptVigenere(string plaintext, string keyword);
char shiftChar(char c, int rshift);

int main () {

  string s;
  cout << "Enter plaintext: ";
  getline (cin, s);

  string k;
  cout << "Enter keyword: ";
  getline (cin, k);

  cout << "Ciphertext: ";
  cout << encryptVigenere(s, k);

 }

 string encryptVigenere(string plaintext, string keyword) {

   string t= "";
   string copyKey = keyword;
   double k=-1;
   int countLetters=0;
     for (int i=0; i<plaintext.length(); i++) { // iterate the string

       if (isalpha(plaintext[i])) {
         k++;
       }
         t += shiftChar(plaintext[i], int(copyKey[k])-97);

       if (copyKey.length()/(k+1)==1.0) {
         k=-1;
       }
     }

   return t;

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
