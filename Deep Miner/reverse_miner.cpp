#include "reverse_miner.h"
/// <summary>
/// alulról kezd bányászni
/// </summary>
/// <param name="zmine"></param>
void reverse_miner::mine(vector<int>& zmine)
{
	for (auto iter = zmine.rbegin(); iter != zmine.rend(); iter++) {
		if (*iter != 0) {
			loot += *iter;
			cout << *iter << " worth of crystals has added to your loot." << endl;
			*iter = 0;
			return;
		}
	}
}
