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

// Add other necessary function(s) here.
void palindrome(int& i, bool& b)
{
	int reverse = 0, ans = i;

	// 
	while (ans > 0)
	{
		reverse = reverse * 10;
		reverse += ans % 10; 
		ans = ans / 10; 
	}
	if (reverse == i)
		b = true;
	i = reverse;
	
}

int main()
{
	int input;
	cin >> input;

	bool isPalindrome = false;
	palindrome(input, isPalindrome);

	if (isPalindrome)
		cout << input << endl << "Yes";
	else
		cout << input << endl << "No";
	int i;
	cin >> i; 
    return 0;
}
