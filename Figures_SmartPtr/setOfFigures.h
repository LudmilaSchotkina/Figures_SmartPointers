#ifndef SETOFFIGURES_H
#define SETOFFIGURES_H

#include "affTransformations.h"

class SetOfFigures
{
    public:
    SetOfFigures(Figure *figure);

    vector<Coord> getCoordinatesOfFigure();
    vector<Coord> getVectors(Figure *a);
    vector<Type> getLengthOfVectors(Figure *a);

    Type getPerimetr(Figure *a);
    Type getArea(Figure *a);

    Type getRelation(Figure *a);

    //~SetOfFigures();

    /*
    void insertValue (int);
    int findValue (int);
    void removeValue(int);
    void removeAll();

    void outputTree();
    void outputSet();
*/
//SetOfFigures &operator=(const SetOfFigures &orig);

    private:
    SetOfFigures();
    Figure *figure;

};


#endif // SETOFFIGURES_H
