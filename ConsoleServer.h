#ifndef CONSOLESERVER_H_INCLUDED
#define CONSOLESERVER_H_INCLUDED
#include "Game.h"
//class Player;
class BoardCell;
class Board;
class Game;
class ConsoleServer
{
private:
    int round = 0; // round #x
    vector<int> possible_cell; // all probable moves
    vector<int> possible_colorful_cell; // all probable moves to colorful cells
    vector<int> orange = {39, 43, 50, 58, 60, 66, 70, 82, 85, 88, 97, 103, 108}; // all orange cells
    int winner[14]; // winner of each round
    int num_of_players = 0; // number of players
    Game game;
public:
    void equality( int j); // prints the free orange cells and purple cell and
    void arrange_game(); // arranges the game including players, cells and dices
    void game_on(); // starts the game process
    int new_round( int starter_player); // starts a new round
    int check( Player* player); // check if a player is in orange or red cell
    void print_choices( Player* player, int dice1, int dice2, int number); // prints the possible moves for the player based on dice numbers
};

#endif // CONSOLESERVER_H_INCLUDED
