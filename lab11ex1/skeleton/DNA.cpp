//=====================================================================
// FILE: DNA.cpp
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
#include <vector>
#include <cmath>
using namespace std;


int convert(char chr) {
    if (chr == 'A') return 0;
    if (chr == 'C') return 1;
    if (chr == 'G') return 2;
    return 3;
}


void generateTable(string DNA, int N, int K, int *&table) {
    int tableSize = 1;
    for (int i = 0; i < K; i++) tableSize *= 4;  // tableSize = 4^K

    table = new int[tableSize];
    for (int i = 0; i < tableSize; i++) table[i] = 0;

	for (int i = 0; i < N; ++i) {
		string word = DNA.substr(i, K);
		int value = 0; 
		for (int j = 0; j < word.size(); ++j) {
			value += convert(word[j]);
		}
		int key = hashF(value, tableSize);
		if (table[key] == 0) 
			table[key] = value;
		else {
			for (; table[key] != 0; ++key)
			table[key] = value;
		}
	}
}

int hashF(int value, int tableSize) {
	return value % tableSize;
}

int count(string substr, int K, int* table) {
	for (int i = 0; i < (*table).size(); ++i) {

	}
}


int main() {

    int N, K, Q;
    string DNA;

    cin >> N >> K;
    cin >> DNA;
    cin >> Q;

    int *table;  // to be an array of int
    generateTable(DNA, N, K, table);

    while (Q-- > 0) {
        string substr;
        cin >> substr;
        cout << count(substr, K, table) << endl;
    }
    return 0;
}
