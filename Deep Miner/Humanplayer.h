#pragma once
#include "Player.h"
class Humanplayer : public Player
{
public:
	Humanplayer(std::string name) : Player(name) {};
	void chooseCast();
	string richtung();
};

