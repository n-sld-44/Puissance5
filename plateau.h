#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include <vector>

class Plateau{
private:
    int line;

    int** grille;
    int nbPions;
    int nbMaxPions;
public:
    int col;
    Plateau();
    Plateau(int l, int c) ;

    ~Plateau();

    void afficher() ;

    bool placerPion(int colonne, int  pion) ;

    bool retirerPion(int colonne);

    bool verifierVictoire(int pion) const;

    int evaluer() const;

    int minimax(int profondeur, int alpha, int beta, bool maximizingPlayer);


};


#endif // PLATEAU_H_INCLUDED
