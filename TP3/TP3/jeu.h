#ifndef JEU_H
#define JEU_H
#include "grillemorpion.h"
#include "grillepuissance4.h"


class Jeu
{
public:
    Jeu();
    bool ChoixTypeJeu();
    bool DeroullementMorpion();
    bool DeroullementPuisance4();
private:
    Joueur joueur1;
    Joueur joueur2;
    bool finDuJeu;
    bool TourJoueurMorpion(Joueur& joueur,GrilleMorpion& grilleDeMorpion);
    int SelectionLigne(GrilleMorpion& grilleDeMorpion);
    int SelectionColonne(GrilleMorpion& grilleDeMorpion);
    bool TourJoueurPuissance4(Joueur& joueur,GrillePuissance4& grilleDePuissance4);
    int SelectionColonne(GrillePuissance4& grilleDePuissance4);
};

#endif // JEU_H
