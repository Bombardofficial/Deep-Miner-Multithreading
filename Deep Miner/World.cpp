#include "World.h"
#include "Miner.h"
#include <algorithm>
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

bool kisebb(int& egyik, int& masik) {
    return egyik < masik;
}

bool kisebbVektor(vector<int>& egyik, vector<int>& masik) {
    return egyik[9] < masik[9];
}

void World::minElementInTable(Miner *miner)
{
    
    //min_element(table[0], table[8],)

    //vector<int> temp = { 1,2,3,4,5 };
    //vector<int>::iterator pos = min_element(temp.begin(), temp.end(), kisebb);
    int x;
    int y;
    vector<vector<int> >::iterator smallest = min_element(table[0].begin(), table[0].end(), kisebbVektor);
    x = 0;
    y = smallest - table[0].begin();
    for (size_t i = 1; i < table.size(); i++) {
        vector< vector <int>> layer = table[i];
        vector<vector<int> >::iterator found = min_element(layer.begin(), layer.end(), kisebbVektor);
        if ( (*found)[9] < (*smallest)[9]) {
            x = i;
            y = smallest - table[0].begin();
            smallest = found;
        }
    }

    miner->pos_X = x;
    miner->pos_Y = y;
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

