/*
Saar Haber
E6.18
A function
vector<int> append(vector<int> a, vector<int> b)
that appends one vector after another.
For example, if a is 1 4 9 16
and b is 9 7 4 9 11
then append returns the vector
1 4 9 16 9 7 4 9 11
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b);

int main () {

vector<int> a = {1,4,9,16};
vector<int> b= {9,7,4,9,11};
vector<int> c (a.size()+ b.size());
c = append(a, b);

for (int i=0; i<c.size(); i++){
  cout << c[i] << " ";
}
}

vector<int> append(vector<int> a, vector<int> b) {
  vector<int> c (a.size()+ b.size());
  c = a;
  for (int i=0; i<b.size(); i++){
    c.push_back(b[i]);
  }
return c;
}
