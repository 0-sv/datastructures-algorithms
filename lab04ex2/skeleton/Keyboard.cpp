//=====================================================================
// FILE: Keyboard.cpp
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
#include <sstream>
#include <string>
#include <cstdlib>
#include "Keyboard.h"
using namespace std;

// Add your code here.
Keyboard::Keyboard() {
	_head = NULL;
}

void Keyboard::moveCursorLeft(int k) {
	int i = k;
	for (Node* curr = _cursor; curr->prev != NULL; --i, curr = curr->prev) {
		_cursor = curr;
		if (i == k)
			return; 
	}
}

void Keyboard::moveCursorRight(int k) {
	int i = 0;
	for (Node* curr = _head; curr->next != NULL; ++i, curr = curr->next) {
		_cursor = curr;
		if (i == k)
			return;
	}
}

void Keyboard::insertChar(char newLetter) {
	// List is empty. 
	if (_head == NULL) {
		Node* newPtr = new Node;
		newPtr->letter = newLetter;
		newPtr->prev = NULL;
		newPtr->next = NULL;
		_head = newPtr;
		_tail = newPtr;
		_cursor = newPtr;
	}
	// Cursor points to the same node as tail 
	else if (_cursor == _tail) {
		Node* newPtr = new Node;
		Node* cur = _cursor;
		newPtr->letter = newLetter;
		newPtr->prev = cur;
		newPtr->next = NULL;
		cur->next = newPtr;
		_tail = newPtr;
		_cursor = newPtr;
	}

	// Cursor points somewhere else. 
	else {
		Node* newPtr = new Node;
		Node* cur = _cursor->next;
		newPtr->next = cur;
		newPtr->prev = cur->prev;
		newPtr->letter = newLetter;

		cur->prev->next = newPtr;
		cur->prev = newPtr;
		_cursor = newPtr->next;
	}
}


void Keyboard::deleteChar() {
	if (_head == NULL)
		return;
	else {
		Node* del = _cursor;
		if (_head == del) {
			_head = del->next;
		}
		if (del->prev != NULL) {
			del->prev->next = del->next;
		}
		if (del->next != NULL){
			del->next->prev = del->prev;
		}
		
		delete del;
		del = NULL;
		_cursor = _head;
	}
}

void Keyboard::printLine() {
	ostringstream oss;
	for (Node* curr = _head; curr != NULL; curr = curr->next) {
		oss << curr->letter;
	}
	cout << oss.str();
}

