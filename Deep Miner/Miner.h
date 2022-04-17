#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Miner
{
public:
	//World* world;
	Miner(char buchstabe) : buchstabe(buchstabe) {}
	virtual void mine(vector<int>& zmine) = 0;
	void richtung();
	
	int pos_X = 0;
	int pos_Y = 0;
	int loot = 0;
	char buchstabe;
};

