//=====================================================================
// FILE: Token.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <Sebastiaan Verbeek>
// MATRIC NO.  : <A0174730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include "Token.h"
#include <string>


Token::Token(string tokenStr): _token(tokenStr) {
}

Token::~Token() = default;


bool Token::isLeftParenthesis() {
	return _token == "(";
}


bool Token::isRightParenthesis() {
	return _token == ")";
}


bool Token::isOperator() {
	size_t found = _token.find_first_of("+-/*");
	if (found != string::npos)
		return true;
	else
		return false;
}


bool Token::isNumber() {
	return (isdigit(_token[0]));
}


bool Token::hasLowerPrecedenceThan(Token& another) {
	// * / has higher precedence. 
	size_t foundInToken = _token.find_first_of("+-");
	size_t foundInAnotherToken = another.getToken().find_first_of("*/");

	return foundInToken != string::npos && foundInAnotherToken != string::npos;
}


bool Token::hasEqualPrecedenceTo(Token& another) {
	size_t foundInToken = _token.find_first_of("+-");
	size_t foundInAnotherToken = another.getToken().find_first_of("+-");

	if (_token == another.getToken())
		return true;
	else if (foundInToken != string::npos && foundInAnotherToken != string::npos)
		return true; 
	else {
		// Change value of foundInToken and foundInAnotherToken, since */ and */ are also equal. 
		foundInToken = _token.find_first_of("*/");
		foundInAnotherToken = another.getToken().find_first_of("*/");
		return foundInToken != string::npos && foundInAnotherToken != string::npos;
	}
}


string Token::getToken() {
    return _token;
}


void Token::setToken(string tokenStr) {
    _token = tokenStr;
}
