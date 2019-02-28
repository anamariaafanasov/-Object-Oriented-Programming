#ifndef PLAYER1_H
#define PLAYER1_H
#include "Player.h"

class Player1: public Player
{
    public:
        Player1(int, int, int);
         ~Player1();

        coordonate get_next_position(map_matrix *);
};

#endif // PLAYER1_H
