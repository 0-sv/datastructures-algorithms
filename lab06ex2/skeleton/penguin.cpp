//=====================================================================
// FILE: penguin.cpp
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
#include <queue>
#include <utility>  // for pair class.
using namespace std;


class BestDive {
private:
	queue< pair<bool, int> > _units; // <risk, fishes>
	int _currFishes;
	int _currRisk;
	int _maxFishes;
	int _riskThreshold;

public:
	// Constructor.
	BestDive(int riskThreshold)
		: _units(), _currFishes(0), _currRisk(0),
		_maxFishes(0), _riskThreshold(riskThreshold) {} // no dive


	int getMaxFishes() { return _maxFishes; }

	/* 
	Explanation:
		1. Pairs are pushed in the queue. 
		2. Every 'R' should update _currRisk. 
		3. If the risk is above the threshold, the queue should be updated until _currRisk is equal to the threshhold.
		4. Lastly, if this could make Tux catch more fish, _maxFishes should be updated.
	*/
	void considerUnit(bool isRisky, int unitFishes)
	{
		_units.push(make_pair(isRisky, unitFishes));
		_currFishes += _units.back().second;

		if (isRisky)
			++_currRisk;

		if (_currRisk > _riskThreshold) {
			while (!_units.front().first) {
				_currFishes -= _units.front().second;
				_units.pop();
			}
			_currFishes -= _units.front().second;
			_units.pop(); // Pop 'R'
			--_currRisk;
		}

		if (_currFishes > _maxFishes)
			_maxFishes = _currFishes;
	}
};


int main() {
	int riskThreshold;
	cin >> riskThreshold; // T

	BestDive dive(riskThreshold);

	char unitRisk;
	int unitFishes;

	while (cin >> unitRisk >> unitFishes) // read risk and Fi
		dive.considerUnit((unitRisk == 'R'), unitFishes);

	cout << dive.getMaxFishes() << endl;

	return 0;
}
