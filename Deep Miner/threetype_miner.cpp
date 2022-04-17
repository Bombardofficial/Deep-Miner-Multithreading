#include "threetype_miner.h"

/// <summary>
/// legfelsõ, közepsõ, legalsó
/// </summary>
/// <param name="zmine"></param>
void threetype_miner::mine(vector<int>& zmine)
{
	int sum = 0;
	if (zmine[0] == 0) {
		cout << "You already mined here.\n";
	}
	loot += zmine[0]; loot += zmine[5]; loot += zmine[9];
	sum = zmine[0] + zmine[5] + zmine[9];
	cout << sum << " worth of crystals has added to your loot." << endl;
	zmine.erase(zmine.begin()); //deleting first element
	zmine.insert(zmine.begin(), 0);  // inserting 0 to the first element, so we change the first one to zero
	zmine.erase(zmine.begin() + 5);
	zmine.insert(zmine.begin() + 5, 0); 
	zmine.pop_back(); //deleting the last element
	zmine.emplace_back(0); // inserting 0 to the last element
}
