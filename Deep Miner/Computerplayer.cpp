#include "Computerplayer.h"

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
	char richtungsym = this->miner->pos_X + 'A';
	int richtungnum = this->miner->pos_Y + 1;
	
	if (rand() % 2 == 0) { // x-en mozog
		int roll = rand() % 4;
		if (roll >= this->miner->pos_X) {
			roll++;
		}
		string s;
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
