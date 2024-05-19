#include "minimax.h"
#include "plateau.h"
#include <climits>
#include <iostream>

int Minimax::trouverMeilleurCoup(Plateau* grille, int profondeur, int pion) {
        std::cout<<profondeur<<std::endl;
        if (profondeur == 0||grille->nbPions==grille->nbMaxPions){
            if (grille->verifierVictoire(1)){
                return 15-profondeur;
            }
            if (grille->verifierVictoire(-1)){
                return -15+profondeur;
            }
            else {
                return 0;
            }
        }


        if (pion == -1){
            if (grille->verifierVictoire(1)){
                return 15-profondeur;
            }
            int minEval = INT_MAX;
            for (int c = 0; c < grille->col; ++c) {
                if (grille->placerPion(c, pion)) {

                    minEval = std::min(trouverMeilleurCoup(grille, profondeur - 1,pion*-1),minEval);

                    grille->retirerPion(c);
                    std::cout<<"min : "<<minEval<<std::endl;

        }
        }
            return minEval;
        }
        else if (pion ==1){
            if (grille->verifierVictoire(-1)){
                return -15+profondeur;
            }
            int maxEval = INT_MIN;
            for (int c = 0; c < grille->col; ++c) {
                if (grille->placerPion(c, pion)) {

                    maxEval = std::max(trouverMeilleurCoup(grille, profondeur - 1,pion*-1),maxEval);
                    grille->retirerPion(c);
                    std::cout<<"max : "<<maxEval<<std::endl;
            }



    }
            return maxEval;
}
}

int Minimax::evaluer(Plateau* g){
    int score =0;
    int s;

}

int Minimax::meilleurCoup(Plateau *grille, int pion,int difficulte){
    int coup = -1;
    int best = INT_MIN*pion;
    for (int c = 0; c < grille->col; ++c) {
            if (grille->placerPion(c, pion)) {

                int eval = trouverMeilleurCoup(grille, difficulte, pion);
                grille->retirerPion(c);
                if (pion == 1){
                    if (eval > best) {
                        best = eval;
                        coup = c;
                    }
            }
                else if (pion ==-1){
                    if (eval < best) {
                        best = eval;
                        coup = c;
                }
            }
        }

    }
     return coup;}






