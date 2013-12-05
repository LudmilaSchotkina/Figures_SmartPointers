#include "affTransformations.h"
#include "setOfFigures.h"


vector<Coord> Square::getCoord()
{
    Coord value;
    vector <Coord> coordinates;

    fstream fileSquare;
    fileSquare.open("square.txt");

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


vector<Coord> Square::buildVectors (Figure *figure)
{
    Square *square = (Square*)figure;
    vector <Coord> coordinates;
    coordinates=square->getCoord();

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

Type Square::perimetr(Figure *figure)
{
     SetOfFigures a(figure);
   // Square *square = (Square *)figure;
    vector<Type> sides;
    sides=a.getLengthOfVectors(figure);

    Type perim=0;
    vector<Type>::iterator i;

    for (i=sides.begin(); i<sides.end(); ++i)
        perim+=(*i);

    cout<<"Perimetr = "<<perim<<endl;
    return perim;
}

Type Square::area(Figure *figure)
{
    SetOfFigures obj(figure);
    vector<Type> sides;
    sides=obj.getLengthOfVectors(figure);

    Type a=0;
    vector<Type>::iterator i;

    for (i=sides.begin(); i<sides.end(); ++i)
        a=(*i)*(*i);

    cout<<"Area = "<<a<<endl;
    return a;
}

