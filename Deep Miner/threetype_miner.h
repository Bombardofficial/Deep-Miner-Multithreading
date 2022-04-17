#pragma once
#include "Miner.h"
class threetype_miner : public Miner
{
public:
	 threetype_miner() : Miner('E') {}

	void mine(vector<int>& zmine);
};

