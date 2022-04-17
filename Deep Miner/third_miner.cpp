#include "third_miner.h"

/// <summary>
/// egyszerre hármat szed ki, mindig 0-1-2
/// </summary>
/// <param name="zmine"></param>
void third_miner::mine(vector<int>& zmine)
{
	int sum = 0;
	loot += zmine[0]; loot += zmine[1]; loot += zmine[2];
	sum = zmine[0] + zmine[1] + zmine[2];
	cout << sum << " worth of crystals has added to your loot." << endl;
	zmine.erase(zmine.begin());
	zmine.insert(zmine.begin(), 0);
	zmine.erase(zmine.begin() + 1);
	zmine.insert(zmine.begin() + 1, 0);
	zmine.erase(zmine.begin() + 2);
	zmine.insert(zmine.begin() + 2, 0);
	
}
