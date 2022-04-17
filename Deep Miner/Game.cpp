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

void Game::start_game()
{
	World w; // 5*5*10 elem generálva
	vector<Miner*> miners;
	cout << "\x1B[31mTexting\033[0m\t\t";
	cout << "\x1B[32mWelcome to the Deep Miner!\033[0m\t\t\n" << endl;
	cout << "(Player vs AI) or (AI vs. AI) (1 or 2)? " << endl;
	int choose;
	do {
		cout << "\n> ";
		cin >> choose;
		if (cin.fail()) {
			cin.clear();
			string s;
			cin >> s;
		}
	} while (choose != 1 && choose != 2);
	Player* elso;
	Player* masodik;
	string masodikNeve;
	if (choose == 1) {
		string name;
		system("cls");
		cout << "Your name: ";
		cout << "\n\n> ";
		cin >> name;
		system("cls");
		elso = new Humanplayer(name);
		masodikNeve = "AI";
	}
	else {
		elso = new Computerplayer("First Bot");
		masodikNeve = "Second Bot";
	}
	elso->chooseCast();
	masodik = new Computerplayer(masodikNeve);
	masodik->chooseCast();
	system("cls");
	elso->miner->pos_X = rand() % 5;
	elso->miner->pos_Y = rand() % 5;
	do {
		masodik->miner->pos_X = rand() % 5;
		masodik->miner->pos_Y = rand() % 5;
	} while (elso->miner->pos_X == masodik->miner->pos_X && elso->miner->pos_Y == masodik->miner->pos_Y);
	
	MiningRound* mining = new MiningRound();
	mining->mineAndReturnWinner(w, elso, masodik);
	
}

