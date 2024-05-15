#include "joueur.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "plateau.h"

#include <ctime>

JoueurHumain::JoueurHumain(int p, Plateau* g) : Joueur(p,g)  {
    setPseudo();
}


void JoueurHumain ::  setPseudo(){
    std::cout<<"Entrez votre pseudo :  ";
    std::cin>> pseudo;
}

int JoueurHumain::choisirCoup(){
    int keyPressed;
    int cursorPosition = 1;
    do {
        std::system("cls");

        std::cout<<"Selectionnez une colonne où placer votre pion "<<pseudo<<" :    <- et -> pour déplacer le curseur, fleche Haut pour valider le coup."<<std::endl<<std::endl<<std::endl<<std::endl;
        this->grille->afficher();
        afficherCurseur(cursorPosition);
        keyPressed = _getch();
        if (keyPressed ==75 && cursorPosition >1){
            cursorPosition= cursorPosition-6;
        }
        else if (keyPressed == 77 && cursorPosition < this->grille->col*5+1){
            cursorPosition= cursorPosition +6;
        }



    }while(keyPressed != 72);

    return (cursorPosition)/6;
}
Ia_niv0::Ia_niv0(int p, Plateau* g) : Joueur(p,g){
    setPseudo();
}

void Ia_niv0::setPseudo(){
    this->pseudo = "Robot idiot";
}
int Ia_niv0::choisirCoup(){
    srand((unsigned)time(0));
    int coup;
    coup = (rand()%this->grille->col);
    return coup;
}






void afficherCurseur(int cursor){
    for (int i=0; i <=cursor;i++){
        if (i == cursor){
            std::cout<<"^^"<<std::endl;
        }
        else{
            std::cout<<" ";
        }
    }
    for (int i=0; i <=cursor;i++){
        if (i == cursor){
            std::cout<<"||"<<std::endl;
        }
        else{
            std::cout<<" ";
        }
    }
}
