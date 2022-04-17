#include "Humanplayer.h"
#include <iostream>
using namespace std;
void Humanplayer::chooseCast()
{
    int humancast = 0;
    do {
        cout << "Options:\n\n";
        cout << "   1. Choosing miner\n";
        cout << "   2. Info about the miners\n";
        int chooseopt;
        cout << "\n> ";
        cin >> chooseopt;
        if (cin.fail()) { // if the answer is not proper for the integer variable
            cin.clear();
            string s;
            cin >> s;
        }
        system("cls");
        if (chooseopt == 1) {
            cout << "\nWhat kind of miner do you want to be?" << endl << "Reverse(1), Trident(2) or Excavator(3)?\n> ";
            cin >> humancast;
            if (cin.fail()) {
                cin.clear();
                string s;
                cin >> s;
            }
            switch (humancast) {
            case 1:
                miner = new reverse_miner();
                miner->pos_X = 1;
                miner->pos_Y = 2; // B3-on áll
                break;
            case 2:
                miner = new third_miner();
                cout << "Advice: If you pick the trident, it is recommended that \nyou keep a record of where you have mined so far.\n";
                miner->pos_X = 0;
                miner->pos_Y = 0;
                break;
            case 3:
                miner = new threetype_miner();
                cout << "Advice: If you pick the excavator, it is recommended that \nyou keep a record of where you have mined so far.\n";
                miner->pos_X = 4;
                miner->pos_Y = 3;
                break;
            default:
                cout << "Not possible! Try again!" << endl;
                break;
            }
        }
        else if (chooseopt == 2) {
            cout << "Reverse: This machine starts from the last one and mines its way up. It can be used several times in one area.\n";
            cout << "Trident: This machine mines the first three areas. It can only be used once per area.\n";
            cout << "Excavator: This machine mines the first, middle and last area. It can only be used once per area.\n\n";
            system("pause");
            system("cls");
        }
        
    } while (humancast != 1 && humancast != 2 && humancast != 3);
}

string Humanplayer::richtung()
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
        if (this->miner->pos_Y != richtungnum - 1 && this->miner->pos_X != richtungsym - 'A') {
            cout << "You can move only horizontally or vertically at a time." << endl;
        }


    } while (!(richtungnum >= 1 && richtungnum <= 5 && richtungsym >= 'A' && richtungsym <= 'E')
        || (this->miner->pos_Y != richtungnum - 1 && this->miner->pos_X != richtungsym - 'A'));
    //string s = "" + richtungsym + richtungnum;
    string s;
    s.push_back(richtungsym);
    s.push_back((char)(richtungnum + '0'));
    cout << "richtung: " << s<< endl;
    return s;
//    this->miner->pos_X = richtungsym - 'A';
//    this->miner->pos_Y = richtungnum - 1;
}
