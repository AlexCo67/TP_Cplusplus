#include "ligne.h"

Ligne::Ligne(int nombreCases, int coordoneeY)
{
    for(int numeroCase=0;numeroCase<nombreCases;++numeroCase){
        this->casesDansLigne.push_back(Case(numeroCase, coordoneeY));
    }
}

Case& Ligne::RetournerCaseDansLigne(int numeroCase){
    return this->casesDansLigne[numeroCase];
}

void Ligne::AfficherPartieSuperieureLigne(){
    for(int numeroCase=0;numeroCase<(int)this->casesDansLigne.size();++numeroCase){
        std::cout<<"|   |";
    }
    std::cout<<std::endl;
}

void Ligne::AfficherPartieInferieureLigne(){
    for(int numeroCase=0;numeroCase<(int)this->casesDansLigne.size();++numeroCase){
        std::cout<<"|___|";
    }
    std::cout<<std::endl;
}

void Ligne::AffichageLigne(){
    this->AfficherPartieSuperieureLigne();
    for(int numeroCase=0;numeroCase<(int)this->casesDansLigne.size();++numeroCase){
        this->RetournerCaseDansLigne(numeroCase).AffichageCase();
    }
    std::cout<<std::endl;
    this->AfficherPartieInferieureLigne();
}

bool Ligne::LigneAppartientAuJoueur(Joueur &joueur){
    for (int numeroCase=0;numeroCase<(int)this->casesDansLigne.size();++numeroCase){
        if (!this->RetournerCaseDansLigne(numeroCase).CaseAppartientAuJoueur(joueur)){
            return false;
        }
    }
    return true;
}
