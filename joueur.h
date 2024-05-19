#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <string>


class Plateau;

class Joueur{
public:
    int pion;
    Plateau* grille;
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

class Ia_niv0 : public Joueur{
public:
    Ia_niv0(int p,Plateau*g);
    void setPseudo();

    int choisirCoup();


};

class Ia : public Joueur{
private:
    int difficulte;
public:

    Ia(int p,Plateau*g);
    ~Ia();

    void selectDiff();
    void setPseudo();

    int choisirCoup();
};

void afficherCurseur(int cursor);


#endif // JOUEUR_H_INCLUDED
