#include "rectangle.h"
#include "point.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

Rectangle::Rectangle(int coteGrand, int cotePetit)
{
    longueur=coteGrand;
    largeur=cotePetit;
}

Rectangle::Rectangle(int coteGrand, int cotePetit, Point CoinHG){
    longueur=coteGrand;
    largeur=cotePetit;
    pointHautGauche= CoinHG;
}

void Rectangle::Afficher(){
    std::cout<<"Le rectange a une longueur de : "<<longueur<<", une largeur de : "<<largeur<<".";
    pointHautGauche.Afficher();
    std::cout<<"Air du rectangle : "<<this->SurfaceRectangle()<<" Périmètre du rectangle : "<<this->PerimetreRectangle()<<endl;
}

int Rectangle::PerimetreRectangle(){
    return GetLargeur()*2+GetLongueur()*2;
}

int Rectangle::SurfaceRectangle(){
    return GetLargeur()*GetLongueur();
}

bool Rectangle::PlusGrandPerimetreQueParametre(Rectangle rectangle){
    return (this->PerimetreRectangle()>rectangle.PerimetreRectangle());
}

bool Rectangle::PlusGrandeSurfaceQueParametre(Rectangle rectange){
    return (this->SurfaceRectangle()>rectange.SurfaceRectangle());
}

//GETTERS
int Rectangle::GetLongueur(){
    return this->longueur;
}

int Rectangle::GetLargeur(){
    return this->largeur;
}

Point Rectangle::GetPointHautGauche(){
    return this->pointHautGauche;
}

//SETTERS
void Rectangle::SetLongueur(int longueur){
    this->longueur=longueur;
}
void Rectangle::SetLargeur(int largeur){
    this->largeur=largeur;
}
void Rectangle::SetPointHautGauche(Point pointHautGauche){
    this->pointHautGauche=pointHautGauche;
}
