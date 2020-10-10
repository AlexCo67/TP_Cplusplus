#include "triangle.h"
#include "point.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

bool Triangle::DoubleEquals(double a, double b, double epsilon = 0.001)
{
    return std::abs(a - b) < epsilon;
}

Triangle::Triangle(Point sommet1, Point sommet2, Point sommet3)
{
    this->sommet1=sommet1;
    this->sommet2=sommet2;
    this->sommet3=sommet3;
}
Point Triangle::GetSommet1(){
      return this->sommet1;
}
Point Triangle::GetSommet2(){
      return this->sommet2;
}
Point Triangle::GetSommet3(){
      return this->sommet3;
}
void Triangle::SetSommet1(Point sommet1){
    this->sommet1=sommet1;
}
void Triangle::SetSommet2(Point sommet2){
    this->sommet2=sommet2;
}
void Triangle::SetSommet3(Point sommet3){
    this->sommet3=sommet3;
}

double Triangle::LongueurCoteTriangle(Point sommet1, Point sommet2){
    return sqrt(pow(sommet1.coordoneeX-sommet2.coordoneeX,2)+pow(sommet1.coordoneeY-sommet2.coordoneeY,2));
}

int Triangle::BaseTriangle(){
    int distanceSommet1Sommet2 = sommet1.DistanceAvecPoint(sommet2);
    int distanceSommet1Sommet3= sommet1.DistanceAvecPoint(sommet3);
    int distanceSommet2Sommet3= sommet2.DistanceAvecPoint(sommet3);
//comparaison des trois côtés du triangle, la base est le plus grand côté
    if(distanceSommet1Sommet2>distanceSommet1Sommet3 && distanceSommet1Sommet2>distanceSommet2Sommet3){
        return distanceSommet1Sommet2;
    }
    else if(distanceSommet1Sommet3>distanceSommet2Sommet3){
        return distanceSommet1Sommet3;
    }
    else{
        return distanceSommet2Sommet3;
    }
}

int Triangle::PerimetreTriangle(){
    return (sommet1.DistanceAvecPoint(sommet2)+sommet1.DistanceAvecPoint(sommet3)+sommet2.DistanceAvecPoint(sommet3));
}

int Triangle::SurfaceTriangle(){
    //Application du Théorème de Héron
    int distanceSommet1Sommet2 = sommet1.DistanceAvecPoint(sommet2);
    int distanceSommet1Sommet3= sommet1.DistanceAvecPoint(sommet3);
    int distanceSommet2Sommet3= sommet2.DistanceAvecPoint(sommet3);
    int demiPerimetre = (this->PerimetreTriangle())/2;
    return (sqrt(demiPerimetre*(demiPerimetre-distanceSommet1Sommet2)*(demiPerimetre-distanceSommet1Sommet3)*(demiPerimetre-distanceSommet2Sommet3)));
}

int Triangle::HauteurTriangle(){
    //Surface = Base*Hauteur/2 <=> Hauteur =2*Surface/Base
    return 2*(this->SurfaceTriangle()/this->BaseTriangle());
}
bool Triangle::TriangleEstEquilateral(){
    //comparaison d'une longueur avec les deux autres, les trois doivent être égales (si a=b et a=c, b=c donc pas de troisième test)
    double cote1=this->LongueurCoteTriangle(sommet1,sommet2);
    double cote2=this->LongueurCoteTriangle(sommet1,sommet3);
    double cote3=this->LongueurCoteTriangle(sommet2,sommet3);
    return(DoubleEquals(cote1,cote2)&&DoubleEquals(cote1,cote3));
}

bool Triangle::TriangleEstIsocele(){
    //comparaison d'une longueur avec les deux autres, au moins deux sont égales. On doit vérifier les trois cas possibles a=b, a=c et b=c
    double cote1=this->LongueurCoteTriangle(sommet1,sommet2);
    double cote2=this->LongueurCoteTriangle(sommet1,sommet3);
    double cote3=this->LongueurCoteTriangle(sommet2,sommet3);
    return(DoubleEquals(cote1,cote2)||DoubleEquals(cote1,cote3)||DoubleEquals(cote2,3));
}


bool Triangle::TriangleEstRectangle(){
    double cote1AuCarre=pow(this->LongueurCoteTriangle(sommet1,sommet2),2);
    double cote2AuCarre=pow(this->LongueurCoteTriangle(sommet1,sommet3),2);
    double cote3AuCarre=pow(this->LongueurCoteTriangle(sommet2,sommet3),2);
    return(DoubleEquals(cote1AuCarre,cote2AuCarre)||DoubleEquals(cote1AuCarre,cote3AuCarre)||DoubleEquals(cote2AuCarre,cote3AuCarre));
}


void Triangle::Afficher(){
    std::cout<<"Les trois points du triangle sont :"<<endl;
    sommet1.Afficher();
    sommet2.Afficher();
    sommet3.Afficher();
    std::cout<<"Les trois longueurs font :"<<this->LongueurCoteTriangle(sommet1,sommet2)<<", "<<this->LongueurCoteTriangle(sommet1,sommet3)<<", "<<this->LongueurCoteTriangle(sommet2,sommet3)<<", "<<endl;
    std::cout<<"Le périmètre du triangle fait : "<<this->PerimetreTriangle()<<" et sa surface fait : "<<this->SurfaceTriangle()<<endl;
    std::cout<<"Sa base fait : "<<this->BaseTriangle()<<" et sa hauteur fait "<<this->HauteurTriangle()<<endl;
    string equilateral= (this->TriangleEstEquilateral()) ? "Le triangle est équilateral" : "Le triangle n'est pas équilatéral";
    std::cout<<equilateral<<endl;
    string isocele= (this->TriangleEstIsocele()) ? "Le triangle est isocèle" : "Le triangle n'est pas isocèle";
    std::cout<<isocele<<endl;
    string rectangle= (this->TriangleEstRectangle()) ? "Le triangle est rectangle" : "Le triangle n'est pas rectangle";
    std::cout<<rectangle<<endl;
}
