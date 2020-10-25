#ifndef CASE_H
#define CASE_H
#include <iostream>
#include "joueur.h"

class Case
{
public:
    Case(int coordoneeX, int coordoneeY);
    void AffichageCase();
    int GetJoueurOccupant();
    void SetJoueurOccupant(Joueur& joueur);
    bool CaseAppartientAuJoueur(Joueur& joueur);
private:
    int coordoneeX;
    int coordoneeY;
    int joueurOccupant;
};



#endif // CASE_H
