//=====================================================================
// FILE: SocialNetwork.h
//=====================================================================

//=====================================================================
// STUDENT NAME: <Sebastiaan Verbeek>
// MATRIC NO.  : <A0174730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef social_network_h
#define social_network_h

#include <string>
#include <vector>
#include "Person.h"
#include "Group.h"
using namespace std;

class SocialNetwork{
private:
    vector <Group *> _groups; // Become invalid when the group/person grows.
    vector <Person *> _persons;
	int numOfGroups;
	int _N; 

public:
    SocialNetwork(int);
    
    Person * addPerson(string name);
    Group * addGroup(string name);
    Person * findPerson(string name);
    Group * findGroup(string name);
    void createjoin(string, string);
    void quit(string, string);
    string answerQuery1();
    string answerQuery2();
    // Add more here if necessary.
};

#endif
