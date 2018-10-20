/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: LAB 6 - D;

A program decryption.cpp that
uses the functions to demonstrate
encryption and decryption for both ciphers.
**/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// vigenere cipher encryption
string encryptVigenere(string plaintext, string keyword);

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift);

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift);

// Decrypters
string decryptCaesar(string ciphertext, int rshift);
string decryptVigenere(string ciphertext,string keyword);

int main () {

  string s;
  cout << "Enter plaintext: ";
  getline (cin, s);
  cout << endl;

  cout << "= Caesar =" << endl;

  int shift;
  cout << "Enter shift: ";
  cin >> shift;


  cout << "Ciphertext: ";
  string encryptCaesar1 = encryptCaesar(s, shift);
  cout << encryptCaesar1 << endl;

  cout << "Decrypted: ";
  if (decryptCaesar(encryptCaesar1, shift) == s) {
    cout << decryptCaesar(encryptCaesar1, shift) << endl << endl;
  }



  cout << "= Vigenere =" << endl;

  string k;
  cout << "Enter keyword: ";
  cin >> k;

  cout << "Ciphertext: ";
  string encryptVigenere1 = encryptVigenere (s,k);
  cout << encryptVigenere1 << endl;

  cout << "Decrypted: ";
  if (decryptVigenere(encryptVigenere1, k) == s) {
    cout << decryptVigenere(encryptVigenere1, k);
  }


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
       while ((position + rshift) < 65) {
         position += 26;
       }
     }
     else if ((position < 123) && (position > 96)) { // lowercase letters
       while ((position + rshift) > 122) {
         position -= 26;
         }
         while ((position + rshift) < 97) {
           position += 26;
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

 string decryptCaesar(string ciphertext, int rshift){

   string t= "";
   for (int i=0; i<ciphertext.length(); i++) { // iterate the string
     t += shiftChar(ciphertext[i], rshift*(-1));
   }

   return t;

 }
 string decryptVigenere(string ciphertext,string keyword){

   string t= "";
   string copyKey = keyword;
   double k=-1;
   int countLetters=0;
     for (int i=0; i<ciphertext.length(); i++) { // iterate the string

       if (isalpha(ciphertext[i])) {
         k++;
       }
         t += shiftChar(ciphertext[i], (int(copyKey[k])-97)*(-1));

       if (copyKey.length()/(k+1)==1.0) {
         k=-1;
       }
     }

   return t;

 }
