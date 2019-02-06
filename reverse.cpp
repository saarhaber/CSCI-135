/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 7.13

A function void reverse(char s[])
that reverses a character string. For example, "Harry" becomes "yrraH".
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void reverse(char s[]);

int main () {

char s[] = "Harry";
reverse(s);

int i = 0;
while (i < 6)
{
  cout << s[i];
  i++;
}

}

void reverse(char s[]) {

int i = 0;

while (s[i] != '\0')
{
  i++;
}

char t[i];


for (int k = 0; k < i; k++)
{
  t[k] = s[k];
}

int m = 0;
i -= 1;

while (i != -1)
{
  s[m] = t[i];
  i--;
  m++;
}

}
