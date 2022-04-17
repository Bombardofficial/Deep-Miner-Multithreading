#include "World.h"
#include "Miner.h"
#include <string>


World::World()
{
    create_table(); // 1. create table;
}

World::~World()
{
}

void World::show_table(vector<Miner*> miners)
{

    
    char ch = 'A'; // x (jobbra nõ)
    int sym_num = 5; // y (felfelé nõ)
    cout << "     ";
    for (char ch = 'A'; ch < (char)('A' + x); ++ch) {
        cout << " " << ch << "  ";
        
    }
    cout << "\n     ___________________\n";
    cout << endl;
    for (int i = y-1; i >= 0; --i) { //i:y index
        cout << " " << i + 1 << " | ";
        for (char ch = 'A'; ch < (char)('A' + x); ++ch) {
            
             cout << "[";
             cout << whichminer(ch - 'A', i, miners);
             cout << "] ";

        }

        cout << endl;
    }

}

char World::whichminer(int x, int y, vector<Miner*> miners) {
    for (size_t i = 0; i < miners.size(); i++) {
        if (miners[i]->pos_X == x && miners[i]->pos_Y == y) {
            return miners[i]->buchstabe;
        }
    }
    return ' ';
}




void World::create_table()
{
    for (int k = 0; k < x; k++) {
        vector< vector<int> > layer;

        for (int j = 0; j < y; j++) {
            vector<int> column;
            for (int i = 0; i < z; i++) {
                int x = rand() % 12 - 2;
                if (z <= 0) {
                    z--;
                }
                column.push_back(z);

            }
            layer.push_back(column);
        }

        table.push_back(layer);
    }
}

