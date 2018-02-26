//=====================================================================
// FILE: Person.h
//=====================================================================

//=====================================================================
// STUDENT NAME: <Sebastiaan Verbeek>
// MATRIC NO.  : <A0174730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef person_h
#define person_h

#include <string>
#include <vector>
using namespace std;

class Person{
private:
    string _name;
    vector <int> _groups;  // contains the group id's of the person's groups.

public:
    Person();
    Person(string name);

    string getName();
    void joinGroup(int grp);
    void quitGroup(int grp);
    int getNumOfGroups();
    int getGroup(int i);
    bool know(Person *p2);

    // Add more if necessary.
};

#endif
