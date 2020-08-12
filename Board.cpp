#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include "BoardCell.h"
#include "Player.h"
#include "Board.h"
using namespace std;
void Board::correct_node( int node, int branch, int weed)
{
    board_cell[node].friends_push(branch); // adding the branch cell as a friend of node
    board_cell[branch].friends_pop( weed); // erasing the weed from branch
    board_cell[branch].friends_push(node); // adding the node cell as a friend of branch
    return;
}
void Board::arrange_cells()
{
    for( int i = 1; i <= 4; i++) // set blue cells
    {
        blue_cell[i].friends_push(1); // all blue cells have a path to cell #1
        blue_cell[i].color_setter("Blue"); // all blue cells are blue
    }
    for( int i = 1; i <= 116; i++) // set board cells
    {
        board_cell[i].number_setter(i); // set board cell numbers
        board_cell[i].friends_push(i - 1); // most of the cells have a path to the previous cell
        board_cell[i].friends_push(i + 1); // most of the cells have a path to the next cell
        board_cell[i].color_setter("White"); // most of the cells are white
        if( i == 39 || i == 43 || i == 50 || i == 58 || i == 60 || i == 66
            || i == 70 || i == 82 || i == 85 || i == 88 || i == 97 || i == 103 || i == 108) // set orange cells
        {
            board_cell[i].color_setter("Orange"); // these cells are orange
        }
    }
    board_cell[15].color_setter("Violet"); // this cell is violet
    board_cell[25].color_setter("Red"); // this cell is red
    // correcting friends cells, including nodes and branches
    board_cell[1].friends_pop(0);
    Board::correct_node( 4, 35, 34);
    Board::correct_node( 7, 79, 78);
    Board::correct_node( 10, 53, 54);
    Board::correct_node( 11, 109, 110);
    Board::correct_node( 15, 34, 35);
    Board::correct_node( 21, 116, 117);
    Board::correct_node( 29, 78, 79);
    Board::correct_node( 37, 49, 50);
    Board::correct_node( 46, 59, 60);
    Board::correct_node( 48, 50, 49);
    Board::correct_node( 51, 54, 53);
    Board::correct_node( 55, 60, 59);
    Board::correct_node( 57, 67, 68);
    Board::correct_node( 63, 68, 67);
    Board::correct_node( 81, 93, 94);
    Board::correct_node( 92, 94, 93);
    Board::correct_node( 95, 107, 108);
    Board::correct_node( 101, 110, 109);
    Board::correct_node( 106, 108, 107);
}
void Board::arrange_players()
{
    for( int i = 1; i <= 4; i++)
    {
        blue_cell[i].full = true; // the blue cells become occupied
        player[i].position = &blue_cell[i]; // putting the player to the blue cell
        player[i].number_setter(i); // numbering the players
        blue_cell[i].player = &player[i]; // adjusts the player of the blue cells
    }
}
BoardCell* Board::BoardCell_getter( int number)
{
    return &(this->board_cell[number]);
}
void Board::BoardCell_setter( BoardCell board_Cell, int number)
{
    this->board_cell[number] = board_Cell;
}
BoardCell* Board::BlueCell_getter( int number)
{
    return &(this->blue_cell[number]);
}
void Board::BlueCell_setter( BoardCell blue_cell, int number)
{
    this->blue_cell[number] = blue_cell;
}
DicePool* Board::dice_getter()
{
    return &(this->dice);
}
void Board::dice_setter( DicePool dice)
{
    this->dice = dice;
}
Player* Board::player_getter( int number)
{
    return &(this->player[number]);
}
void Board::player_setter( Player player, int number)
{
    this->player[number] = player;
}

