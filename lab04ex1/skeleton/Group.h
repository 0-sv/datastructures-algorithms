//=====================================================================
// FILE: Group.h
//=====================================================================

//=====================================================================
// STUDENT NAME: <Sebastiaan Verbeek>
// MATRIC NO.  : <A0174730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef group_h
#define group_h

#include <string>
#include <vector>
#include "Person.h"
using namespace std;

class Group{
private:
    int _id;  // assign a unique id to each group.
    string _name;
    vector <Person *> _members;

public:
    Group();
    Group(int id, string name);
    
    int getId();
    string getName();
    void addMember(Person *p);
    void delMember(string name);
    int getNumOfMembers();
    Person * getMember(int i);

    // Add more here if necessary.
};

#endif
