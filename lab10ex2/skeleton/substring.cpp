//=====================================================================
// FILE: substring.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include <iostream>
#include <string>
using namespace std;


int main() 
{
    int T;
    cin >> T;

    while (T-- > 0) {
        int N;
        string str;
        cin >> N;
        cin >> str;

		bool good = false;

		for (int i = 1; i < N; ++i) {
			if (str[i - 1] != str[i]) {
				good = true;
			}
			if (i - 1 > 0 && i + 1 < N && str[i - 1 - 1] != str[i + 1]) {
				good = true;
				++i;
			}
		}

		if (good)
			cout << "YES";
		else
			cout << "NO";
    }

    return 0;
}
