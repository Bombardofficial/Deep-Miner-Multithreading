#pragma once
#include "Player.h"
class Computerplayer : public Player
{
public:
	Computerplayer(std::string name) : Player(name) {};

	void chooseCast();
	string richtung();
	void ifOnX();
	void ifOnY();
};

