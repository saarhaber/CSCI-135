#include <string>
using namespace std;

/**
   Finds the nth occurrence of a given character in a string.
   @param str the string
   @param ch the character to search
   @param n the occurrence count
   @return the position of the nth occurrence of ch in str, or -1
         if ch doesn't occur n times.
*/
int find_occurrence(string str, string ch, int n)
{
   int length = str.length();
   int count, i = 0;

   for (i=0; i<length; i++) {

     if (str.substr(i,1) == ch) {
      count++;
    }

     if (count == n){
      return i;
    }

   }


   return -1;
}
