#include <iostream>
#include <iomanip>

using namespace std;

int main()

{
const double PI = 3.141592653589793;
double diameter;
double volume1, volume2 ,volume3;
int growth;

cout << "Diameter: ";
cin >> diameter;

volume1 = PI*diameter*diameter*diameter/6;
volume1= int (volume1 + 0.5);
diameter++;

volume2 = PI*diameter*diameter*diameter/6;
volume2 = int (volume2 + 0.5);
growth = volume2-volume1;
cout << "Increase: " << growth << endl;

diameter++;
volume3 = PI*diameter*diameter*diameter/6;
volume3 = int (volume3 + 0.5);
growth = volume3-volume2;
cout << "Increase: " << growth << endl;

return 0;

}
