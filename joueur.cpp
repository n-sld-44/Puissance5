#include "joueur.h"
#include <iostream>
#include <cstdlib>

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
    int coup;
    std::cout<<"Selectionnez une colonne où placer votre pion "<<pseudo<<" : ";
    std:: cin>>coup;
    return coup--;
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
