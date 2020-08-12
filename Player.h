#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include<cstring>
#include<vector>
#include "BoardCell.h"
class BoardCell;

class Player
{
private:
    int number = 0; // player number
public:
    BoardCell* position; // the position of player
    std::vector<char> treasure; // the treasures player has found
    Player( int num); // constructor
    Player(); // constructor
    int number_getter(); // returns player number
    void number_setter( int num); // sets the player number
};
#endif // PLAYER_H_INCLUDED
