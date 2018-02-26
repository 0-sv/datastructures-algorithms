//=====================================================================
// FILE: Evaluator.cpp
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
#include <queue>
#include "Token.h"
#include <vector>

using namespace std;

int eval(queue<Token> tokens) {
	if (tokens.front().isParenthesis()) {
		tokens.pop();
		return eval(tokens);
	}
	else if (tokens.front().isNumber()) {
		int val = tokens.front().getNumberValue();
		tokens.pop();
		if (tokens.front().isAddition()) {
			tokens.pop();
			return val + eval(tokens);
		}
		else if (tokens.front().isDivision()) {
			tokens.pop();
			return val / eval(tokens);
		}
		else if (tokens.front().isMultiplication()) {
			tokens.pop();
			return val * eval(tokens);
		}
		else if (tokens.front().isSubtraction()) {
			tokens.pop();
			return val - eval(tokens);
		}
		else {
			return val;
		}
	}
}


int main() {

	queue<Token> inputExpr;
	string tmp;

	while (cin >> tmp) {
		Token curToken(tmp);
		inputExpr.push(curToken);
	}

	int exprValue = eval(inputExpr);

	cout << exprValue << endl;
	return 0;
}
