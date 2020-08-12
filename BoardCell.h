#ifndef BOARDCELL_H_INCLUDED
#define BOARDCELL_H_INCLUDED
#include<vector>
#include<cstring>
#include "Player.h"
class Player;

class BoardCell
{
private:
    int number = 0; // boardCell number
    std::vector<int> friends; // the cells which have a path to
    std::string color = ""; // type of the cell
public:
    Player* player; // the player in this cell
    bool full = false; // true->occupied false->empty
    BoardCell( int num); // constructor
    BoardCell(); // constructor
    int number_getter(); // returns board cell number
    void number_setter( int num); // sets the board cell number
    void friends_push( int num); // pushes back num to friends
    void friends_pop( int num); // pops up num from friends
    std::vector<int> friends_getter(); // returns board cell friends
    int friends_getter(int num); // returns board cell friend[num]
    void friends_setter( std::vector<int> friends); // sets the board cell friends
    std::string color_getter(); // returns board cell color
    void color_setter( std::string color); // sets the board cell color
};

#endif // BOARDCELL_H_INCLUDED
