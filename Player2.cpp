#include "Player2.h"
#include <iostream>
using namespace std;


Player2::Player2(int x, int y, int tr):Player(x,y,tr)
{

}

Player2::~Player2()
{

}

coordonate Player2::get_next_position(map_matrix *m)
{
    // functie ce determina urmatoarea pozitie pe care se poate deplasa player2:
    //pozitia e de tip coordonate;
    //deplasare:dreapta,sus,stanga,jos;diagonale:dreapta-jos,stanga-sus,dreapta-sus,stanga-jos
    //in cazul in care playerul a gasit comoara,pozitia returnata va fi -1-1;
    //in cazul in care playerul e scos de pe harta,pozitia returnata va fi -2-2;

    int n=m->get_dimensiune();
    int column=get_column();
    int row=get_row();
	int moved=0;

    coordonate next_position;
    //initializam next_position cu pozitia curenta
    next_position.i=row;
    next_position.j=column;

    if(column+1<=n-1) //dreapta
    {

        if(((*m)[row][column+1]==0) ||( (*m)[row][column+1]==5 ))
		{
            next_position.j=column+1;
            moved=1;
            if((*m)[row][column+1]==5)
            {
                cout<<"Player2 is winner"<<endl;
                (*m)[row][column+1]=2;
                next_position.i=-1;
                next_position.j=-1;
            }
		}
    }

	if((row-1>=0)&&(moved == 0)) //sus
    {
        if(((*m)[row-1][column]==0) || ((*m)[row-1][column]==5))
		{
            next_position.i=row-1;
			moved=1;
			if((*m)[row-1][column]==5)
            {
                cout<<"Player2 is winner"<<endl;
                (*m)[row-1][column]=2;
                next_position.i=-1;
                next_position.j=-1;
            }
		}
    }

	if((column-1>=0)&&(moved == 0)) 	//stanga
	{
		if(((*m)[row][column-1]==0) || ((*m)[row][column-1]==5))
		{
			next_position.j=column-1;
			moved=1;
            if((*m)[row][column-1]==5)
            {
                cout<<"Player2 is winner"<<endl;
                (*m)[row][column-1]=2;
                next_position.i=-1;
                next_position.j=-1;
            }
		}
	}

	if((row+1<=n-1)&&(moved == 0))  //jos
	{
		if(((*m)[row+1][column]==0 )|| ((*m)[row+1][column]==5))
		{
			next_position.i=row+1;
			moved=1;
            if((*m)[row+1][column]==5)
            {
                cout<<"Player2 is winner"<<endl;
                (*m)[row+1][column]=2;
                next_position.i=-1;
                next_position.j=-1;
            }
		}
	}

	if((column+1<n-1) && (row+1<n-1)&&(moved == 0)) //dreapta-jos
	{
		if(((*m)[row+1][column+1]==0) || ((*m)[row+1][column+1]==5 ))
		{
			next_position.j=column+1;
			next_position.i=row+1;
			moved=1;
            if((*m)[row+1][column+1]==5)
            {
                cout<<"Player2 is winner"<<endl;
                (*m)[row+1][column+1]=2;
                next_position.i=-1;
                next_position.j=-1;
            }
		}
	}

	if((column-1>=0) && (row-1>0)&&(moved == 0)) // stanga-sus
	{
		if(((*m)[row-1][column-1]==0 )|| ((*m)[row-1][column-1]==5 ))
		{
			next_position.j=column-1;
			next_position.i=row-1;
			moved=1;
			if((*m)[row-1][column-1]==5)
            {
                cout<<"Player2 is winner"<<endl;
                (*m)[row-1][column-1]=2;
                next_position.i=-1;
                next_position.j=-1;
            }
		}
	}

	if((column+1<n-1 )&&( row-1>=0)&&(moved == 0)) //dreapta-sus
	{
		if(((*m)[row-1][column+1]==0) || ((*m)[row-1][column+1]==5 ))
		{
			next_position.j=column+1;
			next_position.i=row-1;
			moved=1;
			if((*m)[row-1][column+1]==5)
            {
                cout<<"Player2 is winner"<<endl;
                (*m)[row-1][column+1]=2;
                next_position.i=-1;
                next_position.j=-1;
            }
		}
	}

	if((column-1>=0) &&( row+1>0)&&(moved == 0)) //stanga-jos
	{
		if(((*m)[row+1][column-1]==0) || ((*m)[row+1][column-1]==5 ))
		{
			next_position.j=column-1;
			next_position.i=row+1;
			moved=1;
			if((*m)[row+1][column-1]==5)
            {
                cout<<"Player2 is winner"<<endl;
                (*m)[row+1][column-1]=2;
                next_position.i=-1;
                next_position.j=-1;
            }
		}
	}

	if(moved == 0)//parasete harta fara comoara
    {
        cout<<"No more valid moves for Player2"<<endl;
        next_position.i=-2;
        next_position.j=-2;
    }

    return next_position;
}

