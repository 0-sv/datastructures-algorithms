//=====================================================================
// FILE: Swing.cpp
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
#include <stack>

using namespace std;


int numSwingPairs(int arr[], int size) {
	stack<int> check;
	int result = 0;
	for (int i = 0; i < size; ++i) {
		if (check.empty())
			check.push(arr[i]);
		else {
			while (!check.empty() && arr[i] > check.top()) {
				check.pop();
				++result;
			}
			if (check.empty()) {
				check.push(arr[i]);
			}
			else if (!check.empty() && arr[i] < check.top()) {
				check.push(arr[i]);
				++result;
			}
			else if (arr[i] == check.top())
				++result;
		}

	}
	return result;
}

int main() {
	int N;
	cin >> N;

	int *arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cout << numSwingPairs(arr, N) << endl;
	int i;
	cin >> i;
	return 0;
}
