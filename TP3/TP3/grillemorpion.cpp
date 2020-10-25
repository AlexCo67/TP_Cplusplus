#include "grillemorpion.h"

GrilleMorpion::GrilleMorpion()
{
    for(int numeroLigne=0;numeroLigne<this->NOMBRELIGNESDANSGRILLE;++numeroLigne){
        this->lignesDansGrille.push_back(Ligne(this->NOMBRECOLONNESDANSGRILLE, numeroLigne));
    };
}

Ligne& GrilleMorpion::RetournerLigneDansGrille(int numeroLigne){
    return this->lignesDansGrille[numeroLigne];
}

void GrilleMorpion::AfficherHautCadre(){
    for(int numeroCase=0;numeroCase<(int)this->NOMBRECOLONNESDANSGRILLE;++numeroCase){
        std::cout<<" ___ ";
    }
    std::cout<<std::endl;
}


void GrilleMorpion::AffichageGrille(){
    this->AfficherHautCadre();
    for(int numeroLigne=0;numeroLigne<this->NOMBRELIGNESDANSGRILLE;++numeroLigne)
    {
        this->RetournerLigneDansGrille(numeroLigne).AffichageLigne();
    }
    std::cout<<std::endl;
}

Case& GrilleMorpion::RetournerCase(int numeroLigne, int numeroColonne){
    return this->RetournerLigneDansGrille(numeroLigne).RetournerCaseDansLigne(numeroColonne);
}

bool GrilleMorpion::CaseVide(Case& caseATester){
    return (caseATester.GetJoueurOccupant()==0);
}

void GrilleMorpion::DeposerJeton(Joueur& joueur, Case& caseDepot){
    caseDepot.SetJoueurOccupant(joueur);
}

bool GrilleMorpion::LigneComplete(Joueur &joueur, int numeroLigne){
    for (int numeroColonne=0; numeroColonne<this->NOMBRECOLONNESDANSGRILLE;++numeroColonne){
        if(!this->RetournerCase(numeroLigne,numeroColonne).CaseAppartientAuJoueur(joueur)){
            return false;
        }
    }
    return true;
}

bool GrilleMorpion::ColonneComplete(Joueur &joueur, int numeroColonne){
    for (int numeroLigne=0; numeroLigne<this->NOMBRELIGNESDANSGRILLE;++numeroLigne){
        if(!this->RetournerCase(numeroLigne,numeroColonne).CaseAppartientAuJoueur(joueur)){
            return false;
        }
    }
    return true;
}

bool GrilleMorpion::VictoireDiagonales(Joueur &joueur){
    return this->DiagonaleGaucheComplete(joueur)||this->DiagonaleDroiteComplete(joueur);
}

bool GrilleMorpion::DiagonaleGaucheComplete(Joueur &joueur){
    int numeroLigne=0;
    for (int numeroColonne=0;numeroColonne<this->NOMBRELIGNESDANSGRILLE;++numeroColonne){
        if(!this->RetournerCase(numeroLigne,numeroColonne).CaseAppartientAuJoueur(joueur)){
            return false;
        }
        else{
            ++numeroLigne;
        }
    }
    return true;
}

bool GrilleMorpion::DiagonaleDroiteComplete(Joueur &joueur){
    int numeroLigne=0;
    for (int numeroColonne=this->NOMBRELIGNESDANSGRILLE-1;numeroColonne>=0;--numeroColonne){
        if(!this->RetournerCase(numeroLigne,numeroColonne).CaseAppartientAuJoueur(joueur)){
            return false;
        }
        else{
            ++numeroLigne;
        }
    }
    return true;
}

bool GrilleMorpion::VictoireColonnes(Joueur &joueur){
    for (int numeroColonne=0; numeroColonne<this->NOMBRECOLONNESDANSGRILLE;++numeroColonne){
        if(this->ColonneComplete(joueur,numeroColonne)){
            return true;
        }
    }
    return false;
}

bool GrilleMorpion::VictoireLignes(Joueur &joueur){
    for (int numeroLigne=0; numeroLigne<this->NOMBRELIGNESDANSGRILLE;++numeroLigne){
        if(this->LigneComplete(joueur,numeroLigne)){
            return true;
        }
    }
    return false;
}

bool GrilleMorpion::VictoireJoueur(Joueur &joueur){
    return (this->VictoireColonnes(joueur)||this->VictoireLignes(joueur)||this->VictoireDiagonales(joueur));
}

bool GrilleMorpion::GrillePleine(){
    for (int numeroLigne=0;numeroLigne<this->NOMBRELIGNESDANSGRILLE;++numeroLigne){
        for (int numeroColonne=0;numeroColonne<this->NOMBRECOLONNESDANSGRILLE;++numeroColonne){
            if(this->CaseVide(this->RetournerCase(numeroLigne, numeroColonne))){
                return false;
            }
        }
    }
    return true;
}

bool GrilleMorpion::LigneValide(int numeroLigne){
    return(numeroLigne>0&&numeroLigne<=this->NOMBRELIGNESDANSGRILLE);
}

bool GrilleMorpion::ColonneValide(int numeroColonne){
    return(numeroColonne>0&&numeroColonne<=this->NOMBRECOLONNESDANSGRILLE);
}
