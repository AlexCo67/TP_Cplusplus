#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <point.h>


class Rectangle
{
public:

    Rectangle(int longueur, int largeur);
    Rectangle(int longueur, int largeur, Point pointHautGauche);
    void Afficher();
    int GetLongueur();
    int GetLargeur();
    Point GetPointHautGauche();
    void SetLongueur(int longueur);
    void SetLargeur(int largueur);
    void SetPointHautGauche(Point pointHautGauche);
    int PerimetreRectangle();
    int SurfaceRectangle();
    bool PlusGrandPerimetreQueParametre(Rectangle rectangle);
    bool PlusGrandeSurfaceQueParametre(Rectangle rectange);

private:
    int longueur;
    int largeur;
    Point pointHautGauche;
};

#endif // RECTANGLE_H
