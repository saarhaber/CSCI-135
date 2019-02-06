/*
Saar Haber
E6.21Write a function that modifies a vector<string>, moving all
strings starting with an uppercase letter to the front, without
otherwise changing the order of the elements.
**/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
vector <string> modifies(vector<string> name);
int main (){

vector<string> a =
{"One", "little", "Kuala", "walked", "into", "the", "Zoo"};
vector<string> b (a.size());
b = modifies (a);
for (int i=0; i<b.size(); i++) {
  cout << b[i] << endl;
}
}

vector<string> modifies(vector<string> name) {
  vector <string> upper (0);
  vector <string> lower (0);
  vector <string> changed (name.size());
  for (int i=0; i<name.size(); i++) {
    if (isupper(name[i][0])) {
      upper.push_back(name[i]);
    }
    if (islower(name[i][0])) {
      lower.push_back(name[i]);
    }
  }
  changed = upper;
  for (int i=0; i<lower.size(); i++) {
      changed.push_back(lower[i]);
    }
  return changed;
}
