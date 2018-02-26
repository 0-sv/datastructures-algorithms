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

    long long total = 0, mii = 0;
	for (int i = 0, j = i + 1; i < N; ++i, ++j) {		// O(N)
		if (arr[j] > arr[i]) 
			++mii;
		else {
			total += (mii * (mii + 1)) / 2;				// MII is equal to the triangle sequence. 
			mii = 0;									// Repeat the counting process.
		}
	}

    cout << total << endl;
    return 0;
}
