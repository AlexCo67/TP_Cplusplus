#include "grillepuissance4.h"

GrillePuissance4::GrillePuissance4()
{
    for(int numeroLigne=0;numeroLigne<this->NOMBRELIGNESDANSGRILLE;++numeroLigne){
        this->lignesDansGrille.push_back(Ligne(this->NOMBRECOLONNESDANSGRILLE, numeroLigne));
    };
}

Ligne& GrillePuissance4::RetournerLigneDansGrille(int numeroLigne){
    return this->lignesDansGrille[numeroLigne];
}

void GrillePuissance4::AfficherHautCadre(){
    for(int numeroCase=0;numeroCase<(int)this->NOMBRECOLONNESDANSGRILLE;++numeroCase){
        std::cout<<" ___ ";
    }
    std::cout<<std::endl;
}

void GrillePuissance4::AffichageGrille(){
    this->AfficherHautCadre();
    for(int numeroLigne=0;numeroLigne<this->NOMBRELIGNESDANSGRILLE;++numeroLigne)
    {
        this->RetournerLigneDansGrille(numeroLigne).AffichageLigne();
    }
    std::cout<<std::endl;
}

Case& GrillePuissance4::RetournerCase(int numeroLigne, int numeroColonne){
    return this->RetournerLigneDansGrille(numeroLigne).RetournerCaseDansLigne(numeroColonne);
}

bool GrillePuissance4::CaseVide(Case& caseATester){
    return (caseATester.GetJoueurOccupant()==0);
}

void GrillePuissance4::DeposerJeton(Joueur& joueur, Case& caseDepot){
    caseDepot.SetJoueurOccupant(joueur);
}

bool GrillePuissance4::LigneComplete(Joueur &joueur, int numeroLigne){
    int nombreJetonsJoueur=0;
    for (int numeroColonne=0; numeroColonne<this->NOMBRECOLONNESDANSGRILLE;++numeroColonne){
        if(nombreJetonsJoueur>=this->NOMBREJETONSALIGNESPOURVICTOIRE){
            return true;
        }
        else if(this->RetournerCase(numeroLigne,numeroColonne).CaseAppartientAuJoueur(joueur)){
            ++nombreJetonsJoueur;
        }
        else{
            nombreJetonsJoueur=0;
        }
    }
    return false;
}

bool GrillePuissance4::ColonneComplete(Joueur &joueur, int numeroColonne){
    for (int numeroLigne=0; numeroLigne<this->NOMBRELIGNESDANSGRILLE;++numeroLigne){
        if(!this->RetournerCase(numeroLigne,numeroColonne).CaseAppartientAuJoueur(joueur)){
            return false;
        }
    }
    return true;
}

bool GrillePuissance4::VictoireDiagonales(Joueur &joueur){
    return (this->BalayageVictoireDiagonaleGauche(joueur)||this->BalayageVictoireDiagonaleDroite(joueur));
}

bool GrillePuissance4::DiagonaleGaucheComplete(Joueur &joueur, int colonneInput){
    int numeroLigne=0;
    for (int numeroColonne=0;numeroColonne<this->NOMBRELIGNESDANSGRILLE;++numeroColonne){
        if(!this->RetournerCase(numeroLigne,numeroColonne+colonneInput).CaseAppartientAuJoueur(joueur)){
            return false;
        }
        else{
            ++numeroLigne;
        }
    }
    return true;
}

bool GrillePuissance4::DiagonaleDroiteComplete(Joueur &joueur, int colonneInput){
    int numeroLigne=0;
    for (int numeroColonne=this->NOMBRECOLONNESDANSGRILLE-1;numeroColonne>=this->NOMBRELIGNESDANSGRILLE-1;--numeroColonne){
        if(!this->RetournerCase(numeroLigne,numeroColonne-colonneInput).CaseAppartientAuJoueur(joueur)){
            return false;
        }
        else{
            ++numeroLigne;
        }
    }
    return true;
}

bool GrillePuissance4::BalayageVictoireDiagonaleGauche(Joueur &joueur){
    for(int numeroColonne=0;numeroColonne<=this->NOMBRECOLONNESDANSGRILLE-this->NOMBRELIGNESDANSGRILLE;numeroColonne++){
        if(this->DiagonaleGaucheComplete(joueur, numeroColonne)){
            return true;
        }
    }
    return false;
}

//A MODIFIER
bool GrillePuissance4::BalayageVictoireDiagonaleDroite(Joueur &joueur){
    for(int numeroColonne=0;numeroColonne<=this->NOMBRECOLONNESDANSGRILLE-this->NOMBRELIGNESDANSGRILLE;numeroColonne++){
        if(this->DiagonaleDroiteComplete(joueur, numeroColonne)){
            return true;
        }
    }
    return false;
}

bool GrillePuissance4::VictoireColonnes(Joueur &joueur){
    for (int numeroColonne=0; numeroColonne<this->NOMBRECOLONNESDANSGRILLE;++numeroColonne){
        if(this->ColonneComplete(joueur,numeroColonne)){
            return true;
        }
    }
    return false;
}

bool GrillePuissance4::VictoireLignes(Joueur &joueur){
    for (int numeroLigne=0; numeroLigne<this->NOMBRELIGNESDANSGRILLE;++numeroLigne){
        if(this->LigneComplete(joueur,numeroLigne)){
            return true;
        }
    }
    return false;
}

bool GrillePuissance4::VictoireJoueur(Joueur &joueur){
    return (this->VictoireColonnes(joueur)||this->VictoireLignes(joueur)||this->VictoireDiagonales(joueur));
}

bool GrillePuissance4::GrillePleine(){
    for (int numeroLigne=0;numeroLigne<this->NOMBRELIGNESDANSGRILLE;++numeroLigne){
        for (int numeroColonne=0;numeroColonne<this->NOMBRECOLONNESDANSGRILLE;++numeroColonne){
            if(this->CaseVide(this->RetournerCase(numeroLigne, numeroColonne))){
                return false;
            }
        }
    }
    return true;
}


bool GrillePuissance4::ColonneValide(int numeroColonne){
    return(numeroColonne>0&&numeroColonne<=this->NOMBRECOLONNESDANSGRILLE);
}

//Case& GrillePuissance4::PremiereCaseVideDeColonne(int numeroColonne){
//    for(int numeroLigne=0; numeroLigne<this->NOMBRELIGNESDANSGRILLE;++numeroLigne){
//        if(this->CaseVide(this->RetournerCase(numeroLigne,numeroColonne))){
//           return RetournerCase(numeroLigne,numeroColonne);
//        }
//    }
//}

bool GrillePuissance4::ColonnePleine(int numeroColonne){
    for (int numeroLigne=this->NOMBRELIGNESDANSGRILLE-1;numeroLigne>=0;--numeroLigne){
            if(this->CaseVide(this->RetournerCase(numeroLigne, numeroColonne))){
                return false;
        }
    }
    return true;
}

int GrillePuissance4::NumeroLigneDePremiereCaseVideDansColonne(int numeroColonne){
    for(int numeroLigne=this->NOMBRELIGNESDANSGRILLE-1;numeroLigne>=0;--numeroLigne){
        if(this->CaseVide(this->RetournerCase(numeroLigne,numeroColonne))){
            return numeroLigne;
        }
    }
    return -1;
}
