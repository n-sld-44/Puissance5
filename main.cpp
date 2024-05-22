#include <iostream>
#include <conio.h>
#include "puissance5.h"
#include "plateau.h"
#include "joueur.h"



using namespace std;

int main()
{
    std::system("cls");
    int state;
    Puissance5* jeu =new Puissance5();
    state = jeu->jouer();
    while (state ==1){
        delete jeu;
        std::system("cls");
        Puissance5* jeu =new Puissance5();
        state = jeu->jouer();
    }
    if (state == 404){
        cout<<"Ce n'était pas dans les options, obéis aux règles la prochaine fois...";
    }
    if (state == 0 ){
        cout<<"Au revoir!";
    }

    return 0;
}



