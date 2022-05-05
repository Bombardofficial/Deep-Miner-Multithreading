#include "Game.h"
#include "Miner.h"
#include "World.h"
#include "reverse_miner.h"
#include "threetype_miner.h"
#include "third_miner.h"
#include "Computerplayer.h"
#include "Humanplayer.h"
#include "MiningRound.h"
#include <iostream>
#include <stdlib.h>

std::mutex m;

void Game::start_game()
{
	World w; // 5*5*10 elem generálva
	vector<Miner*> miners;
	char esc_char = 27;
	cout << esc_char << "[1m" << "Welcome to the Deep Miner!\n" << esc_char << "[0m" << endl;

	Player* elso;
	Player* masodik;
	Player* harmadik;
	Player* negyedik;
	Player* otodik;

	
	createFirst(elso);
	createSecond(masodik);
	createThird(harmadik);
	createFourth(negyedik);
	createFifth(otodik);
	do {
		randFirst(elso);
		randSecond(masodik);
		randThird(harmadik);
		randFourth(negyedik);
		randFifth(otodik);
	} while (elso->miner->pos_X == masodik->miner->pos_X 
		&& elso->miner->pos_X == harmadik->miner->pos_X
		&& elso->miner->pos_X == negyedik->miner->pos_X
		&& elso->miner->pos_X == otodik->miner->pos_X
		&& masodik->miner->pos_X == harmadik->miner->pos_X
		&& masodik->miner->pos_X == negyedik->miner->pos_X
		&& masodik->miner->pos_X == otodik->miner->pos_X
		&& harmadik->miner->pos_X == negyedik->miner->pos_X
		&& harmadik->miner->pos_X == otodik->miner->pos_X
		&& negyedik->miner->pos_X == otodik->miner->pos_X
		&& elso->miner->pos_Y == masodik->miner->pos_Y
		&& elso->miner->pos_Y == harmadik->miner->pos_Y
		&& elso->miner->pos_Y == negyedik->miner->pos_Y
		&& elso->miner->pos_Y == otodik->miner->pos_Y
		&& masodik->miner->pos_Y == harmadik->miner->pos_Y
		&& masodik->miner->pos_Y == negyedik->miner->pos_Y
		&& masodik->miner->pos_Y == otodik->miner->pos_Y
		&& harmadik->miner->pos_Y == negyedik->miner->pos_Y
		&& harmadik->miner->pos_Y == otodik->miner->pos_Y
		&& negyedik->miner->pos_Y == otodik->miner->pos_Y);
	
	MiningRound* mining = new MiningRound();
	mining->mineAndReturnWinner(w, elso, masodik, harmadik, negyedik, otodik);
	
	
}

std::thread Game::createFirst(Player* first)
{
	first = new Computerplayer("First Bot");

	first->chooseCast();
	return std::thread();
}

std::thread Game::createSecond(Player* second)
{
	second = new Computerplayer("First Bot");

	second->chooseCast();
	
}

std::thread Game::createThird(Player* third)
{
	third = new Computerplayer("First Bot");

	third->chooseCast();
	
}

std::thread Game::createFourth(Player* fourth)
{
	fourth = new Computerplayer("First Bot");

	fourth->chooseCast();
	
}

std::thread Game::createFifth(Player* fifth)
{
	fifth = new Computerplayer("First Bot");

	fifth->chooseCast();
	
}

std::thread Game::randFirst(Player* first)
{
	first->miner->pos_X = rand() % 5;
	first->miner->pos_Y = rand() % 5;
}

std::thread Game::randSecond(Player* second)
{
	second->miner->pos_X = rand() % 5;
	second->miner->pos_Y = rand() % 5;
}

std::thread Game::randThird(Player* third)
{
	third->miner->pos_X = rand() % 5;
	third->miner->pos_Y = rand() % 5;
}

std::thread Game::randFourth(Player* fourth)
{
	fourth->miner->pos_X = rand() % 5;
	fourth->miner->pos_Y = rand() % 5;
}

std::thread Game::randFifth(Player* fifth)
{
	fifth->miner->pos_X = rand() % 5;
	fifth->miner->pos_Y = rand() % 5;
}

