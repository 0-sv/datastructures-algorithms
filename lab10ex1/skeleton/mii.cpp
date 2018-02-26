//=====================================================================
// FILE: mii.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <Sebastiaan Verbeek>
// MATRIC NO.  : <A1074730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include <iostream>
using namespace std;


int main()
{
    int N;
    cin >> N;

    int *arr = new int[N];
    for (int i = 0; i < N; i++) cin >> arr[i];

    long long total = 0;

	for (int i = 0; i < N; ++i) {
		int count = 0;
		for (int j = i + 1; j > i; ++j)
			++count;
		int mii = (count * (count + 1)) / 2;
		total += mii; 
	}


    cout << total << endl;
    return 0;
}
