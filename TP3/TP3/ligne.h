#ifndef LIGNE_H
#define LIGNE_H
#include "case.h"
#include <vector>


class Ligne
{
public:
    Ligne(int nombreCases, int coordoneeY);
    void AffichageLigne();
    Case& RetournerCaseDansLigne(int numeroCase);
    void AfficherPartieSuperieureLigne();
    void AfficherPartieInferieureLigne();
    bool LigneAppartientAuJoueur(Joueur& joueur);
private:
    std::vector<Case> casesDansLigne;
    int coordoneeY;
};

#endif // LIGNE_H
