#include "plateau.h"
#include <iostream>
#include <windows.h>

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
        std::cout<<" "<<std::endl<<std::string(col*6+1,' ');
        SetConsoleTextAttribute(hConsole, 7);
        std::cout<<std::endl;
    }
    SetConsoleTextAttribute(hConsole, 7);

}

bool Plateau::placerPion(int c, int pion){
    for (int i = 0;i<line;i++){
        if (grille[c][i]==0){
            grille[c][i] = pion;
            return true;
        }

    }
    return false;
}

bool Plateau::retirerPion(int c){
    for (int i = line-1; i>=0; i--){
        if (grille[c][i] != 0){
            grille[c][i] = 0;
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


