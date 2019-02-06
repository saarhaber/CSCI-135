/*
Author: Saar Haber
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Lab 9 C

Updates position after movement
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct Coord3D {
  double x;
  double y;
  double z;
};

double length(Coord3D *p);
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);
void move(Coord3D *ppos, Coord3D *pvel, double dt);


int main () {
  /* B
  Coord3D pointP = {10, 20, 30};
  Coord3D pointQ = {-20, 21, -22};

  cout << "Address of P: " << &pointP << endl;
  cout << "Address of Q: " << &pointQ << endl << endl;

  Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);

  cout << "ans = " << ans << endl; // So which point is farther?

  **/
  //C
  Coord3D pos = {0, 0, 100.0};
  Coord3D vel = {1.0, -5.0, 0.2};

  move(&pos, &vel, 2.0); // struct pos gets changed
  cout << pos.x << " " << pos.y << " " << pos.z << endl;
  // prints: 2 -10 100.4
}

//length
double length(Coord3D *p) {
  return sqrt(pow(p->x,2) + pow(p->y,2) + pow(p->z,2));
}

//who's further from origin
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2) {

  if (length(p1) > length(p2)) {
    return p1;
  }
  else {
    return p2;
  }
  return p1;
}

void move(Coord3D *ppos, Coord3D *pvel, double dt) {

ppos->x += (pvel->x * dt);
ppos->y += (pvel->y * dt);
ppos->z += (pvel->z * dt);

}
