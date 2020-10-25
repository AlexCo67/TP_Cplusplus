#include "case.h"

Case::Case(int coordoneeX, int coordoneeY)
{
    this->coordoneeX=coordoneeX;
    this->coordoneeY=coordoneeY;
    this->joueurOccupant=0;
}

void Case::AffichageCase(){
    std::cout<<"| "<<this->joueurOccupant<<" |";
}

int Case::GetJoueurOccupant(){
    return this->joueurOccupant;
}

void Case::SetJoueurOccupant(Joueur& joueur){
    this->joueurOccupant=joueur.GetIdentifiant();
}

bool Case::CaseAppartientAuJoueur(Joueur &joueur){
    return this->joueurOccupant==joueur.GetIdentifiant();
}
