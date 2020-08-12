#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include "BoardCell.h"
#include "Player.h"
class Player;
class BoardCell;
class Board
{
private:
    BoardCell board_cell[117], blue_cell[5]; // 116 board cell and 4 blue cell
    DicePool dice; // dice definition
    Player player[5]; // 4 players at max
public:
    void correct_node( int node, int branch, int weed); // corrects the node complexity
    void arrange_cells(); // sets cells and paths to each other
    void arrange_players(); // sets players and their numbers
    BoardCell* BoardCell_getter( int number); // returns BoardCell[number]
    void BoardCell_setter( BoardCell board_Cell, int number); // sets the BoardCell[number]
    BoardCell* BlueCell_getter( int number); // returns BlueCell[number]
    void BlueCell_setter( BoardCell blue_cell, int number); // sets the BlueCell[number]
    DicePool* dice_getter(); // returns dice
    void dice_setter( DicePool dice); // sets dice
    Player* player_getter( int number); // returns player[number]
    void player_setter( Player player, int number); // sets the player[number]
};


#endif // BOARD_H_INCLUDED
