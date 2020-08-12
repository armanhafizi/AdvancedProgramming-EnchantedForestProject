#include <iostream>
#include <cstring>
#include "Player.h"
#include "BoardCell.h"
using namespace std;
Player::Player( int num)
{
    this->number = num;
}
Player::Player()
{
    this->number = 0;
}
int Player::number_getter()
{
    return this->number;
}
void Player::number_setter( int num)
{
    this->number = num;
}
