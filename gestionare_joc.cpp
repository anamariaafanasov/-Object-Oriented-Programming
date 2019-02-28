#include "gestionare_joc.h"
#include <iostream>

using namespace std;

gestionare_joc::gestionare_joc(int dimensiune )
{
     //constructor
    harta= new map_matrix(dimensiune);

    player1=new Player1(0,0,1);
    player2=new Player2(0,dimensiune-1,2);
    player3=new Player3(dimensiune-1,0,3);
    player4=new Player4(dimensiune-1,dimensiune-1,4);
    harta->add_treasure();

    //adaugam cei 4 playeri in cele 4 colturi
    harta->set_player_on_map(player1);
    harta->set_player_on_map(player2);
    harta->set_player_on_map(player3);
    harta->set_player_on_map(player4);
    cout<<*harta<<endl;
}

gestionare_joc::~gestionare_joc()
{   //destructor
    delete harta;
    delete player1;
    delete player2;
    delete player3;
    delete player4;
}

void gestionare_joc::start_round()
{
    //o runda consta in deplasarea fiecarui player cu o pozitie
    coordonate new_poz_player1, new_poz_player2, new_poz_player3, new_poz_player4;

    if(player1->get_column()!=-1 && player1->get_column()!=-2)// mutare player1
    {
        new_poz_player1=player1->get_next_position(harta);
        player1->set_player_on_position_given(new_poz_player1.i,new_poz_player1.j);
        if(player1->get_column()!=-1 && player1->get_column()!=-2)
            harta->set_player_on_map(player1);
    }

    if(player2->get_column()!=-1 && player2->get_column()!=-2)//mutare player2
    {
        new_poz_player2=player2->get_next_position(harta);
        player2->set_player_on_position_given(new_poz_player2.i,new_poz_player2.j);
        if(player2->get_column()!=-1 && player2->get_column()!=-2)
            harta->set_player_on_map(player2);
    }

    if(player3->get_column()!=-1 && player3->get_column()!=-2)//mutare player3
    {
        new_poz_player3=player3->get_next_position(harta);
        player3->set_player_on_position_given(new_poz_player3.i,new_poz_player3.j);
        if(player3->get_column()!=-1 && player3->get_column()!=-2)
            harta->set_player_on_map(player3);
    }

    if(player4->get_column()!=-1 && player4->get_column()!=-2)//mutare player4
    {
        new_poz_player4=player4->get_next_position(harta);
        player4->set_player_on_position_given(new_poz_player4.i,new_poz_player4.j);
        if(player4->get_column()!=-1 && player4->get_column()!=-2)
            harta->set_player_on_map(player4);
    }

    cout<<*harta;

    //cand 3 playeri au gasit comoara=>gata jocul
    if(player1->get_column()==-1 && player2->get_column()==-1 && player3->get_column()==-1)
        cout<<"END OF GAME"<<endl;
    if(player1->get_column()==-1 && player2->get_column()==-1 && player4->get_column()==-1)
        cout<<"END OF GAME"<<endl;
    if(player1->get_column()==-1 && player3->get_column()==-1 && player4->get_column()==-1)
        cout<<"END OF GAME"<<endl;
    if(player2->get_column()==-1 && player3->get_column()==-1 && player4->get_column()==-1)
        cout<<"END OF GAME"<<endl;

    //2 playeri au fost scosi de pe harta si 2 au gasit comoara=>gata jocul
    if(player1->get_column()==-1 && player2->get_column()==-1 && player3->get_column()==-2 &&player4->get_column()==-2)
        cout<<"END OF GAME"<<endl;
    if(player1->get_column()==-1 && player2->get_column()==-2 && player3->get_column()==-1 &&player4->get_column()==-2)
        cout<<"END OF GAME"<<endl;
    if(player1->get_column()==-2 && player2->get_column()==-1 && player3->get_column()==-1 &&player4->get_column()==-2)
        cout<<"END OF GAME"<<endl;
    if(player1->get_column()==-1 && player2->get_column()==-2 && player3->get_column()==-2 &&player4->get_column()==-1)
        cout<<"END OF GAME"<<endl;
    if(player1->get_column()==-2 && player2->get_column()==-1 && player3->get_column()==-2 &&player4->get_column()==-1)
        cout<<"END OF GAME"<<endl;
    if(player1->get_column()==-2 && player2->get_column()==-2 && player3->get_column()==-1 &&player4->get_column()==-1)
        cout<<"END OF GAME"<<endl;

    //3 playeri au fost scosi de pe harta si unul a gasit comoara=>gata jocul
    if(player1->get_column()==-1 && player2->get_column()==-2 && player3->get_column()==-2 &&player4->get_column()==-2)
        cout<<"END OF GAME"<<endl;
    if(player1->get_column()==-2 && player2->get_column()==-1 && player3->get_column()==-2 &&player4->get_column()==-2)
        cout<<"END OF GAME"<<endl;
    if(player1->get_column()==-1 && player2->get_column()==-2 && player3->get_column()==-2 &&player4->get_column()==-2)
        cout<<"END OF GAME"<<endl;
}

