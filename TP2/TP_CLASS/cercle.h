#ifndef CERCLE_H
#define CERCLE_H
#include <point.h>


class Cercle
{
public:
    Cercle(Point centre, int diametre);
    //GETTERS
    Point GetCentre();
    int GetDiametre();
    //SETTERS
    void SetCentre(Point centre);
    void SetDiametre(int diametre);

    void Afficher();
    int SurfaceCercle();
    int PerimetreCercle();
    double DistanceCentrePoint(Point point);
    bool PointParametreDansLeCercle(Point point);
    bool PointParametreSurLeCercle(Point point);

    bool DoubleEquals(double a, double b, double epsilon);


private:
    Point centre;
    int diametre;
};



#endif // CERCLE_H
