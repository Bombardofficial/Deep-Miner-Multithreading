#pragma once
#include "Miner.h"
class third_miner : public Miner
{
public:
	third_miner() : Miner('T') {}
	/// <summary>
	/// Egyszerre három mezõbõl tud bányászni, azonban csak egy magasságban.
	/// Például ha az A3-at, a B5-öt, illetve a C7-et választom és az 5. blokkot választom mélységben,
	/// akkor mind a három helyen az 5.-et szedi ki.
	/// </summary>
	void mine(vector<int>& zmine);
};

