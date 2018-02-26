//=====================================================================
// FILE: Main.cpp
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
#include <stack>
#include "Token.h"
using namespace std;

int main() {
	stack<Token> tokenStack;
	string postfix(""), tmp;

	while (cin >> tmp) {
		Token* token = new Token(tmp);

		// Left Parenthesis
		if (token->isLeftParenthesis())
			tokenStack.push(*token);

		// Numbers
		else if (token->isNumber())
			postfix += token->getToken() + " ";

		// Right Parenthesis
		else if (token->isRightParenthesis()) {
			while (tokenStack.top().getToken() != "(") {
				postfix += tokenStack.top().getToken() + " ";
				tokenStack.pop();
			}
			tokenStack.pop(); 
		}

		// Operators
		else if (token->isOperator()) {
			// Stack is not empty, token in infix has no lower precedence or equal precedence.
			while (!tokenStack.empty() && (token->hasLowerPrecedenceThan(tokenStack.top()) || token->hasEqualPrecedenceTo(tokenStack.top()))) {
				if (tokenStack.top().getToken() != "(" || tokenStack.top().getToken() != ")")
					postfix += tokenStack.top().getToken() + " ";
				tokenStack.pop();
			}
			tokenStack.push(*token);
		}
	}

	// Loop through tokenStack, maybe there are still elements in the stack.
	while (!tokenStack.empty()) {
		if (tokenStack.top().getToken() != "(" || tokenStack.top().getToken() != ")")
			postfix += tokenStack.top().getToken() + " ";
		tokenStack.pop();
	}

	cout << postfix << endl;
	return 0;
}
