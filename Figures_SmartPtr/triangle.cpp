#include "affTransformations.h"
#include "setOfFigures.h"

vector<Coord> Triangle::getCoord()
{
    Coord value;
    vector <Coord> coordinates;

    fstream fileSquare;
    fileSquare.open("triangle.txt");

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
    /*
                vector<Coord>::iterator i;
                for (i=coordinates.begin(); i<coordinates.end(); ++i)
                    cout<<(*i).x<<" "<<(*i).y<<endl;
    */
    return coordinates;
}


vector<Coord> Triangle::buildVectors (Figure *figure)
{
    Triangle *triangle = (Triangle *)figure;
    vector <Coord> coordinates;
    coordinates=triangle->getCoord();

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
/*
    for (i=vect.begin(); i<vect.end(); ++i)
        cout<<(*i).x<<" "<<(*i).y<<endl;
*/
    return vect;
}

Type Triangle::perimetr(Figure *figure)
{
    SetOfFigures a(figure);
    vector<Type> sides;
    sides=a.getLengthOfVectors(figure);

    Type perim=0;
    vector<Type>::iterator i;

    for (i=sides.begin(); i<sides.end(); ++i)
        perim+=(*i);

    cout<<"Perimetr = "<<perim<<endl;
    return perim;
}

Type Triangle::area(Figure *figure)
{
    SetOfFigures a(figure);
    vector<Type> sides;
    sides=a.getLengthOfVectors(figure);

    Type area=0;

    vector <Coord> vect;
    Type ab;
    vect=buildVectors(figure);

    ab=vect[0].x * vect[1].x + vect[0].y * vect[1].y;
    Type sinA=sin(acos((ab/(sides[0]*sides[1]*PI/180))));

    area=(0.5)*sides[0]*sides[1]*sinA;
    cout<<"Area = "<<area<<endl;

    return area;
}

