#include "affTransformations.h"
#include "setOfFigures.h"


vector<Coord> Circle::getCoord()
{
    getCenter();
    getRadius();
}
Coord Circle::getCenter()
{
    Coord value;
    vector <Coord> coordinates;


    fstream filecircle;
    filecircle.open("circle.txt");

    if(!filecircle)
    cerr<<"Error 404"<<endl;


    while(!filecircle.eof())
    {
        filecircle>>value.x;
        filecircle>>value.y;
    }
    filecircle.close();

    return value;
}
Type Circle::getRadius()
{
    Coord value;
    vector <Coord> coordinates;
    Type radius;

    fstream filecircle;
    filecircle.open("circle.txt");

    if(!filecircle)
        cerr<<"Error 404"<<endl;

    while(!filecircle.eof())
    {
        filecircle>>value.x;
        filecircle>>value.y;
        filecircle>>radius;
    }
    filecircle.close();

    return radius;
}

vector<Coord> Circle::buildVectors (Figure *figure)
{
    Circle *circle = (Circle*)figure;
    vector <Coord> coordinates;
    coordinates=circle->getCoord();

    vector <Coord> vect;

    vector<Coord>::iterator i;
    Coord a;
    Type i_coord=0;

    for (i=coordinates.begin()+1; i<coordinates.end(); ++i)
    {
        a.x=(*i).x - coordinates.at(i_coord).x;
        a.y=(*i).y - coordinates.at(i_coord).y;
        vect.push_back(a);
        ++i_coord;
    }

    a.x=coordinates.front().x - coordinates.back().x;
    a.y=coordinates.front().y - coordinates.back().y;
    vect.push_back(a);

    return vect;
}

Type Circle::perimetr(Figure *figure)
{
    Circle *circle = (Circle *)figure;
    Coord pos=circle->getCenter();
    Type r=circle->getRadius();


    Type perim=2*PI*r;

    cout<<"Perimetr = "<<perim<<endl;
    return perim;
}

Type Circle::area(Figure *figure)
{
    Circle *circle=(Circle *)figure;
    Coord pos=circle->getCenter();
    Type r=circle->getRadius();

    Type a=PI*r*r;

    cout<<"Area = "<<a<<endl;

    return a;
}


