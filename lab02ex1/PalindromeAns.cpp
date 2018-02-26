//=====================================================================
// FILE: Palindrome.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <ADRIANUS JOHANNES SEBASTIAAN VERBEEK>
// MATRIC NO.  : <A0174730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <None>
//
//=====================================================================


#include <iostream>

using namespace std;

// Passed by reference
void reverse(int& i, bool& b)
{
	int rev = 0, temp = i;

	// 
	while (temp > 0)
	{
		rev = rev * 10 + temp % 10;
		temp = temp / 10;
	}
	if (rev == i)
		b = true;
	i = rev;
}

int main()
{
	int input;
	cin >> input;

	bool palindrome = false;
	reverse(input, palindrome);

	if (palindrome)
		cout << input << endl << "Yes" << endl;
	else
		cout << input << endl << "No" << endl;
	int i;
	cin >> i;
	return 0;
}
