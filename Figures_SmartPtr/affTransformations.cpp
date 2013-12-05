#include "affTransformations.h"
/*
Figure::Figure ():
    setOfFigures(new vector<Figure>)
    {}
*/

vector<Coord> Figure::getCoordinates()
{
    return getCoord();
}

vector<Coord> Figure::buildFigure(Figure *figure)
{
    return buildVectors(figure);
}

vector<Type> Figure::length(Figure *figure1)
{
    //return lengthOfVectors(a);

    vector <Coord> vect;
    vect=buildVectors(figure1);

    vector <Type> sides;
    vector<Coord>::iterator i;

    for (i=vect.begin(); i<vect.end(); ++i)
        sides.push_back(sqrt(((*i).x)*((*i).x)+((*i).y)*((*i).y)));
    /*
    for (Type i=0; i<3; ++i)
    {
        cout<<"len"<<sides.at(i)<<endl;
    }
    */
    return sides;
}

Type Figure::getP(Figure *square)
{
    return perimetr(square);
}
Type Figure::getA(Figure *square)
{
    return  area(square);
}
