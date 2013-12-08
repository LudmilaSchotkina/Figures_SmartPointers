#ifndef SETOFFIGURES_H
#define SETOFFIGURES_H

#include "affTransformations.h"
#include "smartPtr.h"
class SetOfFigures
{
public:
    SetOfFigures(Figure *figure);

    vector<Coord> getCoordinatesOfFigure();
    vector<Coord> getVectors(Figure *a);
    vector<Type> getLengthOfVectors(Figure *a, bool upd);

    vector<Coord> updateLength(Figure *a, bool upd);


    Type getPerimetr(Figure *a, bool update);
    Type getArea(Figure *a, bool update);

    Type getRelation(Figure *a,bool update);

    vector<Coord> scale(Figure *a);
    Type **getOriginVector(Figure *a);
    Type **getAffTransformation();

private:
    SetOfFigures();
    Figure *figure;

};


#endif // SETOFFIGURES_H
