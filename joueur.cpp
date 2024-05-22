#include "joueur.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "plateau.h"
#include <limits.h>
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


Ia::Ia(int p, Plateau* g) : Joueur(p,g){
    this->selectDiff();
    setPseudo();
}

Ia::~Ia(){

}
void Ia::selectDiff(){
    int dif = 1;
    int keyPressed;
    do{
        std::system("cls");
        std::cout<<"Modifiez le niveau de difficulté de l'Ia avec les fleches Up and Down du clavier et space pour valider"<<std::endl<<std::endl;
        std:: cout<<dif;
        keyPressed = _getch();
        if (keyPressed ==80 && dif>1){
            dif--;
        }
        else if (keyPressed == 72 && dif<10){
            dif++;
        }


    }while (keyPressed != 32);

this->difficulte = dif;
}

void Ia::setPseudo(){
    this->pseudo = "Robot avec "+std::to_string(this->difficulte*20)+ " de QI";
}


/////////////

int Ia::choisirCoup(){
    int meilleurCoup = -1;

    if (this->pion==1){
        int meilleurScore = INT_MIN;

        for (int c = 0; c < this->grille->col; c++) {
            if (this->grille->placerPion(c, 1)) {
                int score = this->grille->minimax(this->difficulte, INT_MIN, INT_MAX, -1);
                this->grille->retirerPion(c);

                if (score > meilleurScore) {
                    meilleurScore = score;
                    meilleurCoup = c;
                }
            }
        }

    }
    else{
        int meilleurScore = INT_MAX;


        for (int c = 0; c < this->grille->col; c++) {
            if (this->grille->placerPion(c, -1)) {
                int score = this->grille->minimax(this->difficulte, INT_MIN, INT_MAX, 1);
                this->grille->retirerPion(c);

                if (score < meilleurScore) {
                    meilleurScore = score;
                    meilleurCoup = c;
                }
            }
        }

    }
    return meilleurCoup;

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
