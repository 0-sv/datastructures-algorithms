//=====================================================================
// FILE: Matrix.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <ADRIANUS JOHANNES SEBASTIAAN VERBEEK>
// MATRIC NO.  : <A0174730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include "Matrix.h"
#include <iostream>
#include <vector>

using namespace std;

// Add more methods if necessary.
Matrix::Matrix(int size) : _len(size) {
	for (int i = 0; i < _len; ++i) {
		vector<int > row;
		for (int j = 0; j < _len; ++j) {
			int input;
			cin >> input;
			row.push_back(input);
		}
		_matrix.push_back(row);
	}
}

void Matrix::rotate(int degrees) {
	// transform the matrix by rotating the matrix
	if (degrees == 90 || degrees == 270) {
		// Transpose
		for (int i = 0; i <= _len - 2; ++i)
			for (int j = i + 1; j <= _len - 1; ++j) {
				swap(_matrix.at(i).at(j), _matrix.at(j).at(i));
			}
		if (degrees == 90) {
			reflectY();
		}
		else
			reflectX();
	}
	else if (degrees == 180) {
		reflectX();
		reflectY();
	}
}

void Matrix::reflectX() {
	// transform the matrix by reflecting it about the x-axis
	for (int i = 0; i < _len / 2; ++i)
		for (int j = 0; j < _len; ++j) {
			swap(_matrix.at(i).at(j), _matrix.at(_len - i - 1).at(j));
		}
}


void Matrix::reflectY() {
	// transform the matrix by reflecting it about the y-axis
	for (int i = 0; i < _len; ++i)
		for (int j = 0; j < _len / 2; ++j) {
			swap(_matrix.at(i).at(j), _matrix.at(i).at(_len - j - 1));
		}
}

void Matrix::operate(string operation, string type) {
	// transform matrix according to input operation and type
	if (operation == "Rotate") {
		if (type == "90")
			rotate(90);
		else if (type == "180")
			rotate(180);
		else if (type == "270")
			rotate(270);
	}
	else if (operation == "Reflect") {
		if (type == "x")
			reflectX();
		else if (type == "y")
			reflectY();
	}
}

void Matrix::printMatrix() {
	// Print Matrix
	for (int i = 0; i < _len; ++i) {
		for (int j = 0; j < _len; ++j) {
			if (j == _len - 1)
				cout << _matrix.at(i).at(j);
			else
				cout << _matrix.at(i).at(j) << " ";
		}
		cout << endl;
	}
}

void Matrix::swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
