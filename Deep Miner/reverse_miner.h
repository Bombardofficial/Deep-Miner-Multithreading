#pragma once
#include "Miner.h"
class reverse_miner : public Miner
{
public:
	reverse_miner() : Miner('R') {}

	void mine(vector<int>& zmine);
	
};

