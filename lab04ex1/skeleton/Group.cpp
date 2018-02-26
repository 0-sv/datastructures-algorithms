//=====================================================================
// FILE: Group.cpp
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
#include "Group.h"

// Add your code here.
Group::Group() {
	_id = NULL;
	_name = "\0";
}
Group::Group(int id, string name) {
	_id = id;
	_name = name;
}

int Group::getId() {
	return _id;
}
string Group::getName() {
	return _name;
}
void Group::addMember(Person *p) {
	_members.push_back(p);
	p->joinGroup(_id);
}
void Group::delMember(string name) {
	for (vector<Person*>::const_iterator it = _members.begin(); it != _members.end(); ++it) {
		string personName = _members[it - _members.begin()]->getName();
		if (name == personName) {
			_members[it - _members.begin()]->quitGroup(_id);
			_members.erase(it);
			return;
		}
	}
}
int Group::getNumOfMembers() {
	return _members.size();
}
Person * Group::getMember(int i) {
	return _members[i];
}