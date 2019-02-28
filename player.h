#ifndef PLAYER_H
#define PLAYER_H
#include "map_matrix.h"

struct coordonate {
    int i,j;
};

class map_matrix;

class Player
{
      //clasa de baza a 4 tipuri de playeri
    int column,row;
    const int trace;

    public:
        Player(int, int, int);
        virtual ~Player();

        int get_column();
        int get_row();
        int get_trace();
        virtual coordonate get_next_position(map_matrix *)=0;
        void  set_player_on_position_given(int , int );

        friend class map_matrix;
};

#endif // PLAYER_H

