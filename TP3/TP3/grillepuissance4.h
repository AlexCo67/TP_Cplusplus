#ifndef GRILLEPUISSANCE4_H
#define GRILLEPUISSANCE4_H
#include "ligne.h"


class GrillePuissance4
{
public:
    GrillePuissance4();
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
    bool DiagonaleGaucheComplete(Joueur& joueur, int colonneInput);
    bool DiagonaleDroiteComplete(Joueur& joueur, int colonneInput);
    bool BalayageVictoireDiagonaleGauche(Joueur& joueur);
    bool BalayageVictoireDiagonaleDroite(Joueur& joueur);
    bool VictoireJoueur(Joueur& joueur);
    bool GrillePleine();
    bool ColonneValide(int numeroColonne);
    int NumeroLigneDePremiereCaseVideDansColonne (int numeroColonne);
//    Case& PremiereCaseVideDeColonne(int numeroColonne); //A REVOIR
    bool ColonnePleine(int numeroColonne);
private:
    std::vector<Ligne> lignesDansGrille;
    const int NOMBRELIGNESDANSGRILLE = 4;
    const int NOMBRECOLONNESDANSGRILLE=7;
    const int NOMBREJETONSALIGNESPOURVICTOIRE = 4;
};

#endif // GRILLEPUISSANCE4_H
