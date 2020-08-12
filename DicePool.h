#ifndef DICEPOOL_H_INCLUDED
#define DICEPOOL_H_INCLUDED

class DicePool
{
private:
    int number = 0; // dice number
public:
    int roll_dice(); // get a random number between 1 and 6
    DicePool( int num); // constructor
    DicePool(); // constructor
    int number_getter(); // returns dice number
    void number_setter( int num); // sets the dice number
};


#endif // DICEPOOL_H_INCLUDED
