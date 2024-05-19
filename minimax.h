#ifndef MINIMAX_H_INCLUDED
#define MINIMAX_H_INCLUDED
class Plateau;

class Minimax{

public:
    int trouverMeilleurCoup(Plateau* grille, int profondeur, int pion);
    int evaluer(Plateau* grille);
    int meilleurCoup(Plateau *grille, int pion,int difficulte);






};

#endif // MINIMAX_H_INCLUDED
