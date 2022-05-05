#include "MiningRound.h"
#include "Computerplayer.h"
#include "Humanplayer.h"
#include "reverse_miner.h"
#include "threetype_miner.h"
#include "third_miner.h"
#include "World.h"
#include <iostream>
#include <vector>
#include <stdlib.h>


Player* MiningRound::mineAndReturnWinner(World& w, Player* first, Player* second, Player* third, Player* fourth, Player* fifth)
{
    vector<Miner*> miners;
    miners.push_back(first->miner);
    miners.push_back(second->miner);
    miners.push_back(third->miner);
    miners.push_back(fourth->miner);
    miners.push_back(fifth->miner);
    system("Color 0E");
    do {
        
        w.show_table(miners);
        //first
        string dir = first->richtung();
        first->miner->pos_X = dir[0] - 'A';
        first->miner->pos_Y = dir[1] - '1';

        first->miner->mine(w.table[first->miner->pos_X][first->miner->pos_Y]);

        //second
        string dir2 = second->richtung();
        second->miner->pos_X = dir2[0] - 'A';
        second->miner->pos_Y = dir2[1] - '1';

        second->miner->mine(w.table[second->miner->pos_X][second->miner->pos_Y]);

        //third
        string dir3 = third->richtung();
        third->miner->pos_X = dir3[0] - 'A';
        third->miner->pos_Y = dir3[1] - '1';

        third->miner->mine(w.table[third->miner->pos_X][third->miner->pos_Y]);

        //fourth
        string dir4 = fourth->richtung();
        fourth->miner->pos_X = dir4[0] - 'A';
        fourth->miner->pos_Y = dir4[1] - '1';

        fourth->miner->mine(w.table[fourth->miner->pos_X][fourth->miner->pos_Y]);

        //fifth
        string dir5 = fifth->richtung();
        fifth->miner->pos_X = dir5[0] - 'A';
        fifth->miner->pos_Y = dir5[1] - '1';

        fifth->miner->mine(w.table[fifth->miner->pos_X][fifth->miner->pos_Y]);

        //score
        cout << "\nScore:\n";
        cout << first->name << ": " << first->miner->loot << endl;
        cout << second->name << ": " << second->miner->loot << endl;
        cout << third->name << ": " << third->miner->loot << endl;
        cout << fourth->name << ": " << fourth->miner->loot << endl;
        cout << fifth->name << ": " << fifth->miner->loot << endl << endl;
        system("pause");
        system("cls");
        

    } while (first->miner->loot < 50 && second->miner->loot < 50 
        && third->miner->loot < 50 && fourth->miner->loot < 50 && fifth->miner->loot < 50);

    system("Color 0A");
    if (second->miner->loot >= 50) {
        cout << second->name << " won!" << endl;
        return second;
    }
    else if (third->miner->loot >= 50) {
        cout << third->name << " won!" << endl;
        return third;
    }
    else if (fourth->miner->loot >= 50) {
        cout << fourth->name << " won!" << endl;
        return fourth;
    }
    else if (fifth->miner->loot >= 50) {
        cout << fifth->name << " won!" << endl;
        return fifth;
    }
    else {
        cout << first->name << " won!" << endl;
        return first;
    }
 
}
