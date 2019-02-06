/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryashg
Assignment: E7.15

function int* read_data(int& size) that reads data from cin
until the user terminates input by entering Q. The function
should set the size reference parameter to the number of
numeric inputs. Return a pointer to an arrayInt on the heap.
That arrayInt should have exactly size elements. Of course,
you won’t know at the outset how many elements the user
will enter. Start with an arrayInt of 10 elements, and double
the size whenever the arrayInt fills up. At the end, allocate
an arrayInt of the correct size and copy all the inputs into it.
Be sure to delete any intermediate arrayInts.

*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int* read_data(int& size);
// reads data from cin until the user terminates input by entering Q

void printArrayInt(int* arrayInt, int size);
//testing to see it works


int main()
{
int* arrayInt;
int size;
arrayInt = read_data(size);

printArrayInt(arrayInt,size);

}

int* read_data(int& size)
{

string input="";

size = 0;

int arrayCapacity = 1; //used to store current arrayCapacity of arrayInt
int* arrayInt = new int[1];

cout << "Enter integer, Q to quit : " << endl;

cin >> input;
while(input != "Q")
{
arrayInt[size] = atoi(input.c_str());
//necessary cause we need to convert the string
//argument str to an integer (type int)
size++;

//doubling arrayCapacity of arrayInt
if (size==arrayCapacity)
{
//copy elements to arrayTemp arrayInt
arrayCapacity *= 2;
int* arrayTemp = new int[size];
for (size_t i = 0; i < size; i++)
{
arrayTemp[i] = arrayInt[i];
}

//delete old arrayInt, allocate new arrayInt at new arrayCapacity

delete[] arrayInt;
arrayInt = new int[arrayCapacity];

//copy arrayTemp arrayInt to new arrayInt
for (size_t i = 0; i < size; i++)
{
arrayInt[i] = arrayTemp[i];
}
delete[] arrayTemp;

}

cin >> input;
}


int* arrayTemp = new int[size];
for (size_t i = 0; i < size; i++)
{
arrayTemp[i] = arrayInt[i];
}

//if no values are entered return NULL
if (size==0)
return NULL;

//delete old arrayInt, allocate new arrayInt at new arrayCapacity
delete[] arrayInt;
arrayInt = arrayTemp; //make arrayInt point to arrayTemp arrayInt

return arrayInt; //return address of arrayInt
}



//print values of arrayInt for testing
void printArrayInt(int* arrayInt, int size)
{
for (size_t i = 0; i < size ; i++)
cout << arrayInt[i] << " ";
cout << endl;
}
