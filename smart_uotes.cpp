#include <string>
using namespace std;

int find_occurrence(string str, string ch, int n);
string replace_at(string str, int position, string replacement);

/**
   Replaces all pairs of straight quotes with curly quotes.
   @param str the string to process
   @return str with adjacent pairs of straight quotes changed to
   curly quotes
*/
string smart_quotes(string str)
{
   string result = str;
   string left_quote = "“";
   string right_quote = "”";
   string regular = "\"";

   int i=0, count=0;

   for (i=0; i<str.length(); i++) {
     if (regular == str.substr(i,1)) {
      count++;
     }
   }

   while (count!=0){

   if (count == 1){
      return result;
   }
   int first = find_occurrence(result, "\"", 1);
   result = replace_at(result, first, left_quote);
   count--;

   int second = find_occurrence(result, "\"", 1);
   result = replace_at(result, second, right_quote);
   count--;;
   }

   return result;
}

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
   int count = 0;
   for (int i = 0; i < str.length(); i++)
   {
      if (str.substr(i, 1) == ch)
      {
         count++;
         if (count == n) { return i; }
      }
   }
   return -1;
}

/**
   Replaces a character of a string at a given position.
   @param str the string where the replacement takes place
   @param position the position of the character to be replaced
   @param replacement the replacement string
   @return str with the character at the position changed to
      the replacement string, or the original string
      if position was not valid.
*/
string replace_at(string str, int position, string replacement)
{
   if (0 <= position && position < str.length())
   {
      return str.substr(0, position) + replacement +
         str.substr(position + 1);
   }
   else
   {
      return str;
   }
}
