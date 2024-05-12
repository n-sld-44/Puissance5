#include "puissance5.h"

#include <iostream>
#include <conio.h>


#include "joueur.h"
#include "plateau.h"

#define esc 27
#define tab 9


Puissance5::Puissance5(){
    this->plateau = new Plateau();
    menuSelection1();
    menuSelection2();
}

Puissance5::~Puissance5(){
    delete plateau;
    delete joueur1;
    delete joueur2;
}

void Puissance5::menuSelection1(){
    int player;
    // ajouter les differents joueurs ici
    std::cout<<"Selectionner le joueur 1 !"<<std::endl<<" 1 : Joueur humain"<<std::endl;
    std::cin>>player;
    switch (player){
        case 1:
            this->joueur1 = new JoueurHumain(1, plateau);
            std::cout<<"Bienvenue, "<<joueur1->pseudo<<std::endl;
            break;

        default:
            menuSelection1();
}
}
void Puissance5::menuSelection2(){
    int player;
    // ajouter les differents joueurs ici
    std::cout<<"Selectionner le joueur 2 !"<<std::endl<<" 1 : Joueur humain"<<std::endl;
    std::cin>>player;
    switch (player){
    case 1:
        this->joueur2 = new JoueurHumain(1, plateau);
        std::cout<<"Bienvenue, "<<joueur2->pseudo<<std::endl;
        break;

    default:
        menuSelection2();
}
}

int Puissance5::jouer(){
    int coup;
    plateau->afficher();
    std::cout<<"Que le match commence"<<std::endl;
    while (true){

        do{
            coup = joueur1->choisirCoup();
        } while (coup<0||coup>plateau->col-1);
        plateau->placerPion(coup,1);
        plateau->afficher();

        if (plateau->verifierVictoire(1)){
            std::cout<<"Victoire de "<<joueur1->pseudo<<std::endl;
            break;
            }
        do{
            coup = joueur2->choisirCoup();
        } while (coup<0||coup>plateau->col-1);
        plateau->placerPion(coup,-1);
        plateau->afficher();
        if (plateau->verifierVictoire(-1)){
            std::cout<<"Victoire de "<<joueur2->pseudo<<std::endl;
            break;
        }
    }
    std::cout<<"Pour quitter, appuyez sur échap. Sinon pour rejouer, appuyez sur tab."<<std::endl<<std::endl;
    int key;
    key = _getch();
    switch (key){

        case esc:
            return 0;

        case tab:
            return 1;
        default:
            return 404;
        }
}

