#include "cercle.h"
#include <iostream>
#include "point.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

bool Cercle::DoubleEquals(double a, double b, double epsilon = 0.001)
{
    return std::abs(a - b) < epsilon;
}

Cercle::Cercle(Point centre, int diametre)
{
    this->centre=centre;
    this->diametre=diametre;
}

Point Cercle::GetCentre(){
    return this->centre;
}

int Cercle::GetDiametre(){
    return this->diametre;
}

void Cercle::SetCentre(Point centre){
    this->centre=centre;
}

void Cercle::SetDiametre(int diametre){
    this->diametre=diametre;
}

double Cercle::DistanceCentrePoint(Point point){
    return sqrt(pow(this->GetCentre().coordoneeX-point.coordoneeX,2)+pow(this->GetCentre().coordoneeY-point.coordoneeY,2));
}

int Cercle::PerimetreCercle(){
    return M_PI*this->GetDiametre();
}

int Cercle::SurfaceCercle(){
    return M_PI*pow((this->GetDiametre()/2),2);
}

bool Cercle::PointParametreSurLeCercle(Point point){
    double rayonDouble = static_cast<double>(this->GetDiametre()/2);
    return DoubleEquals(rayonDouble,this->DistanceCentrePoint(point));
}

bool Cercle::PointParametreDansLeCercle(Point point){
    double rayonDouble = static_cast<double>(this->GetDiametre()/2);
    return (this->DistanceCentrePoint(point)<rayonDouble);
}
