#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "point.h"


class Triangle
{
public:
    Triangle(Point sommet1, Point sommet2, Point sommet3);

    //GETTERS
    Point GetSommet1();
    Point GetSommet2();
    Point GetSommet3();
    //SETTERS
    void SetSommet1(Point sommet1);
    void SetSommet2(Point sommet1);
    void SetSommet3(Point sommet1);

    int PerimetreTriangle();
    int BaseTriangle();
    int SurfaceTriangle();
    int HauteurTriangle();
    bool TriangleEstEquilateral();
    bool TriangleEstIsocele();
    bool TriangleEstRectangle();

    bool DoubleEquals(double a, double b, double epsilon);

    double LongueurCoteTriangle(Point sommet1, Point sommet2);

    void Afficher();

private:
    Point sommet1;
    Point sommet2;
    Point sommet3;

};

#endif // TRIANGLE_H
