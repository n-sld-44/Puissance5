#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include <vector>

class Plateau{
private:
    int line;

    int** grille;

public:
    int nbPions;
    int nbMaxPions;
    int col;
    Plateau();
    Plateau(int l, int c) ;

    ~Plateau();

    void afficher() ;

    bool placerPion(int colonne, int  pion) ;

    bool retirerPion(int colonne);

    bool verifierVictoire(int pion) const;

    int evaluer(int piece) const;

    int minimax(int profondeur, int alpha, int beta, int maxJoueur);


};

int evaluerFenetre(int arr[5],int piece);
int countArray(int arr[],int piece);
#endif // PLATEAU_H_INCLUDED
