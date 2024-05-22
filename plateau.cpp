#include "plateau.h"
#include <iostream>
#include <windows.h>
#include <limits.h>



Plateau::Plateau(){
    std::cout<<"Nombre de lignes"<<std::endl;
    std::cin>>line;
    while(line<5 ){
        std::cout<<"Nombre de lignes"<<std::endl;
        std::cin>>line;
    }
    std::cout<<"Nombre de colonnes"<<std::endl;
    std::cin>>col;
    while(col<5){
        std::cout<<"Nombre de colonnes"<<std::endl;
        std::cin>>col;
    }
    grille = new int*[col];
    for (int i=0;i<col;i++){
        grille[i] = new int[line];
        for (int j =0; j<line;j++){
            grille[i][j]= 0;
        }
    }
    nbMaxPions = line*col;
    nbPions = 0;
}
Plateau::Plateau(int l, int c): line(l), col(c) , nbMaxPions(l*c),nbPions(0) {
            grille = new int*[col];
            for (int i=0;i<col;i++){
                grille[i] = new int[line];
                for (int j =0; j<line;j++){
                    grille[i][j]= 0;
                }
            }

    }
Plateau::~Plateau(){
    for (int i = 0;i< col;++i) {
            delete[] grille[i];
        }
        delete[] grille;
    }

void Plateau::afficher() {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    const char* caracter;
    for (int i =line-1;i>=0;i--){
        for (int j = 0; j<col;j++){
            SetConsoleTextAttribute(hConsole, 17);
            std::cout<<" ";
            if (grille[j][i]==1){
                SetConsoleTextAttribute(hConsole, 240);
                std::cout<<"     ";
            }
            else if (grille[j][i]==-1){
                SetConsoleTextAttribute(hConsole, 204);
                std::cout<<"     ";
            }
            else{
                SetConsoleTextAttribute(hConsole, 7);
                std::cout<<"     ";
            }
        }
        SetConsoleTextAttribute(hConsole, 17);
        std::cout<<" ";
        SetConsoleTextAttribute(hConsole, 7);
        std::cout<<std::endl;
        for (int j = 0; j<col;j++){
            SetConsoleTextAttribute(hConsole, 17);
            std::cout<<" ";
            if (grille[j][i]==1){
                SetConsoleTextAttribute(hConsole, 240);
                std::cout<<"     ";
            }
            else if (grille[j][i]==-1){
                SetConsoleTextAttribute(hConsole, 204);
                std::cout<<"     ";
            }
            else{
                SetConsoleTextAttribute(hConsole, 7);
                std::cout<<"     ";
            }
        }
        SetConsoleTextAttribute(hConsole, 17);
        std::cout<<" ";
        SetConsoleTextAttribute(hConsole, 7);
        std::cout<<std::endl;
        for (int j = 0; j<col;j++){
            SetConsoleTextAttribute(hConsole, 17);
            std::cout<<" ";
            if (grille[j][i]==1){
                SetConsoleTextAttribute(hConsole, 240);
                std::cout<<"     ";
            }
            else if (grille[j][i]==-1){
                SetConsoleTextAttribute(hConsole, 204);
                std::cout<<"     ";
            }
            else{
                SetConsoleTextAttribute(hConsole, 7);
                std::cout<<"     ";
            }
        }
        SetConsoleTextAttribute(hConsole, 17);
        std::cout<<" ";
        SetConsoleTextAttribute(hConsole, 7);
        std::cout<<std::endl;
        SetConsoleTextAttribute(hConsole, 17);
        std::cout<<std::string(col*6+1,' ');
        SetConsoleTextAttribute(hConsole, 7);
        std::cout<<std::endl;
    }
    SetConsoleTextAttribute(hConsole, 7);

}

bool Plateau::placerPion(int c, int pion){
    for (int i = 0;i<line;i++){
        if (grille[c][i]==0){
            grille[c][i] = pion;
            this->nbPions++;
            return true;
        }

    }

    return false;
}

bool Plateau::retirerPion(int c){
    for (int i = line-1; i>=0; i--){
        if (grille[c][i] != 0){
            grille[c][i] = 0;
            this->nbPions--;
            return true;
        }
    }

    return false;
}

