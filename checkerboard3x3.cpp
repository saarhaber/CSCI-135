/*
Author: Saar Haber
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4 - G

a program that asks the user to
input width and height and prints a checkerboard of
3-by-3 squares. (It should work even if the input
dimensions are not a multiple of three.)**/

#include <iostream>
using namespace std;

int height;
int width;
int row;
int col;

int main()
{
	cout << "input width: " << endl;
	cin >> width;
	cout << "input height: " << endl;
	cin >> height;

	for (row = 0; row < height; row++)
	{
		for (col = 0; col < width; col++)
		{

			if((row/3)%2 == (col/3)%2)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}




}
