#pragma once
#include <iostream> //to show in command prompt
#include <vector> //to create 2D Vector
#include <algorithm> //to create random bombs
#include "Miner.h"
using namespace std;

class Miner;

class World
{
public:
	World();
	~World();
	void show_table(vector<Miner*> miners);
	char whichminer(int x, int y, vector<Miner*> miners);
	vector< vector< vector<int> > > table;
	void minElementInTable(Miner *miner);
private:
	int x = 5;
	int y = 5;
	int z = 10;
	
	vector<int> crystals;
	void create_table();
	int rows; //rows, given by the user
	int columns; //columns, given by the user
	int max_size; //rows*columns
	int crystal_count;
};

