#ifndef PLAYER2_H
#define PLAYER2_H
#include "Player.h"


class Player2: public Player
{
    public:
        Player2(int, int, int);
        virtual ~Player2();


        coordonate get_next_position(map_matrix *);
};

#endif // PLAYER1_H
