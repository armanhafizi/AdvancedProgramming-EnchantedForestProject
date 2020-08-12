#include <iostream>
#include <cstring>
#include "BoardCell.h"
#include "Player.h"
using namespace std;
BoardCell::BoardCell( int num)
{
    this->number = num;
}
BoardCell::BoardCell()
{
    this->number = 0;
}
int BoardCell::number_getter()
{
    return this->number;
}
void BoardCell::number_setter( int num)
{
    this->number = num;
}
std::vector<int> BoardCell::friends_getter()
{
    return this->friends;
}
int BoardCell::friends_getter(int num)
{
    return this->friends[num];
}
void BoardCell::friends_setter( std::vector<int> friends)
{
    this->friends = friends;
}
std::string BoardCell::color_getter()
{
    return this->color;
}
void BoardCell::color_setter( std::string color)
{
    this->color = color;
}
void BoardCell::friends_push( int num)
{
    this->friends.push_back(num);
}
void BoardCell::friends_pop(int num)
{
    this->friends.erase( std::find(this->friends.begin(), this->friends.end(), num));
}
