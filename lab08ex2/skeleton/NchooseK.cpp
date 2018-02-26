//=====================================================================
// FILE: NchooseK.cpp
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
using namespace std;

void nChooseK(int k, string s, string sub) {
	if (k == s.size()) {
		cout << sub << s << endl;
	}
	else if (k == 0) {
		cout << sub << endl;
	}
	else {
		nChooseK(k - 1, s.substr(1), sub + s[0]);
		nChooseK(k, s.substr(1), sub);
	}
}

int main() {
	int k;
	string s; // Alphabetical order: a - z
	cin >> k >> s;
	nChooseK(k, s, "");
	return 0;
}
