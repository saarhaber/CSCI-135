// astride cpp program
/* this program prints this pattern:
*******
 *****
  ***
   *
  ***
 *****
*******
 */
#include <iostream>  //The built-in library for input/output
using namespace std; //The names of standard definitions

int ast (int y);

int main(){

ast (7);

  return 0;
}

int ast (int y){
int i;
int j;
for (j=1; j<=4; j++) {
for (i=1; i<=(7-y)/2; i++){
cout << ' ';
}
for (i=1; i<=y; i++){
cout << '*';
}
for (i=1; i<=7-y; i++){
cout << ' ';
}
cout << endl;
y=y-2;
}
y=y+2;
for (j=1; j<=3; j++) {
y=y+2;
for (i=1; i<=(7-y)/2; i++){
cout << ' ';
}
for (i=1; i<=y; i++){
cout << '*';
}
for (i=1; i<=7-y; i++){
cout << ' ';
}
cout << endl;
}

}
