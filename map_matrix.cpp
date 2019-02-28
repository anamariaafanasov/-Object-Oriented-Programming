#include "map_matrix.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


map_matrix::map_matrix(int dimensiune)
{
    //constructor cu parametri
    //harta va fi initializata cu 0
      n=dimensiune;
      p=new int*[n];

        for(int i=0;i<n;i++)
            p[i]=new int[n];

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                p[i][j]=0;
}

void map_matrix::set_player_on_map(Player *player)
{
    //adaugam un player pe harta
    p[player->row][player->column]=player->trace;
}

map_matrix::~map_matrix()
{
    //destructor
    int i,j;
    for(i=0;i<n;i++)
        delete p[i];
    delete p;
}

int map_matrix::get_dimensiune()
{
    return n;
}

std::ostream &operator<<(std::ostream &out,const map_matrix &val)
{
    //supraincarcatea operatorului de afisare
    for(int i=0;i<val.n;i++){
        for(int j=0;j<val.n;j++)
            out<<val.p[i][j]<<" ";
        out<<endl;
    }

    return out;
}

void map_matrix::add_treasure()
{
    //3 comori vor fi setate pe harta, fiind marcate prin valoarea 5
    //nici o comoara nu va fi amplasata in colturile hartii
    pair<int,int> poz_treasure1,poz_treasure2,poz_treasure3;

    poz_treasure1.first=rand()%n;
    poz_treasure1.second=rand()%n;

    poz_treasure2.first=rand()%n;
    poz_treasure2.second=rand()%n;

    poz_treasure3.first=rand()%n;
    poz_treasure3.second=rand()%n;

    //verificam daca prima comoarra se afla in unul din cele 4 colturi,iar in caz afirmativ o mutam
    if(poz_treasure1.first==0 && poz_treasure1.second==0)
        poz_treasure1.first++;
    if(poz_treasure1.first==0 && poz_treasure1.second==n-1)
        poz_treasure1.first++;
    if(poz_treasure1.first==n-1 && poz_treasure1.second==0)
        poz_treasure1.first--;
    if(poz_treasure1.first==n-1 && poz_treasure1.second==n-1)
        poz_treasure1.first--;
    
    //verificam daca a doua comoarra se afla in unul din cele 4 colturi,iar in caz afirmativ o mutam
    if(poz_treasure2.first==0 && poz_treasure2.second==0)
        poz_treasure2.first++;
    if(poz_treasure2.first==0 && poz_treasure2.second==n-1)
        poz_treasure2.first++;
    if(poz_treasure2.first==n-1 && poz_treasure2.second==0)
        poz_treasure2.first--;
    if(poz_treasure2.first==n-1 && poz_treasure2.second==n-1)
        poz_treasure2.first--;
    
    //verificam daca a treia comoarra se afla in unul din cele 4 colturi,iar in caz afirmativ o mutam
    if(poz_treasure3.first==0 && poz_treasure3.second==0)
        poz_treasure3.first++;
    if(poz_treasure3.first==0 && poz_treasure3.second==n-1)
        poz_treasure3.first++;
    if(poz_treasure3.first==n-1 && poz_treasure3.second==0)
        poz_treasure3.first--;
    if(poz_treasure3.first==n-1 && poz_treasure3.second==n-1)
        poz_treasure3.first--;

    p[poz_treasure1.first][poz_treasure1.second]=5;
    p[poz_treasure2.first][poz_treasure2.second]=5;
    p[poz_treasure3.first][poz_treasure3.second]=5;
}

int* & map_matrix::operator [](const int &index) const  // overloading operator []
{// supraincarcare operator[] pentru matrice
  return   p[index];
}
void map_matrix::operator=(const map_matrix & other)
{
    //supraincarcare operator =
    if(p!=other.p && n!=other.n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                p[i][j]=other.p[i][j];
    }
}