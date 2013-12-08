#ifndef AFFTRANSFORMATIONS_H
#define AFFTRANSFORMATIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <exception>

using namespace std;

#define PI 3.14159265
typedef double Type;


class FigureException: public exception
{
    const char *what() const throw()
    {
        return "Wrong input data";
    }
};

struct Coord
{
    Type x;
    Type y;
};

class Figure
{
public:

    vector<Coord> getCoordinates();
    vector<Coord> buildFigure(Figure *a);

    vector<Type> length(Figure *a, bool upd);
    vector<Coord> updLength(Figure *a, bool upd);

    Type getP(Figure *a, bool update); //get perimetr
    Type getA(Figure *a, bool update); //get area
    vector<Coord> changeSize(Figure *a);

    Type **getVector(Figure *a);
    Type **affTransf();

private:
    virtual vector<Coord> getCoord() = 0;
    virtual vector<Coord> buildVectors(Figure *a) = 0;

    virtual Type perimetr(Figure *figure, bool update) = 0;
    virtual Type area(Figure *figure, bool update) = 0;

};

///////////////////////////////////////////////

class Triangle: public Figure
{
    vector<Coord> getCoord();
    vector<Coord> buildVectors(Figure *figure);

    Type perimetr(Figure *figure, bool update);
    Type area(Figure *figure, bool update);
};

//////////////////////////////////////////////

class Square: public Figure
{
    vector<Coord> getCoord();
    vector<Coord> buildVectors(Figure *figure);

    Type perimetr(Figure *figure, bool update);
    Type area(Figure *figure, bool update);
};

////////////////////////////////////////////

class Circle: public Figure
{
    vector<Coord> getCoord();
    vector<Coord> buildVectors(Figure *figure);

    Type perimetr(Figure *figure, bool update);
    Type area(Figure *figure, bool update);

};


#endif
