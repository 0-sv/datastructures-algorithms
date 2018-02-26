//=====================================================================       
// FILE: ArrayOfPoints.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
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

	Point* points = new Point[n];
	for (int i = 0; i < n; ++i)
		cin >> points[i].x >> points[i].y;

	for (int t = n - 1; t >= 0; --t)
		cout << "Point " << to_string(t) << ": (" << to_string(points[t].x) << ", " << to_string(points[t].y) << ")\n";

	int input;
	cin >> input;
    return 0;
}
