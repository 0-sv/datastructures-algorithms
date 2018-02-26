//=====================================================================       
// FILE: HelloByeBye.cpp
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
#include <cstdio>

using namespace std;

int main() 
{
    string name;

    cout << "What is your name? ";
    getline(cin, name);

    //=======================
    // WRITE YOUR CODE BELOW.
    //=======================
	int times = 0;

	cout << "Hello how many times? ";
	cin >> times; 

	for (int t = 1; t <= times; ++t)
	{
		if (times <= 0)
			break;
		else 
			cout << to_string(t) << ": Hello, " << name << ".\n";;
	}
	
    //=======================

    cout << "Bye-bye!" << endl;
	int input;
	cin >> input;

    return 0;
}
