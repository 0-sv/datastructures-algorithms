//=====================================================================
// FILE: RemoveSubstring.cpp
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

using namespace std;

// Returns the length of the null-terminated string s.
int stringLength(char s[]) {
	if (s == NULL) {
		return 0;
	}
	else {
		int i = 0;
		while (s[i] != '\0') { i++; }
		return i;
	}
}

const int maxSize = 101;

// Adds the character to the result.
void add(char* result, char c, int& position) {
	result[position++] = c;
}

// Copies the occurence of sub in string to result. 
void copy(char string[], char sub[], char* result) {
	// Counts the amount of characters that should be skipped.
	// Positions the character in the result. 
	int i, count = 0, position = 0;

	for (i = 0; i < stringLength(string); ++i) {
		if (string[i] != sub[0])
			add(result, string[i], position);
		else {
			for (int j = 1; j < stringLength(sub); ++j) {
				if (string[i + j] != sub[j]) {
					add(result, string[i], position);
					--count;
					break;
				}
				else
					++count;
			}
			// i should not be incremented with a negative count. This way runtime error is prevented. 
			if (count >= 0)
				i += count;
			count = 0;
		}
	}
	result[position] = '\0';
}

int main()
{
	char str[maxSize], sub[maxSize], result[maxSize];
	cin >> str;
	cin >> sub;

	// Copies from str all occurrences of sub to result. 
	copy(str, sub, result);

	cout << '"';
	for (int i = 0; i < stringLength(result); ++i)
		cout << result[i];
	cout << '"' << endl;

	return 0;
}
