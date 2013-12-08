#include "affTransformations.h"
#include "setOfFigures.h"

vector<Coord> Circle::getCoord()
{
    Coord value;
    vector <Coord> coordinates;

    fstream fileSquare;
    fileSquare.open("circle.txt");

    if(!fileSquare)
    {
        cerr<<"Error 404"<<endl;
    }

    while(!fileSquare.eof())
    {
        fileSquare>>value.x;
        fileSquare>>value.y;
        coordinates.push_back(value);
    }
    fileSquare.close();

    return coordinates;
}

vector<Coord> Circle::buildVectors (Figure *figure)
{
    Circle *circle = (Circle*)figure;
    vector <Coord> coordinates;
    coordinates=circle->getCoord();

    vector <Coord> vect;
    Coord a;
    vector<Coord>::iterator i;
    for (i=coordinates.begin()+1; i<coordinates.end(); ++i)
    {
        a.x=(*i).x - coordinates.at(0).x;
        a.y=(*i).y - coordinates.at(0).y;
        vect.push_back(a);
    }
/*
    for (i=vect.begin(); i<vect.end(); ++i)
        cout<<(*i).x<<" "<<(*i).y<<endl;
*/
    return vect;
}

Type Circle::perimetr(Figure *figure, bool update)
{

    SetOfFigures obj(figure);
    vector<Type> sides;
    sides=obj.getLengthOfVectors(figure, update);

    Type perim=0;
    vector<Type>::iterator i;
    i=sides.begin();
    double a=*i;
    double b=*(++i);
        perim=4*(PI*a*b+(a-b)*(a-b))/(a+b);

    return perim;
}

Type Circle::area(Figure *figure, bool update)
{
    SetOfFigures obj(figure);
    vector<Type> sides;
    sides=obj.getLengthOfVectors(figure, update);

    Type ar=0;
    vector<Type>::iterator i;

    i=sides.begin();
    double a=*i;
    double b=*(++i);
        ar=PI*a*b;

    return ar;
}


