#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(int x, int y, int tr):column(y),  row(x), trace(tr)
{
    //constructor
}
Player::~Player()
{
    //destructor
}

int Player::get_column()
{
    return column;
}

int Player::get_row()
{
    return row;
}

int Player::get_trace()
{
    return trace;
}

void Player::set_player_on_position_given(int x, int y)
{
    row=x;
    column=y;
}


