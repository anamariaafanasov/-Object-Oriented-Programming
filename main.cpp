#include <iostream>
#include "gestionare_joc.h"


using namespace std;

int main()
{
    int numar_runda=1;
    int merg_mai_departe=1;
    cout<<"START GAME"<<endl;
    gestionare_joc joc(15);

    do {
        cout<<"Runda"<<numar_runda<<endl;
        joc.start_round();
        cout<<"doriti sa continuati? DA-press 1, NU-press 0:";
        cin>>merg_mai_departe;
        numar_runda++;
      } while (merg_mai_departe==1);
      
    return 0;
}
