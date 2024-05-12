#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include <vector>

class Plateau{

private:
    int line;
    int** grille;

public:
    int col;


    Plateau();

    ~Plateau();

    void afficher() ;

    bool placerPion(int colonne, int  pion) ;

    bool retirerPion(int colonne);

    bool verifierVictoire(int pion) const;

};


#endif // PLATEAU_H_INCLUDED
