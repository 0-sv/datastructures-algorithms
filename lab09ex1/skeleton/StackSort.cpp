//=====================================================================
// FILE: StackSort.cpp
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
#include <vector>
#include <queue>

using namespace std;

/* 
Creating new methods was not really necessary.. 
Time complexity: O(T)(O(N) + O(N) + O(1) + O(N))
 = O(T)(O(3N) + O(1))
 = O(T)(O(N))
 = O(TN)
 = O(N)
 */
int main() {

	int T;
	cin >> T;

	while (T-- > 0) {	// O(T)
		int N;
		cin >> N;
		vector<int> arr;
		arr.clear();

		for (int i = 0; i < N; i++) {	// O(N)
			int x;
			cin >> x;
			arr.push_back(x);
		}

		bool succ = true;

		stack<int> A, B, junction;

		// Push all items from the array unto the stack.
		// O(N)
		for (int i = N - 1; i >= 0; --i){
			A.push(arr[i]);
		}

		// O(N)
		while (!A.empty()) {
			int tmp = A.top();
			A.pop();
			if (junction.empty())
				junction.push(tmp);
			else if (junction.top() >= tmp) {
				junction.push(tmp);
			}
			else  {
				while (!junction.empty() && junction.top() <= tmp) {	// keep 177 on the stack, pop 173 and 175, push 176, pop 176 and 177
					B.push(junction.top());
					junction.pop();
				}
				junction.push(tmp);
			}
		}

		// What's left on the junction stack goes to B. 
		// O(1)
		while (!junction.empty()) {
			B.push(junction.top());
			junction.pop();
		}

		// O(N)
		while (!B.empty()) {
			int tmp = B.top();
			B.pop();
			if (B.empty())
				break;
			else if (tmp < B.top()) {
				succ = false;
				break;
			}
		}

        if (succ) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    return 0;
}
