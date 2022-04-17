#include "MiningRound.h"
#include "Computerplayer.h"
#include "Humanplayer.h"
#include "reverse_miner.h"
#include "threetype_miner.h"
#include "third_miner.h"
#include "World.h"
#include <iostream>
#include <vector>
Player* MiningRound::mineAndReturnWinner(World& w, Player* first, Player* second)
{
    vector<Miner*> miners;
    miners.push_back(first->miner);
    miners.push_back(second->miner);
    do {
        // showtable
        // richtung lesz
        // mining
        // csere
        w.show_table(miners);
        string dir = first->richtung();
        first->miner->pos_X = dir[0] - 'A';
        first->miner->pos_Y = dir[1] - '1';

        first->miner->mine(w.table[first->miner->pos_X][first->miner->pos_Y]);

        cout << "\nScore:\n";
        cout << first->name << ": " << first->miner->loot << endl; //loot first->miner->loot
        cout << second->name << ": " << second->miner->loot << endl << endl;
        system("pause");
        system("cls");
        Player* tmp = first;
        first = second;
        second = tmp;

    } while (first->miner->loot < 50 && second->miner->loot < 50); //itt is

    if (second->miner->loot >= 50) {
        cout << second->name << " won!" << endl;
        return second;
    }
    else {
        cout << first->name << " won!" << endl;
        return first;
    }
 
}
