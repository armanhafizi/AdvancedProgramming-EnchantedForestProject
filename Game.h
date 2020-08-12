#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "Board.h"
class Player;
class BoardCell;
class Board;
class Game
{
private:
    Board board;
    std::vector<char> treasure; // all the treasures of the board
    std::vector<char> left_treasure; // the treasures which are left
    std::vector<int> possible_cell[3]; // 2 vectors for the possible cells that a player can go to
    char goal_treasure; // the goal treasure of the round which is the last element of the left_treasure
public:
    void arrange_board(); // arranges the dices, players and cells of the board
    void add_treasures(); // add A to M as elements of the treasure
    void add_left_treasures(); // add A to M as elements of the left_treasure
    void change_treasures(); // changes the treasures order randomly for the new round
    void change_goal_treasure(); // changes the goal treasure of the round randomly
    void change_position( Player* player, int new_position); // changes the positions of the player
    void back_to_blue_cell( Player* player); // sends the player back to a blue cell
    void go_to_violet_cell( Player* player); // sends the player to the violet cell
    void crash( Player* player1, Player* player2); // player1 hits player2 and sends it to a blue cell
    vector<int> show_choices( BoardCell* board_cell, int dice); // shows the choices based on the dice number
    void show_choices( BoardCell* prev_board_cell, BoardCell* curr_board_cell, int dice); // helping function for function above
    Board* board_getter(); // returns the board
    void board_setter( Board board); // sets the board
    std::vector<char> treasure_getter(); // returns the treasure
    void treasure_setter( std::vector<char> treasure); // sets the treasure
    char treasure_getter(int num); // returns the treasure[num]
    std::vector<char> left_treasure_getter(); // returns left treasure
    void left_treasure_setter( std::vector<char> left_treasure); // sets the left treasure
    std::vector<int> possible_cell_getter(int num); // returns possible cell[num]
    void possible_cell_setter( std::vector<int> possible_cell, int num); // sets the possible cell[num]
    char goal_treasure_getter(); // returns goal treasure
    void possible_cell_clear( int num); // clears possible cell[num]
};
#endif // GAME_H_INCLUDED
