#include "Miner.h"
#include <iostream>
using namespace std;
void Miner::richtung()
{
	char richtungsym;
	int richtungnum;
	do {
		cout << "\nwalk to: \nColumn(A,B,C,D,E) -> ";
		cin >> richtungsym;
		cout << "\nRow(1,2,3,4,5) -> ";
		cin >> richtungnum;

		if (cin.fail()) { // if the answer is not proper for the integer variable
			cin.clear();
			string s;
			cin >> s;
		}
		if (this->pos_Y != richtungnum - 1 && this->pos_X != richtungsym - 'A') {
			cout << "You can move only horizontally or vertically at a time." << endl;
		}


	} while (!(richtungnum >= 1 && richtungnum <= 5 && richtungsym >= 'A' && richtungsym <= 'E') 
		|| (this->pos_Y != richtungnum - 1 && this->pos_X != richtungsym - 'A'));
	this->pos_X = richtungsym - 'A';
	this->pos_Y = richtungnum - 1;
	//} while (richtungnum < 1 || richtungnum > 5 || richtungsym < 'A' || richtungsym > 'E'); DeMorgan-azonosság(ok)

	
}
