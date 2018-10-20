#include <string>
using namespace std;

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
   if (position < str.length()) {
     str = str.substr(0,position) + replacement +
     str.substr(position+1, str.length());
   }
   return str;

}
