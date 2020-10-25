#include <iostream>
#include "jeu.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
//    GrilleMorpion grilleTest = GrilleMorpion();
//    grilleTest.AffichageGrille();
//    cout<<"case vide ?"<<grilleTest.CaseVide(grilleTest.RetournerCase(0,0))<<endl;
//    Joueur joueur(1);
//    cout<<"Ligne appartient au joueur 1 ? "<<grilleTest.LigneComplete(joueur,0)<<endl;
//    cout<<"identifiant joueur "<<joueur.GetIdentifiant()<<endl;
//    grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(0,0));
//    cout<<"joueur occupant case "<<grilleTest.RetournerCase(0,0).GetJoueurOccupant()<<endl;
//    cout<<"case vide ?"<<grilleTest.CaseVide(grilleTest.RetournerCase(0,0))<<endl;
//    grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(0,1));
//    grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(0,2));
//    grilleTest.AffichageGrille();
//    cout<<"Case 0-0 appartient au joueur 1 ? "<<grilleTest.RetournerCase(0,0).CaseAppartientAuJoueur(joueur)<<endl;
//    cout<<"Ligne appartient au joueur 1 ? "<<grilleTest.LigneComplete(joueur,0)<<endl;
//    cout<<"Colonne appartient au joueur 1 ? "<<grilleTest.ColonneComplete(joueur,0)<<endl;
//    grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(1,1));
//    grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(2,0));
//    grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(2,2));
//    grilleTest.AffichageGrille();
//    cout<<"Diagonale G appartient au joueur 1 ? "<<grilleTest.DiagonaleGaucheComplete(joueur)<<endl;
//    cout<<"Diagonale D appartient au joueur 1 ? "<<grilleTest.DiagonaleDroiteComplete(joueur)<<endl;
//    cout<<"Diagonales appartiennent au joueur 1 ? "<<grilleTest.VictoireDiagonales(joueur)<<endl;
//    cout<<"Victoire ? "<<grilleTest.VictoireJoueur(joueur)<<endl;


//    GrillePuissance4 grilleTest = GrillePuissance4();
//        grilleTest.AffichageGrille();
//        cout<<"case vide ?"<<grilleTest.CaseVide(grilleTest.RetournerCase(0,0))<<endl;
//        Joueur joueur(1);
//        cout<<"Ligne appartient au joueur 1 ? "<<grilleTest.LigneComplete(joueur,0)<<endl;
//        cout<<"identifiant joueur "<<joueur.GetIdentifiant()<<endl;
//        grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(3,0));
//        cout<<"joueur occupant case "<<grilleTest.RetournerCase(0,0).GetJoueurOccupant()<<endl;
//        cout<<"case vide ?"<<grilleTest.CaseVide(grilleTest.RetournerCase(0,0))<<endl;
//        grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(3,1));
//        grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(3,0));
//        grilleTest.AffichageGrille();
//        std::cout<<grilleTest.NumeroLigneDePremiereCaseVideDansColonne(0)<<std::endl;;
//        grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(3,1));
//        grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(2,2));
//        grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(3,3));
//        grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(1,2));
//        grilleTest.AffichageGrille();
//        cout<<"case vide ?"<<grilleTest.CaseVide(grilleTest.RetournerCase(3,1))<<endl;
//        cout<<"case vide ?"<<grilleTest.CaseVide(grilleTest.RetournerCase(2,2))<<endl;
//        cout<<"case vide ?"<<grilleTest.CaseVide(grilleTest.RetournerCase(3,3))<<endl;
//        cout<<"case vide ?"<<grilleTest.CaseVide(grilleTest.RetournerCase(1,2))<<endl;
//        cout<<"case vide ?"<<grilleTest.CaseVide(grilleTest.RetournerCase(3,6))<<endl;
//        grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(0,3));
//        grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(1,4));
//        grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(2,5));
//        grilleTest.DeposerJeton(joueur, grilleTest.RetournerCase(3,6));
//        grilleTest.AffichageGrille();
//        std::cout<<"Diagonale gauche Test ? "<<grilleTest.DiagonaleGaucheComplete(joueur,3)<<std::endl;
//        std::cout<<"Multi Test Diagonales "<<grilleTest.BalayageVictoireDiagonaleGauche(joueur)<<std::endl;

Jeu jeu= Jeu();
jeu.ChoixTypeJeu();

}
