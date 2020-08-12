#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "DicePool.h"
using namespace std;
int DicePool::roll_dice()
{
    int random_number = rand() % 6 + 1;
    return random_number;
}
DicePool::DicePool( int num)
{
    this->number = num;
}
DicePool::DicePool()
{
    this->number = 0;
}
int DicePool::number_getter()
{
    return this->number;
}
void DicePool::number_setter( int num)
{
    this->number = num;
}

