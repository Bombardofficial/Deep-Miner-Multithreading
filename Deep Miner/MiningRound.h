#pragma once
#include "Player.h"
#include "World.h"
class MiningRound
{
public:
	Player* mineAndReturnWinner(World& w, Player* first, Player* second);
	bool korrektRichtung(Miner* miner, string richtung);
};

