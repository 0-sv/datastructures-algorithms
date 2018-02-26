//=====================================================================       
// FILE: ArrayOfPoints.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <ADRIANUS JOHANNES SEBASTIAAN VERBEEK>
// MATRIC NO.  : <A0174730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <>
//
//=====================================================================


#include <iostream>
#include <string>

using namespace std;

struct Point {
    int x;
    int y;
};


int main() 
{
	int n;
	cin >> n;

	// Dynamic allocation of an array of Points using operator new. 
	Point* points = new Point[n];
	for (int i = 0; i < n; ++i)
		// Variables are accessible with the . operator.
		cin >> points[i].x >> points[i].y;

	// Structure should be accessed in reverse order. 
	for (int t = n - 1; t >= 0; --t)
		cout << "Point " << to_string(t) << ": (" << to_string(points[t].x) << ", " << to_string(points[t].y) << ")\n";

    return 0;
}
