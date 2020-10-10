#ifndef POINT_H
#define POINT_H


struct Point
{
public:
    float coordoneeX;
    float coordoneeY;

    Point();
    Point(float coordoneeX, float coordoneeY);
    void Afficher();
    int DistanceAvecPoint(Point point2);

};

#endif // POINT_H
