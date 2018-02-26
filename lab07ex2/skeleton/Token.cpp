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

Token::Token(string tokenStr): _token(tokenStr) {
}

bool Token::isParenthesis() {
	return isLeftParenthesis() || isRightParenthesis();
}

bool Token::isLeftParenthesis() {
    if (_token == "(") return true;
    return false;
}


bool Token::isRightParenthesis() {
    if (_token == ")") return true;
    return false;
}


bool Token::isOperator() {
    if (_token == "+") return true;
    if (_token == "-") return true;
    if (_token == "*") return true;
    if (_token == "/") return true;
    return false;
}


string Token::getToken() {
    return _token;
}


void Token::setToken(string tokenStr) {
    _token = tokenStr;
}


bool Token::isAddition() {
    if (_token == "+") return true;
    return false;
}


bool Token::isSubtraction() {
    if (_token == "-") return true;
    return false;
}


bool Token::isMultiplication() {
    if (_token == "*") return true;
    return false;
}


bool Token::isDivision() {
    if (_token == "/") return true;
    return false;
}


bool Token::isNumber() {
	return (_token.find_first_not_of("0123456789") == string::npos);
}


int Token::getNumberValue() {
	return stoi(_token);
}


// Add more if necessary.

