//=====================================================================
// FILE: Matrix.h
//=====================================================================

//=====================================================================
// STUDENT NAME: <ADRIANUS JOHANNES SEBASTIAAN VERBEEK>
// MATRIC NO.  : <A0174730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    private:
         // Add more attributes and methods if necessary.
		int _len; 
		vector<vector<int > > _matrix;
		void rotate(int degrees);
		void reflectX();
		void reflectY();
		void swap(int& x, int& y);
    public:
        // Constructor
		Matrix(int input);
        // Add more methods if necessary.
		void printMatrix();
		void operate(string operation, string type);
};
