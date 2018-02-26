//=====================================================================
// FILE: Transformation.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <ADRIANUS JOHANNES SEBASTIAAN VERBEEK>
// MATRIC NO.  : <A0174730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================


#include <iostream>
#include <string>
#include "Matrix.h"

int main() {
    // read input and create the Matrix object
	int input;
	cin >> input; 

	Matrix matrix(input);

    // for each operation, process the matrix
	int num_of_operations;
	cin >> num_of_operations;
	
	for (int i = 0; i < num_of_operations; ++i) {
		string operation, type;
		cin >> operation >> type;
		matrix.operate(operation, type); 
	}

    // output the final matrix
	matrix.printMatrix();
    return 0;
}
