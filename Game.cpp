#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Game.h"
using namespace std;
void Game::arrange_board()
{
    srand(time(NULL)); // adjusting rand seed
    this->board.arrange_cells(); // arranges cells of the board
    this->board.arrange_players(); // arranges players of the board
}
void Game::add_treasures()
{
    for( int i = 0; i <= 12; i++) // 0->39, 1->43, ..., 12->108
        this->treasure.push_back( char(i + 65)); // casting integer to character as A to M
}
void Game::add_left_treasures()
{
    for( int i = 0; i <= 12; i++) // 0->39, 1->43, ..., 12->108
        this->left_treasure.push_back( char(i + 65)); // casting integer to character as A to M
}
void Game::change_treasures()
{
    std::random_shuffle( this->treasure.begin(), this->treasure.end()); // shuffles the treasures order
}
void Game::change_goal_treasure()
{
    for( int i = 0; i <= rand()%10 + 1; i++ )
        std::random_shuffle( this->left_treasure.begin(), this->left_treasure.end()); // shuffles the left treasures order
    this->goal_treasure = this->left_treasure[ this->left_treasure.size() - 1 ]; // the goal treasure automatically changes
}
void Game::change_position( Player* player, int new_position)
{
    player->position->full = false; // frees the previous position of the player
    player->position->player = NULL; // frees the previous position of the player
    player->position = board.BoardCell_getter(new_position); // sets the new position of the player
    this->board.BoardCell_getter(new_position)->player = player; // sets the player as a member of the new position
    this->board.BoardCell_getter(new_position)->full = true; // the new cell becomes occupied
}
void Game::back_to_blue_cell( Player* player)
{
    int i = 1;
    player->position->full = false; // frees the previous position of the player
    for( i = 1; i <= 4; i++)
    {
        if( this->board.BlueCell_getter(i)->full == false ) // checks which blue cell is empty
            break;
    }
    player->position = this->board.BlueCell_getter(i); // sets the new position of the player
    this->board.BlueCell_getter(i)->player = player; // sets the player as a member of the new position
    this->board.BlueCell_getter(i)->full = true; // this blue cell becomes occupied
}
void Game::go_to_violet_cell( Player* player)
{
    Game::change_position( player, 15); // sends the player to the violet cell(15)
}
void Game::crash( Player* player1, Player *player2)
{
    Game::change_position(player1, player2->position->number_getter()); // sends player1 to the position of player2
    Game::back_to_blue_cell( player2); // sends player2 to a blue cell
}
std::vector<int> Game::show_choices( BoardCell* board_cell, int dice)
{
    for( int i = 0; i < board_cell->friends_getter().size(); i++) // for all the friends, runs the below function
            Game::show_choices( board_cell, this->board.BoardCell_getter( board_cell->friends_getter(i) ) , dice);
    sort( this->possible_cell[0].begin(), this->possible_cell[0].end()); // sorts the cells
    this->possible_cell[0].erase( unique( this->possible_cell[0].begin(), this->possible_cell[0].end()), this->possible_cell[0].end()); // removers duplicate cells
    return this->possible_cell[0];
}
void Game::show_choices( BoardCell* curr_board_cell, BoardCell* next_board_cell, int dice)
{
    if( dice == 0) // last step of the function
    {
        this->possible_cell[0].push_back( curr_board_cell->number_getter()); // adds this cell as an element of the possible cells vector
        return;
    }
    for( int i = 0; i < next_board_cell->friends_getter().size(); i++) // for all the friends, runs the function again
    {
        if( next_board_cell->number_getter() == 1 && curr_board_cell->number_getter() == 2 && dice == 1)
            this->possible_cell[0].push_back(1); // adds this cell as an element of the possible cells vector
        if( next_board_cell->friends_getter(i)  != curr_board_cell->number_getter()) // except the previous cell, because changing direction is not allowed
            Game::show_choices( next_board_cell, board.BoardCell_getter( next_board_cell->friends_getter(i) ) ,dice - 1);
    }
}
Board* Game::board_getter()
{
    return &(this->board);
}
void Game::board_setter( Board board)
{
    this->board = board;
}
std::vector<char> Game::treasure_getter()
{
    return this->treasure;
}
void Game::treasure_setter( std::vector<char> treasure)
{
    this->treasure = treasure;
}
std::vector<char> Game::left_treasure_getter()
{
    return this->left_treasure;
}
void Game::left_treasure_setter( std::vector<char> left_treasure)
{
    this->left_treasure = left_treasure;
}
std::vector<int> Game::possible_cell_getter(int num)
{
    return this->possible_cell[num];
}
void Game::possible_cell_setter( std::vector<int> possible_cell, int num)
{
    this->possible_cell[num] = possible_cell;
}
char Game::goal_treasure_getter()
{
    return this->goal_treasure;
}
char Game::treasure_getter(int num)
{
    return this->treasure[num];
}
void Game::possible_cell_clear( int num)
{
    this->possible_cell[num].clear();
}
