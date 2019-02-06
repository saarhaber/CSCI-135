/*
  Author: Saar Haber
  Course: CSCI-136
  Instructor: Genady Mariash
  Assignment: Lab8G
  Description:
  A  program kernel.cpp, which implements
  a horizontal edge detection operation  */


#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

int main() {

	int img[MAX_H][MAX_W];
	int h, w;

	readImage(img, h, w); // read it from the file "inImage.pgm"
	// h and w were passed by reference and
	// now contain the dimensions of the picture
	// and the 2-dimesional array img contains the image data

	// Now we can manipulate the image the way we like
	// for example we copy its contents into a new array
	int out[MAX_H][MAX_W];
	int saveR = 0;
	int saveC = 0;
	int avg;
	int a,b,c,d,f,g,H,i, color;
	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
				if (col == 0 || col == w-1 || row == 0 || row == h-1) {
					out[row][col] = 0;
				}
				else {
					a = img[row-1][col-1];
					b = img[row-1][col];
					c = img[row-1][col+1];
					d = img[row][col-1];
					f = img[row][col+1];
					g = img[row+1][col-1];
					H = img[row+1][col];
					i = img[row+1][col+1];

					color =  (g + 2*H + i) - (a + 2*b + c);

					if (color<0) {
						out[row][col] = 0;
					}
					else if (color>255) {
						out[row][col] = 255;
					}
					else {
						out[row][col] = color;
					}

				}
		}
	}

	// and save this new image to file "outImage.pgm"
	writeImage(out, h, w);

}
