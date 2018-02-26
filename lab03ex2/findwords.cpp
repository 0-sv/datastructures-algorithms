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

	// Rotate 90 degrees. 
	void rotate90(vector<string>& matrix) {
		transpose(matrix);
		reflectY(matrix);
	}

	// Transpose
	void transpose(vector<string>& matrix) {
		for (int i = 0; i < _row; ++i)
			for (int j = 0; j < _col; ++j)
				swap(matrix[i][j], matrix[j][i]);
	}

	// Reflect matrix about the y-axis. 
	void reflectY(vector<string>& matrix) {
		for (int i = 0; i < _row / 2; ++i)
			for (int j = 0; j < _col; ++j) {
				swap(matrix[i][j], matrix[_col - j - 1][i]);
			}
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

	bool diagonal(string query) {
		size_t ans = 0;
		for (int k = 0; k < _row; ++k)
			for (int j = 0; j < _col; ++j) 



					

				diagonal += _matrix[i][j];
				string copy(diagonal);
				reverse(copy.begin(), copy.end());
				if (diagonal.find(query) != string::npos || copy.find(query) != string::npos)
					++ans;
			return ans;
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
		else if (matrix.diagonal(queries[i]))
			cout << "YES" << endl; 
		else
			cout << "NO" << endl;
	}

	int i;
	cin >> i;
	return 0;
}
