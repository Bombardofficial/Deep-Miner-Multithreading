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

	Player* elso = nullptr;
	Player* masodik = nullptr;
	Player* harmadik = nullptr;
	Player* negyedik = nullptr;
	Player* otodik = nullptr;

	auto startTime = std::chrono::steady_clock::now();
	std::thread t1 = createFirstThread(elso);
	std::thread t2 = createSecondThread(masodik);
	std::thread t3 = createThirdThread(harmadik);
	std::thread t4 = createFourthThread(negyedik);
	std::thread t5 = createFifthThread(otodik);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	auto endTime = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(endTime-startTime).count();

	cout << "Elapsed time during creating the bots: " << elapsed << endl << endl;

	do {
		auto startTimeRand = std::chrono::steady_clock::now();
		std::thread tr1 = randFirstThread(elso);
		std::thread tr2 = randSecondThread(masodik);
		std::thread tr3 = randThirdThread(harmadik);
		std::thread tr4 = randFourthThread(negyedik);
		std::thread tr5 = randFifthThread(otodik);

		tr1.join();
		tr2.join();
		tr3.join();
		tr4.join();
		tr5.join();
		auto endTimeRand = std::chrono::steady_clock::now();
		auto elapsedRand = std::chrono::duration_cast<std::chrono::milliseconds>(endTimeRand - startTimeRand).count();

		cout << "Elapsed time during randomizing the position of the bots: " << elapsedRand << endl << endl;

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

void Game::createFirst(Player* first)
{
	m.lock();
	first = new Computerplayer("First Bot");

	first->chooseCast();
	m.unlock();
	
}

void Game::createSecond(Player* second)
{
	m.lock();
	second = new Computerplayer("First Bot");

	second->chooseCast();
	m.unlock();
}

void Game::createThird(Player* third)
{
	m.lock();
	third = new Computerplayer("First Bot");

	third->chooseCast();
	m.unlock();
}

void Game::createFourth(Player* fourth)
{
	m.lock();
	fourth = new Computerplayer("First Bot");

	fourth->chooseCast();
	m.unlock();
}

void Game::createFifth(Player* fifth)
{
	m.lock();
	fifth = new Computerplayer("First Bot");

	fifth->chooseCast();
	m.unlock();
}

void Game::randFirst(Player* first)
{
	m.lock();
	first->miner->pos_X = rand() % 5;
	first->miner->pos_Y = rand() % 5;
	m.unlock();
}

void Game::randSecond(Player* second)
{
	m.lock();
	second->miner->pos_X = rand() % 5;
	second->miner->pos_Y = rand() % 5;
	m.unlock();
}

void Game::randThird(Player* third)
{
	m.lock();
	third->miner->pos_X = rand() % 5;
	third->miner->pos_Y = rand() % 5;
	m.unlock();
}

void Game::randFourth(Player* fourth)
{
	m.lock();
	fourth->miner->pos_X = rand() % 5;
	fourth->miner->pos_Y = rand() % 5;
	m.unlock();
}

void Game::randFifth(Player* fifth)
{
	m.lock();
	fifth->miner->pos_X = rand() % 5;
	fifth->miner->pos_Y = rand() % 5;
	m.unlock();
}

