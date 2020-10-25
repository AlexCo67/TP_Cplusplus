#ifndef GRILLEMORPION_H
#define GRILLEMORPION_H
#include "ligne.h"


class GrilleMorpion
{
public:
    GrilleMorpion();
    Ligne& RetournerLigneDansGrille(int numeroLigne);
    void AffichageGrille();
    void AfficherHautCadre();
    Case& RetournerCase(int numeroLigne, int numeroColonne);
    bool CaseVide(Case& caseATester);
    void DeposerJeton(Joueur& joueur, Case& caseDepot);
    bool LigneComplete(Joueur& joueur, int numeroLigne);
    bool ColonneComplete(Joueur& joueur, int numeroColonne);
    bool VictoireDiagonales(Joueur& joueur);
    bool VictoireLignes(Joueur& joueur);
    bool VictoireColonnes(Joueur& joueur);
    bool DiagonaleGaucheComplete(Joueur& joueur);
    bool DiagonaleDroiteComplete(Joueur& joueur);
    bool VictoireJoueur(Joueur& joueur);
    bool GrillePleine();
    bool LigneValide(int numeroLigne);
    bool ColonneValide(int numeroColonne);
private:
    std::vector<Ligne> lignesDansGrille;
    const int NOMBRELIGNESDANSGRILLE = 3;
    const int NOMBRECOLONNESDANSGRILLE=3;
};

#endif // GRILLEMORPION_H
