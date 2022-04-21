#include "reverse_miner.h"
/// <summary>
/// alulról kezd bányászni
/// </summary>
/// <param name="zmine"></param>
void reverse_miner::mine(vector<int>& zmine)
{
	for (auto iter = zmine.rbegin(); iter != zmine.rend(); iter++) {

		if (*iter == -1) {
			cout << "You mined only rocks. The crystals were worth zero." << endl;
			*iter = 0;
			return;
		}
		if (*iter == -2) {
			cout << "The ground was too hard to mine, so you moved to another zone." << endl;
			world->minElementInTable(this);
			*iter = 0;
			return;
		}
		if (*iter != 0 && *iter != -1 && *iter != -2) {
			loot += *iter;
			cout << *iter << " worth of crystals has added to your loot." << endl;
			*iter = 0;
			return;
		}
		
	}
}
