#ifndef PLAYER3_H
#define PLAYER3_H
#include "Player.h"


class Player3: public Player
{
    public:
        Player3(int, int, int);
        virtual ~Player3();

        coordonate get_next_position(map_matrix *);
};

#endif // PLAYER1_H
