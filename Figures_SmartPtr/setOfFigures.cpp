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
vector<Type> SetOfFigures::getLengthOfVectors(Figure *a)
{
    return figure->length(a);
}
Type SetOfFigures::getPerimetr(Figure *a)
{
    return figure->getP(a);
}
Type SetOfFigures::getArea(Figure *a)
{
    return figure->getA(a);
}

 Type SetOfFigures::getRelation(Figure *a)
 {
     return figure->getP(a)/figure->getA(a);
 }
/*

void SetOfFigures::outputSetOfFigures()
{
    for(Iterator it=figure->begin(); it!=figure->end(); it++)
        std::cout << *it << " ";
}
*/



