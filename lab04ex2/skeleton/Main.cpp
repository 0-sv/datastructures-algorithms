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
#include <cstdlib>
#include "Keyboard.h"
using namespace std;


int main() {

    Keyboard keyboard;

    // Add your code here.
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string operation; 
		cin >> operation; 
		if (operation == "left") {
			int k;
			cin >> k;
			keyboard.moveCursorLeft(k);
		}
		else if (operation == "right") {
			int k;
			cin >> k;
			keyboard.moveCursorRight(k);
		}
		else if (operation == "insert") {
			char c;
			cin >> c;
			keyboard.insertChar(c);
		}
		else if (operation == "delete") {
			keyboard.deleteChar();
		}
		else
			cout << "Invalid operation, please try again."; 
	}
    keyboard.printLine();
    cout << endl;
	int i;
	cin >> i; 
    return 0;
}
