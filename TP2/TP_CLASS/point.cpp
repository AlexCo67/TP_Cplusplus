#include "point.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

Point::Point(){
    coordoneeX=0;
    coordoneeY=0;
}

Point::Point(float abssice, float ordonnee)
{
    coordoneeX=abssice;
    coordoneeY=ordonnee;
}

void Point::Afficher(){
    std::cout<<"Le point a pour coordonnées X et Y : "<<coordoneeX<<" "<<coordoneeY<<endl;
}

//théorème de pythagore appliqué à deux points dans un plan carthésien
//utilisée pour donner des approximations en int
int Point::DistanceAvecPoint(Point point2){
    float result=sqrtf(pow(this->coordoneeX-point2.coordoneeX,2)+pow(this->coordoneeY-point2.coordoneeY,2));
    return static_cast<int>(result);
}
