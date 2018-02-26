//=====================================================================
// FILE: findwords.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <Sebastiaan Verbeek>
// MATRIC NO.  : <A0174730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include <algorithm>
#include <math.h>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Add more variables and functions if necessary.
class FindWords {
private:
	int _col, _row;
	vector<string> _matrix;

	// Swap elements.
	void swap(char& x, char& y) {
		int temp = x;
		x = y;
		y = temp;
	}
public:
	FindWords(int row, int col) {
		_col = col;
		_row = row;

		for (int i = 0; i < _row; ++i) {
			string word;
			cin >> word;
			_matrix.push_back(word);
		}
	}

	bool horizontal(string query) {
		size_t ans = 0;
		for (int i = 0; i < _row; ++i) {
			string horizontal = "";
			for (int j = 0; j < _col; ++j) {
				horizontal += _matrix[i][j];
			}
			string copy(horizontal);
			reverse(copy.begin(), copy.end());
			if (horizontal.find(query, 0) != string::npos || copy.find(query, 0) != string::npos)
				++ans;
		}
		return ans;
	}
	bool vertical(string query) {
		size_t ans = 0;
		for (int i = 0; i < _col; ++i) {
			string vertical = "";
			for (int j = 0; j < _row; ++j) {
				vertical += _matrix[j][i];
			}
			string copy(vertical);
			reverse(copy.begin(), copy.end());
			if (vertical.find(query) != string::npos || copy.find(query, 0) != string::npos)
				++ans;
		}
		return ans;
	}

	bool diagonalOne(string query) {
		size_t ans = 0;
		vector<string> temp = _matrix;
		int begin = 0;
		for (int i = 1, j = 1; i < _row; ++i, ++j)
			temp[i].insert(begin, j, 'X');

		for (int k = 0, j = 0; k < _row; ++k) {
			string diagonal = "";
			for (int i = 0, j = 0; i < _row; ++i) {
				diagonal += temp[i][j];
			}
			++j;
			string copy(diagonal);
			reverse(copy.begin(), copy.end());
			if (diagonal.find(query) != string::npos || copy.find(query) != string::npos)
				++ans;
		}
		return ans;
	}
	bool diagonalTwo(string query) {
		size_t ans = 0;
		vector<string> temp = _matrix;
		int begin = _row - 1;

		for (int i = _row - 1, j = i; i >= 0; --i, --j)
			temp[i].insert(begin, j, 'X');

		for (int k = 0; k < _row; ++k) {
			string diagonal = "";
			int i, j;
			for (i = 0, j = _col - 1; i < _row; ++i, --j) {
				diagonal += temp[i][j];
			}
			++j;
			string copy(diagonal);
			reverse(copy.begin(), copy.end());
			if (diagonal.find(query) != string::npos || copy.find(query) != string::npos)
				++ans;
		}
		return ans;
	}
};

int main()
{
	int row, col, num;
	string query;
	vector<string> queries;

	cin >> row >> col;
	FindWords matrix(row, col);

	cin >> num;
	for (int i = 0; i < num; ++i) {
		cin >> query;
		queries.push_back(query);
	}

	for (int i = 0; i < num; ++i) {
		if (matrix.horizontal(queries[i]))
			cout << "YES" << endl;
		else if (matrix.vertical(queries[i]))
			cout << "YES" << endl;
		else if (matrix.diagonalOne(queries[i]))
			cout << "YES" << endl;
		else if (matrix.diagonalTwo(queries[i]))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	int i;
	cin >> i;
	return 0;
}
