//=====================================================================
// FILE: Person.cpp
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
#include <cstdlib>
#include "Person.h"

// Add your code here.
Person::Person() {
	_name = "\0";
}
Person::Person(string name) {
	_name = name;
}

string Person::getName() {
	return _name;
}
void Person::joinGroup(int grp) {
	_groups.push_back(grp);
}
void Person::quitGroup(int grp) {
	for (vector<int>::const_iterator it = _groups.begin(); it != _groups.end(); ++it) {
		if (grp == *it)
			_groups.erase(it);
	}
}
int Person::getNumOfGroups() {
	return _groups.size();
}
int Person::getGroup(int i) {
	return _groups[i];
}
bool Person::know(Person *p2) {
	return true;
}