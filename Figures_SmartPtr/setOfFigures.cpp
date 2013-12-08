#include "setOfFigures.h"


SetOfFigures::SetOfFigures():
    figure(0)
{}

SetOfFigures::SetOfFigures(Figure *figure):
    figure(figure)
{}

vector<Coord> SetOfFigures::getCoordinatesOfFigure()
{
    return figure->getCoordinates();
}

vector<Coord> SetOfFigures::getVectors(Figure *a)
{
    return figure->buildFigure(a);
}

vector<Type> SetOfFigures::getLengthOfVectors(Figure *a, bool upd)
{
    return figure->length(a, upd);
}
vector<Coord> SetOfFigures::updateLength(Figure *a, bool upd)
{
    return figure->updLength(a,upd);
}

Type SetOfFigures::getPerimetr(Figure *a, bool update)
{
    return figure->getP(a,  update);
}
Type SetOfFigures::getArea(Figure *a, bool update)
{
    return figure->getA(a,  update);
}

 Type SetOfFigures::getRelation(Figure *a, bool update)
 {
     return figure->getP(a,update)/figure->getA(a,update);
 }

vector<Coord> SetOfFigures::scale(Figure *a)
{
    return figure->changeSize(a);
}

Type **SetOfFigures::getOriginVector(Figure *a)
{
    return figure->getVector(a);
}

Type **SetOfFigures::getAffTransformation()
{
    return figure->affTransf();
}

