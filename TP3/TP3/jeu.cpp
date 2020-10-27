#include "jeu.h"
#include <iostream>

Jeu::Jeu() :joueur1(1), joueur2(2)
{
    this->finDuJeu=false;
}
bool Jeu::ChoixTypeJeu(){
    std::cout<<"Veuillez choisir le type de jeu"<<std::endl<<"Tapez 1 pour le morpion"<<std::endl<<"Tapez 2 pour le puissance 4"<<std::endl;
    int choixJeu;
    std::cin>>choixJeu;
    if(!std::cin){
        std::cout<<"Veuillez entrer une valeur numérique correcte"<<std::endl;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    }
    switch (choixJeu) {
    case 1:
        std::cout<<"Morpion"<<std::endl;
        return this->DeroullementMorpion();
    case 2:
        std::cout<<"Puissance 4"<<std::endl;
        return this->DeroullementPuisance4();
    default:
        std::cout<<"Morpion par défaut."<<std::endl;
        return this->DeroullementMorpion();
    }
}

bool Jeu::DeroullementMorpion(){
    GrilleMorpion grilleDeMorpion= GrilleMorpion();
    while(!this->finDuJeu){
        if(this->TourJoueurMorpion(this->joueur1, grilleDeMorpion)){
            grilleDeMorpion.AffichageGrille();
            std::cout<<"Féliciation joueur1 vous avez gagné"<<std::endl;
           return finDuJeu=true;
            }
        if(grilleDeMorpion.GrillePleine()){
            grilleDeMorpion.AffichageGrille();
            std::cout<<"La grille est pleine !"<<std::endl;
            return finDuJeu=true;
            }
       if(this->TourJoueurMorpion(this->joueur2, grilleDeMorpion)){
           grilleDeMorpion.AffichageGrille();
           std::cout<<"Féliciation joueur2 vous avez gagné"<<std::endl;
           return finDuJeu=true;
         }
       if(grilleDeMorpion.GrillePleine()){
           grilleDeMorpion.AffichageGrille();
           std::cout<<"La grille est pleine !"<<std::endl;
           return finDuJeu=true;
           }
    }
    grilleDeMorpion.AffichageGrille();
    std::cout<<"La grille est pleine !"<<std::endl;
    return this->finDuJeu=true;
}

