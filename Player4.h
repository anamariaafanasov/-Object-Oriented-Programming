#ifndef PLAYER4_H
#define PLAYER4_H
#include "Player.h"

class Player4: public Player
{
    public:
        Player4(int, int, int);
        virtual ~Player4();

        coordonate get_next_position(map_matrix *);
};

#endif // PLAYER1_H
