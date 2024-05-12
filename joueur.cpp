#include "joueur.h"
#include <iostream>

#include "plateau.h"


JoueurHumain::JoueurHumain(int p, Plateau* g) : Joueur(p,g)  {
    setPseudo();
}


void JoueurHumain ::  setPseudo(){
    std::cout<<"Entrez votre pseudo :  ";
    std::cin>> pseudo;
}

int JoueurHumain::choisirCoup(){
    int coup;
    std::cout<<"Selectionnez une colonne où placer votre pion "<<pseudo<<" : ";
    std:: cin>>coup;
    return coup--;
}
