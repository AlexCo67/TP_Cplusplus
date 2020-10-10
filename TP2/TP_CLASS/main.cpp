#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <point.h>
#include <rectangle.h>
#include <triangle.h>
#include <cercle.h>

using namespace std;

int main()
{
    std::cout << "Hello World!" << endl;

    Point pointTest(55,66);
    pointTest.Afficher();
    Point pointTest2(55,76);
    std::cout<<"Distance entre les deux points de test : "<<pointTest.DistanceAvecPoint(pointTest2)<<endl;
    Point pointTest3(76,76);

    Point pointTriangle1(0,0);
    Point pointTriangle2(0,5);
    Point pointTriangle3(5,0);


    Rectangle rectangleTest(55,15);
    rectangleTest.Afficher();
    Rectangle rectangleTest2(33,15, pointTest);
    rectangleTest2.Afficher();

    std::cout<<rectangleTest.PerimetreRectangle()<<endl;
    std::cout<<rectangleTest.SurfaceRectangle()<<endl;
    std::cout<<rectangleTest.PlusGrandPerimetreQueParametre(rectangleTest2)<<endl;
    std::cout<<rectangleTest.PlusGrandeSurfaceQueParametre(rectangleTest2)<<endl;

    Triangle triangleTest(pointTriangle1,pointTriangle2,pointTriangle3);
    triangleTest.Afficher();


    Point centreCercle(0,0);
    Point dansLeCercle(0,3);
    Point surLeCercle(0,5);
    Point aCoteDuCercle(10,10);
    Cercle cercleTest(centreCercle,10);
    string estDansLeCercle = (cercleTest.PointParametreSurLeCercle(surLeCercle))?"Oui, il est sur le cercle":"Non il n'est pas sur le cercle";
    std::cout<<"Le point surLeCercle est comme son nom l'indique ? "<<estDansLeCercle<<endl;
    estDansLeCercle = (cercleTest.PointParametreSurLeCercle(aCoteDuCercle))?"Oui, il est sur le cercle":"Non il n'est pas sur le cercle";
    std::cout<<"Le point aCoteDuCercle est comme son nom l'indique ? "<<estDansLeCercle<<endl;
    estDansLeCercle = (cercleTest.PointParametreDansLeCercle(dansLeCercle))?"Oui, il est dans le cercle":"Non il n'est pas dans le cercle";
    std::cout<<"Le point dansLeCercle est comme son nom l'indique ? "<<estDansLeCercle<<endl;
    estDansLeCercle = (cercleTest.PointParametreDansLeCercle(surLeCercle))?"Oui, il est dans le cercle":"Non il n'est pas dans le cercle";
    std::cout<<"Le point surLeCercle est comme son nom l'indique ? "<<estDansLeCercle<<endl;

    return 0;
}
