#ifndef PUISSANCE5_H_INCLUDED
#define PUISSANCE5_H_INCLUDED

class Joueur;
class Plateau;

class Puissance5{
private:
    Joueur* joueur1;
    Joueur* joueur2;
    Plateau* plateau;
public:

    Puissance5();
    ~Puissance5();
    void menuSelection1();
    void menuSelection2();
    int jouer();
};

#endif // PUISSANCE5_H_INCLUDED
