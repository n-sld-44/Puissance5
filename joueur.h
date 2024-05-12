#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <string>

class Plateau;

class Joueur{
private:

    int pion;
    Plateau* grille;
public:

    std::string pseudo;
    Joueur(int p, Plateau* g)  : pion(p), grille(g) {};

    virtual int choisirCoup() = 0;

    virtual void setPseudo() = 0;

};

class JoueurHumain : public Joueur{

public:
    JoueurHumain(int p,Plateau* g);

    int choisirCoup();

    void setPseudo();


};





#endif // JOUEUR_H_INCLUDED
