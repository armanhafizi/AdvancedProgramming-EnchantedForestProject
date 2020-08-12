#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "ConsoleServer.h"
using namespace std;
void ConsoleServer::arrange_game()
{
    this->game.arrange_board(); // arranges the game board
    this->game.add_treasures(); // add A to M as elements of the treasure
    this->game.add_left_treasures(); // add A to M as elements of the left_treasure
    this->game.change_treasures(); // changes the treasures order randomly for the new round
    this->game.change_goal_treasure(); // changes the goal treasure of the round randomly
}
void ConsoleServer::equality( int j)
{
    for( int i = 0; i <= 12; i++)
        if( this->game.board_getter()->BoardCell_getter( this->orange[i] )->full == false) // check if the target orange cell is empty
        {
            this->possible_colorful_cell.push_back( orange [i]); // adds this cell as an possible colorful cell element
            cout << ++j <<". Move to " << this->orange[i] << "(Orange)" << endl;
        }
    if( this->game.board_getter()->BoardCell_getter(15)->full == false) // check if the purple cell is empty
    {
        this->possible_colorful_cell.push_back( 15); // adds this cell as an possible colorful cell element
        cout << ++j <<". Move to 15(Violet)" << endl;
    }
    cout << ++j << ". Change current round's goal treasure" << endl;
}
int ConsoleServer::new_round(int starter_player)
{
    this->round++; // at the beginning of the new round
    int i = starter_player; // counter for while
    cout << "Round number " << this->round << " started, this round's goal treasure is " << this->game.goal_treasure_getter() << endl;
    if( this->round != 1 ) // not for round #1
    {
        int red_choice = ConsoleServer::check(  this->game.board_getter()->player_getter(i) ); // the choice when in red cell
        if(red_choice != 1)
        {
            if( this->game.treasure_getter(red_choice - 2) != this->game.goal_treasure_getter()) // wrong guess
            {
                cout << "Cell " << this->orange[ red_choice - 2 ] << "'s treasure as seen by player " << i << " is " << this->game.treasure_getter(red_choice - 2) << endl;
                cout << "Player " << i << "'s guess, " << this->orange[ red_choice - 2 ] << ", was not correct" << endl;
                cout << "Player " << i << " is moved to Blue cells" << endl;
                this->game.back_to_blue_cell( this->game.board_getter()->player_getter(i) ) ; // goes back to blue cell
                i++; //next player turn
            }
            else // correct answer
            {
                cout << "Cell " << this->orange[ red_choice - 2 ] << "'s treasure as seen by player " << i << " is " << this->game.treasure_getter(red_choice - 2) << endl;
                cout << "Player " << i << "'s guess, " << this->orange[ red_choice - 2 ] << ", was correct and he/she has won this"
                    << " round's goal treasure, " << this->game.goal_treasure_getter() << endl;
                this->game.board_getter()->player_getter(i)->treasure.push_back(this->game.goal_treasure_getter()); // adding this round's goal treasure as a treasure for the player
                this->game.left_treasure_getter().pop_back(); // deleting this round's goal treasure
                this->game.change_goal_treasure(); // changing the goal treasure
                this->possible_cell.clear(); // clears possible cell
                return i; // returns i as the winner of this round
            }
        }
    }
    while(true)
    {
        cout << "Current Positions:";
        for( int j = 1; j <= this->num_of_players; j++) // for all the players
            cout << " " << j << "->" << this->game.board_getter()->player_getter(j)->position->number_getter(); // prints the position of all players
        int dice1 = this->game.board_getter()->dice_getter()->roll_dice(); // random number for dice #1
        int dice2 = this->game.board_getter()->dice_getter()->roll_dice(); // random number for dice #2
        cout << endl << "Dice Numbers for Player " << i << ": " << dice1 << " " << dice2 << endl << "Player " << i << "'s Choices:" << endl;
        ConsoleServer::print_choices( this->game.board_getter()->player_getter(i), dice1, dice2, 1);// prints all the probabilities
        if( dice1 == dice2) // check if the dice numbers are equal
            equality( this->possible_cell.size()); // does what is necessary for the equality
        else // means the dices are not equal
            ConsoleServer::print_choices( this->game.board_getter()->player_getter(i) , dice2, dice1, 2);// prints all the probabilities
        int choice = 0; // defines choice
        cin >> choice; // inputs choice from the player
        if( choice <= this->possible_cell.size() ) // means that the choice is one of the possible cell elements
        {
            if( this->game.board_getter()->BoardCell_getter( this->possible_cell[choice - 1] )->full == true) // check if the target cell is occupied
            {
                cout << "Player " << this->game.board_getter()->BoardCell_getter( this->possible_cell[choice - 1] )->player->number_getter() << " is moved to Blue cells" << endl;
                this->game.crash( this->game.board_getter()->player_getter(i) , this->game.board_getter()->BoardCell_getter( this->possible_cell[choice - 1])->player) ; // the player hits another player
            }
            else
                this->game.change_position(  this->game.board_getter()->player_getter(i) , this->game.board_getter()->BoardCell_getter( this->possible_cell[choice - 1] )->number_getter() ); // goes to the target cell
            int red_choice = ConsoleServer::check( this->game.board_getter()->player_getter(i) ); // the choice when in red cell
            bool second_dice_permission = true; // indicates if the second dice rolling is allowed or not
            if(red_choice > 1)
            {
                second_dice_permission = false; // the second dice use is not allowed
                if( this->game.treasure_getter(red_choice - 2) != this->game.goal_treasure_getter()) // wrong guess
                {
                    cout << "Cell " << this->orange[ red_choice - 2 ] << "'s treasure as seen by player " << i << " is " << this->game.treasure_getter(red_choice - 2) << endl;
                    cout << "Player " << i << "'s guess, " << this->orange[ red_choice - 2 ] << ", was not correct" << endl;
                    cout << "Player " << i << " is moved to Blue cells" << endl;
                    this->game.back_to_blue_cell( game.board_getter()->player_getter(i) ) ; // goes back to blue cell
                }
                else // correct answer
                {
                    cout << "Cell " << this->orange[ red_choice - 2 ] << "'s treasure as seen by player " << i << " is " << this->game.treasure_getter(red_choice - 2) << endl;
                    cout << "Player " << i << "'s guess, " << this->orange[ red_choice - 2 ] << ", was correct and he/she has won this"
                        << " round's goal treasure, " << this->game.goal_treasure_getter() << endl;
                    this->game.board_getter()->player_getter(i)->treasure.push_back(this->game.goal_treasure_getter()); // adding this round's goal treasure as a treasure for the player
                    this->game.left_treasure_getter().pop_back(); // deleting this round's goal treasure
                    this->game.change_goal_treasure(); // changing the goal treasure
                    this->possible_cell.clear(); // clears possible cell
                    return i; // return i as the winner of this round
                }
            }
            this->possible_cell.clear(); //clears all the elements of possible cells
            if( second_dice_permission == true) // check if the second dice rolling is allowed
            {
                // second choice actions
                cout << "Player " << i << "'s Choices(Second Dice):" << endl;
                if( choice <= this->game.possible_cell_getter(1).size()) // if the choice was for dice #1
                    ConsoleServer::print_choices( this->game.board_getter()->player_getter(i) , dice2, 0, 2);// prints all the probabilities
                else // if the choice was for dice #2
                    ConsoleServer::print_choices( this->game.board_getter()->player_getter(i) , dice1, 0, 1);// prints all the probabilities
                cin >> choice; // input second dice choice
                if( this->game.board_getter()->BoardCell_getter( this->possible_cell[choice - 1] )->full == true) // check if the target cell is occupied
                {
                    cout << "Player " << this->game.board_getter()->BoardCell_getter( this->possible_cell[choice - 1] )->player->number_getter() << " is moved to Blue cells" << endl;
                    this->game.crash( this->game.board_getter()->player_getter(i)  , this->game.board_getter()->BoardCell_getter( this->possible_cell[choice - 1] )->player) ; // the player hits another player
                }
                else
                    this->game.change_position( this->game.board_getter()->player_getter(i) , this->game.board_getter()->BoardCell_getter( this->possible_cell[choice - 1])->number_getter() ); // goes to the target cell
                int red_choice = ConsoleServer::check( this->game.board_getter()->player_getter(i) ) ; // the choice when in red cell
                if(red_choice > 1)
                {
                    if( this->game.treasure_getter(red_choice - 2) != this->game.goal_treasure_getter()) // wrong guess
                    {
                        cout << "Cell " << this->orange[ red_choice - 2 ] << "'s treasure as seen by player " << i << " is " << this->game.treasure_getter(red_choice - 2) << endl;
                        cout << "Player " << i << "'s guess, " << this->orange[ red_choice - 2 ] << ", was not correct" << endl;
                    cout << "Player " << i << " is moved to Blue cells" << endl;
                        this->game.back_to_blue_cell( this->game.board_getter()->player_getter(i) ) ; // goes back to blue cell
                    }
                    else // correct answer
                    {
                        cout << "Cell " << this->orange[ red_choice - 2 ] << "'s treasure as seen by player " << i << " is " << this->game.treasure_getter(red_choice - 2) << endl;
                        cout << "Player " << i << "'s guess, " << this->orange[ red_choice - 2 ] << ", was correct and he/she has won this"
                            << " round's goal treasure, " << this->game.goal_treasure_getter() << endl;
                        this->game.board_getter()->player_getter(i)->treasure.push_back(this->game.goal_treasure_getter()); // adding this round's goal treasure as a treasure for the player
                        this->game.left_treasure_getter().pop_back(); // deleting this round's goal treasure
                        this->game.change_goal_treasure(); // changing the goal treasure
                        this->possible_cell.clear(); // clears possible cell
                        return i; // return i as the winner of this round
                    }
                }
            }
        }
        else // means that the choice is not one of the possible cell elements
        {
            choice -= this->possible_cell.size(); // the suitable  index for possible colorful cell
            if( choice <= this->possible_colorful_cell.size() ) // means that the choice is one of the possible colorful cell elements
                this->game.change_position( this->game.board_getter()->player_getter(i) , this->game.board_getter()->BoardCell_getter( this->possible_colorful_cell[choice - 1] )->number_getter() ); // goes to the target colorful cell
            else
            {
                this->game.change_goal_treasure(); // changes goal treasure of the round
                cout << "Round number " << this->round << ", this round's goal treasure has changed to " << this->game.goal_treasure_getter() << endl;
            }
            int red_choice = ConsoleServer::check( this->game.board_getter()->player_getter(i)  ); // the choice when in red cell
            this->possible_colorful_cell.clear(); //clears all the elements of possible colorful cells
        }
        this->possible_cell.clear(); //clears all the elements of possible cells
        i %= num_of_players; // i making a loop
        i++; // next player
    }
}
void ConsoleServer::game_on()
{
    ConsoleServer::arrange_game(); // arranges the game including board, players, cells and dices
    cout << "How many players are going to play?" << endl; //upcoming message
    cin >> this->num_of_players; // input number of players
    this->winner[0] = 1;
    for( int i = 0; i <= 12; i++)
        this->winner[i + 1] = ConsoleServer::new_round( this->winner[i]); // starts the new round, winner of last round starts the new round
}
void ConsoleServer::print_choices( Player* player, int dice1, int dice2, int number)
{
    if( player->position->number_getter() == 0)
        this->game.possible_cell_setter( this->game.show_choices( this->game.board_getter()->BoardCell_getter(1) , dice1 - 1) , number); // check if it's in a blue cell
    else
        this->game.possible_cell_setter( this->game.show_choices( player->position , dice1) , number); // otherwise
    std::vector<int> temp = this->game.possible_cell_getter(number);
    for( int j = 0; j < this->game.possible_cell_getter(number).size(); j++) // for all the possible moves
    {
        cout << j + this->possible_cell.size() + 1 <<". Move to " << temp[j];
        if( this->game.board_getter()->BoardCell_getter( temp[j] )->color_getter() != "White") // check if it's orange or violet
            cout << "(" << this->game.board_getter()->BoardCell_getter( temp[j] )->color_getter() << ")" ;
        if( dice2 != 0)
            cout << ", and then move " << dice2 << " cells" ; // prints all the probabilities
        cout << endl;
    }
    for( int i = 0; i < this->game.possible_cell_getter(number).size(); i++)
        this->possible_cell.push_back( temp[i]); // appending game.possible_cell to possible_cell
    this->game.possible_cell_clear(0); // clears all elements of game possible cell[0]
    temp.clear(); // clears temp vector
}
int ConsoleServer::check( Player* player)
{
    int n = player->position->number_getter(); // n as cell number of the player
    for( int i = 0; i <= 12; i++) // for all 13 orange cells
        if( n == this->orange[i]) // check if it's in an orange cell
            cout << "Cell " << n << "'s treasure as seen by player " << player->number_getter() << " is " << this->game.treasure_getter(i) << endl;
    if( n == 25) // check if it's in the red cell
    {
        cout << "Player " << player->number_getter() << " is in 25(Red), and can attempt to guess goal treasure's place:" << endl
            << "1. I don't want to guess" << endl;
        for( int i = 0; i <= 12; i++) // for all 13 orange cells
            cout << i + 2 << ". It's " << this->orange[i] << endl;
        int choice = 0; // defines choice
        cin >> choice; // inputs choice
        return choice;
    }
    return 0; // meaning no actions is necessary
}