int Jeu::SelectionLigne(GrilleMorpion& grilleDeMorpion){
    bool selectionValide=false;
    int numeroLigne;
    while(!selectionValide){
        std::cout<<"Selectionnez une ligne de la grille"<<std::endl;
        std::cin>>numeroLigne;
        if(!std::cin){
            std::cout<<"Veuillez entrer une valeur numérique contenue entre 1 et 3"<<std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
        else if(grilleDeMorpion.LigneValide(numeroLigne)){
            selectionValide=true;
        }
        else{
            std::cout<<"Veuillez entrer une valeur numérique contenue entre 1 et 3"<<std::endl;
        }
    }
    return numeroLigne;
}

int Jeu::SelectionColonne(GrilleMorpion& grilleDeMorpion){
    bool selectionValide=false;
    int numeroColonne;
    while(!selectionValide){
        std::cout<<"Selectionnez une colonne de la grille"<<std::endl;
        std::cin>>numeroColonne;
        if(!std::cin){
            std::cout<<"Veuillez entrer une valeur numérique contenue entre 1 et 3"<<std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
        else if(grilleDeMorpion.ColonneValide(numeroColonne)){
            selectionValide=true;
        }
        else{
            std::cout<<"Veuillez entrer une valeur numérique contenue entre 1 et 3"<<std::endl;
        }
    }
    return numeroColonne;
}

bool Jeu::TourJoueurMorpion(Joueur& joueur, GrilleMorpion& grilleDeMorpion){
    grilleDeMorpion.AffichageGrille();
    std::cout<<"Joueur "<<joueur.GetIdentifiant()<<" à vous de jouer"<<std::endl;
    bool caseValide=false;
    int numeroLigne;
    int numeroColonne;
    while(!caseValide){
        std::cout<<"Choisissez une case vide"<<std::endl;
        numeroLigne=this->SelectionLigne(grilleDeMorpion);
        numeroColonne=this->SelectionColonne(grilleDeMorpion);
        caseValide=grilleDeMorpion.CaseVide(grilleDeMorpion.RetournerCase(numeroLigne-1,numeroColonne-1));
    }
    grilleDeMorpion.DeposerJeton(joueur, grilleDeMorpion.RetournerCase(numeroLigne-1, numeroColonne-1));
    return grilleDeMorpion.VictoireJoueur(joueur);
}




bool Jeu::DeroullementPuisance4(){
    GrillePuissance4 grilleDePuissance4= GrillePuissance4();
    while(!this->finDuJeu){
        if(this->TourJoueurPuissance4(this->joueur1, grilleDePuissance4)){
            grilleDePuissance4.AffichageGrille();
            std::cout<<"Féliciation joueur1 vous avez gagné"<<std::endl;
           return finDuJeu=true;
            }
        if(grilleDePuissance4.GrillePleine()){
            grilleDePuissance4.AffichageGrille();
            std::cout<<"La grille est pleine !"<<std::endl;
            return finDuJeu=true;
            }
       if(this->TourJoueurPuissance4(this->joueur2, grilleDePuissance4)){
           grilleDePuissance4.AffichageGrille();
           std::cout<<"Féliciation joueur2 vous avez gagné"<<std::endl;
           return finDuJeu=true;
         }
       if(grilleDePuissance4.GrillePleine()){
           grilleDePuissance4.AffichageGrille();
           std::cout<<"La grille est pleine !"<<std::endl;
           return finDuJeu=true;
           }
    }
    grilleDePuissance4.AffichageGrille();
    std::cout<<"La grille est pleine !"<<std::endl;
    return this->finDuJeu=true;
}


int Jeu::SelectionColonne(GrillePuissance4& grilleDePuissance4){
    bool selectionValide=false;
    int numeroColonne;
    while(!selectionValide){
        std::cout<<"Selectionnez une colonne de la grille"<<std::endl;
        std::cin>>numeroColonne;
        if(!std::cin){
            std::cout<<"Veuillez entrer une valeur numérique contenue entre 1 et 7"<<std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
        else if(grilleDePuissance4.ColonneValide(numeroColonne)){
            selectionValide=true;
        }
        else{
            std::cout<<"Veuillez entrer une valeur numérique contenue entre 1 et 7"<<std::endl;
        }
    }
    return numeroColonne;
}


bool Jeu::TourJoueurPuissance4(Joueur& joueur, GrillePuissance4& grilleDePuissance4){
    grilleDePuissance4.AffichageGrille();
    std::cout<<"Joueur "<<joueur.GetIdentifiant()<<" à vous de jouer"<<std::endl;
    bool caseValide=false;
    int numeroColonneInput;
    int numeroLigne;
    while(!caseValide){
        std::cout<<"Choisissez une colonne"<<std::endl;
        numeroColonneInput=this->SelectionColonne(grilleDePuissance4);
        if(!grilleDePuissance4.ColonnePleine(numeroColonneInput-1)){
            numeroLigne=grilleDePuissance4.NumeroLigneDePremiereCaseVideDansColonne(numeroColonneInput-1);
            std::cout<<numeroLigne<<std::endl;
            caseValide=grilleDePuissance4.CaseVide(grilleDePuissance4.RetournerCase(numeroLigne,numeroColonneInput-1));
        }
        else{
            std::cout<<"La colonne est pleine ! "<<std::endl;
        }
    }
    grilleDePuissance4.DeposerJeton(joueur, grilleDePuissance4.RetournerCase(numeroLigne, numeroColonneInput-1));
    std::cout<<"fin du tour du joueur"<<joueur.GetIdentifiant()<<std::endl;
    return grilleDePuissance4.VictoireJoueur(joueur);
}

