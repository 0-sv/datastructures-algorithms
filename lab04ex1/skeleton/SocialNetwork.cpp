//=====================================================================
// FILE: SocialNetwork.cpp
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
#include "SocialNetwork.h"

// Add your code here.
SocialNetwork::SocialNetwork(int N) {
	_N = N;
	string result = ""; 
	for (int i = 0; i < N; ++i) {
		string query;
		cin >> query;
		string firstName, group;
		int typeQuery;
		if (query == "Createjoin") {
			cin >> firstName >> group;
			createjoin(firstName, group);
		}
		else if (query == "Quit") {
			cin >> firstName >> group;
			quit(firstName, group);
		}
		else if (query == "Query") {
			cin >> typeQuery;
			if (typeQuery == 1) {
				result += answerQuery1() + "\n";
			}
			else {
				result += answerQuery2() + "\n";
			}
		}
	}
	cout << result;
}
Person* SocialNetwork::addPerson(string name) {
	Person* p = new Person(name);
	return p;
}
Group * SocialNetwork::addGroup(string group) {
	Group* g = new Group(numOfGroups++, group);
	return g;
}
Person * SocialNetwork::findPerson(string name) {
	for (size_t i = 0; i < _persons.size(); ++i) {
		if (name == _persons[i]->getName())
			return _persons[i];
	}
	return NULL;
}
Group * SocialNetwork::findGroup(string group) {
	for (size_t i = 0; i < _groups.size(); ++i) {
		string groupName = _groups[i]->getName();
		if (group == groupName)
			return _groups[i];
	}
	return NULL;
}
void SocialNetwork::createjoin(string name, string group) {
	Group* g = new Group();
	g = findGroup(group);
	if (g == NULL) {
		delete g; 
		Group* newGroup = addGroup(group);
		Person* newPerson = addPerson(name);
		newGroup->addMember(newPerson); 
		_groups.push_back(newGroup);
		_persons.push_back(newPerson); 
	}
	else {
		Person* p = new Person();
		p = findPerson(name);
		if (p == NULL) {
			delete p; 
			Person* p = new Person(name); 
			g->addMember(p);
		}
		else {
			// Do nothing, group and person already exist. 
		}
	}
}
void SocialNetwork::quit(string name, string group) {
	Group* g = new Group();
	Person* p = new Person();
	g = findGroup(group);
		if (g == NULL) {
			delete g;
			return;
		}
		else {
			p = findPerson(name);
			if (p = NULL) {
				delete p;
				return;
			}
			else {
				for (vector<Person*>::const_iterator it = _persons.begin(); it != _persons.end(); ++it) {
					if (p == *it) {
						p->quitGroup(g->getId());
						_persons.erase(it); 
					}
					else {
						return; 
					}
				}
				for (vector<Group*>::const_iterator it = _groups.begin(); it != _groups.end(); ++it) {
					if (g == *it) {
						g->delMember(name);
					}
				}
			}
		}
		delete p, g;
}
string SocialNetwork::answerQuery1() {
	size_t biggest = 0; 
	for (size_t i = 1; i <= _groups.size() - 1; ++i) {
		if (_groups[i]->getNumOfMembers() > _groups[i - 1]->getNumOfMembers())
			biggest = i;
	}
	return _groups[biggest]->getName();
}
string SocialNetwork::answerQuery2() {
	size_t biggest = 0;
	for (size_t i = 0; i < _persons.size() - 1; ++i) {
		if (_persons[i]->getNumOfGroups() > _persons[i - 1]->getNumOfGroups())
			biggest = i;
	}
	return _persons[biggest]->getName();
}
