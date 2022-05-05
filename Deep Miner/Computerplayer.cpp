#include "Computerplayer.h"
#include <chrono>
#include <thread>
void Computerplayer::chooseCast()
{
	int valasztas = rand() % 3;
	if (valasztas == 0) {
		Miner* m1 = new reverse_miner();
		m1->pos_X = 1;
		m1->pos_Y = 2; // B3-on áll
		miner = m1;
	}
	else if (valasztas == 1) {
		Miner* m1 = new threetype_miner();
		m1->pos_X = 0;
		m1->pos_Y = 0;
		miner = m1;
	}
	else {
		Miner* m1 = new third_miner();
		m1->pos_X = 4;
		m1->pos_Y = 3;
		miner = m1;
	}
	
}

string Computerplayer::richtung()
{
	int counter = 0;
	auto startTime = std::chrono::steady_clock::now(); //für zeitmessung

	char richtungsym = this->miner->pos_X + 'A';
	int richtungnum = this->miner->pos_Y + 1;
	
	if (rand() % 2 == 0) { // x-en mozog
		int roll = rand() % 4;
		if (roll >= this->miner->pos_X) {
			roll++;
		}
		string s;
		//std::thread th0(ifOnX(), ref(counter));
		s.push_back((char)(roll + 'A'));
		s.push_back((char)(richtungnum + '0'));
		return s;
	}
	else { // y-on
		int roll = rand() % 4;
		if (roll >= this->miner->pos_Y) {
			roll++;
		}
		string s;
		s.push_back(richtungsym);
		s.push_back((char)(roll + '1'));
		return s;
	}
}

void Computerplayer::ifOnX()
{
}

void Computerplayer::ifOnY()
{
}
