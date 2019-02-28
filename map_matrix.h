#ifndef MAP_MATRIX_H
#define MAP_MATRIX_H
#include <ostream>
#include "player.h"
class Player;

class map_matrix
{
    int **p,n;
    
    public:
        map_matrix(int );
        virtual ~map_matrix();

        int get_dimensiune();
        void add_treasure();

        int* & operator[](const int &index) const ;
        friend std::ostream &operator<<(std::ostream &out,const map_matrix &val);
        void operator=(const map_matrix &);
        void add_player(const int, const int );
        void set_player_on_map(Player*);
};

#endif // MAP_MATRIX_H

