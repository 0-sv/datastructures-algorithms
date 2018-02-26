//=====================================================================       
// FILE: HelloByeBye.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <ADRIANUS JOHANNES SEBASTIAAN VERBEEK>
// MATRIC NO.  : <A0174730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <>
//
//=====================================================================

#include <iostream>
#include <string>

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
		// If times is equal or less than zero (non positive integer), we should just output "Bye-Bye!"
		if (times <= 0)
			break;
		else 
			cout << to_string(t) << ": Hello, " << name << ".\n";;
	}
    //=======================

    cout << "Bye-bye!" << endl;

    return 0;
}