bool Plateau::verifierVictoire(int pion) const {

    //verif ligne
    for (int i = 0; i<line;i++){
        for (int j =0; j<col-4;j++){
            if (grille[j][i]+grille[j+1][i]+grille[j+2][i]+grille[j+3][i]+grille[j+4][i]==5*pion)
                return true;
            }

        }
    // verif colonnes
    for (int j = 0; j<col;j++){
            for (int i =0; i<line-4;i++){
                if (grille[j][i]+grille[j][i+1]+grille[j][i+2]+grille[j][i+3]+grille[j][i+4]==5*pion){
                    return true;
                }
            }

        }
    //verif diago montante
    for (int i = 0; i<line-4;i++){
            for (int j =0; j<col-4;j++ ){
                if (grille[j][i]+grille[j+1][i+1]+grille[j+2][i+2]+grille[j+3][i+3]+grille[j+4][i+4]== 5*pion){
                    return true;
                }
            }

        }
    //verif diago descendante
    for (int i = 0;i<col-4;i++){
            for (int j = line-1;j>4;j-- ){
                if (grille[i][j]+grille[i+1][j-1]+grille[i+2][j-2]+grille[i+3][j-3]+grille[i+4][j-4]== 5*pion){
                    return true;
                }
            }
    }
    return false;
}



int Plateau::minimax(int profondeur, int alpha, int beta, int  maxJoueur) {
    if(nbPions==nbMaxPions||verifierVictoire(maxJoueur)){
        if (verifierVictoire(maxJoueur)){
            return 99999*maxJoueur;
        }
        else if (verifierVictoire(maxJoueur*-1)){
            return 99999*maxJoueur*-1;
        }
        else{
            return 0;
        }
    }
    if (profondeur==0){
        return evaluer(maxJoueur);
    }

    if (maxJoueur==1) {
        int maxEval = INT_MIN;
        for (int c = 0; c < col; c++) {
            if (placerPion(c, 1)) {
                int eval = minimax(profondeur - 1, alpha, beta, -1);
                retirerPion(c);
                maxEval = std::max(maxEval, eval);
                alpha = std::max(alpha, eval);
                if (alpha >= beta) break;
            }
        }
        return maxEval;
    }
     else {
        int minEval = INT_MAX;
        for (int c = 0; c < col; c++) {
            if (placerPion(c, -1)) {
                int eval = minimax(profondeur - 1, alpha, beta, 1);
                retirerPion(c);
                minEval = std::min(minEval, eval);
                beta = std::min(beta, eval);
                if (alpha >= beta) break;
            }
        }
        return minEval;
    }
}


int Plateau::evaluer(int piece) const {

    int score =0;
    //Score colonne centrale
    int arr1[this->line];
    for (int i=0;i<line;i++){
    arr1[i]= this->grille[this->col/2][i];
    }

    score += evaluerFenetre(arr1,piece);
    delete arr1;

    //Horizontal
    for (int c=0;c<this->col-4;c++){
        for (int r=0;r<this->line;r++){
            int arr[5] = {this->grille[c][r],this->grille[c+1][r],this->grille[c+2][r],this->grille[c+3][r],this->grille[c+4][r]};
           score += evaluerFenetre(arr,piece);
        }
    }

    //vertical
    for (int c=0;c<this->col;c++){
        for (int r=0;r<this->line-4;r++){
            int arr[5] = {this->grille[c][r],this->grille[c][r+1],this->grille[c][r+2],this->grille[c][r+3],this->grille[c][r+4]};
           score += evaluerFenetre(arr,piece);
        }
    }

    //Diago montante
    for (int r=0;r<this->line-4;r++){
        for (int c=0;c<this->col-4;c++){
            int arr[5] = {this->grille[c][r],this->grille[c+1][r+1],this->grille[c+2][r+2],this->grille[c+3][r+3],this->grille[c+4][r+4]};
           score += evaluerFenetre(arr,piece);
        }
    }
    //Diago montante
    for (int r = line-1;r>4;r-- ){
        for (int c=0;c<this->col-4;c++){
            int arr[5] = {this->grille[c][r],this->grille[c+1][r-1],this->grille[c+2][r-2],this->grille[c+3][r-3],this->grille[c+4][r-4]};
           score += evaluerFenetre(arr,piece);
        }
    }
return score;


}


int evaluerFenetre(int* arr,int piece){
    int score =0;
    int opp = -1*piece;
    if (countArray(arr,piece) ==5){
        score+=200;
    }
    else if (countArray(arr,piece) ==4&&countArray(arr,0)==1){
        score+=piece*10;
    }
    else if (countArray(arr,piece) ==3&&countArray(arr,0)==2){
        score+=piece*5;
    }
    else if (countArray(arr,piece) ==2&&countArray(arr,0)==3){
        score+=piece*2;
    }
    if (countArray(arr,opp) ==4&&countArray(arr,0)==1){
        score-=piece*9;
    }
    if (countArray(arr,opp) ==3&&countArray(arr,0)==2){
        score-=piece*4;
    }
    return score;
}


int countArray(int *arr,int piece){
    int compteur =0;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i=0;i<n;i++){
        if (arr[i]==piece){
            compteur++;
        }
    }
    return compteur;
}

