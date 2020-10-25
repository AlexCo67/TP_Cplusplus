#include "joueur.h"

Joueur::Joueur(int identifiant)
{
    this->identifiant=identifiant;
}

int Joueur::GetIdentifiant(){
    return this->identifiant;
}
