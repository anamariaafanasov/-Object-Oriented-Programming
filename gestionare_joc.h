#ifndef GESTIONARE_JOC_H
#define GESTIONARE_JOC_H
#include "map_matrix.h"
#include "player.h"
#include "Player1.h"
#include "Player2.h"
#include "Player3.h"
#include "Player4.h"


class gestionare_joc
{
        map_matrix *harta;
        Player1 *player1;
        Player2 *player2;
        Player3 *player3;
        Player4 *player4;
    public:
        gestionare_joc(int );
        virtual ~gestionare_joc();

        void start_round();
};

#endif // GESTIONARE_JOC_H
