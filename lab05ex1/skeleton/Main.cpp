//=====================================================================
// FILE: Main.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <Sebastiaan Verbeek>
// MATRIC NO.  : <A0174730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include <iostream>
#include <string>
#include "BinarySearchTree.h"
using namespace std;


int main() {

    // Add your code here.
	int N;
	cin >> N; 

	// Constructor
	BinarySearchTree bst;

	for (int i = 0; i < N; ++i) {
		string operation;
		int value;

		cin >> operation;
		if (operation == "INSERT") {
			cin >> value;
			bst.insert(value);
		}
		else if (operation == "FINDMIN") {
			cout << bst.findMin() << endl;
		}
		else if (operation == "FINDMAX") {
			cout << bst.findMax() << endl;
		}
		else {
			cin >> value;
			cout << bst.findDepth(value) << endl;
		}
	}
	
	// Destructor
	bst.~BinarySearchTree();
    return 0;
}
