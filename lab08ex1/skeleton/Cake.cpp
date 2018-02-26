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


class BestCake {
private:
	queue< pair<bool, int> > _units; // <risk, pieces>
	int _currPieces;
	int _currRisk;
	int _maxPieces;
	int _riskThreshold;

public:
	// Constructor.
	BestCake(int riskThreshold)
		: _units(), _currPieces(0), _currRisk(0),
		_maxPieces(0), _riskThreshold(riskThreshold) {} 


	int getMaxPieces() { return _maxPieces; }

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
		_currPieces += _units.back().second;

		if (isRisky)
			++_currRisk;

		if (_currRisk > _riskThreshold) {
			while (!_units.front().first) {
				_currPieces -= _units.front().second;
				_units.pop();
			}
			_currPieces -= _units.front().second;
			_units.pop(); // Pop 'R'
			--_currRisk;
		}

		if (_currPieces > _maxPieces)
			_maxPieces = _currPieces;
	}
};


int main() {
	int N;
	int riskThreshold;
	cin >> N >> riskThreshold; 

	BestCake cake(riskThreshold);

	char unitRisk;
	int unitPieces;

	while (cin >> unitRisk >> unitPieces)
		cake.considerUnit((unitRisk == 'R'), unitPieces);

	cout << cake.getMaxPieces() << endl;

	return 0;
}
