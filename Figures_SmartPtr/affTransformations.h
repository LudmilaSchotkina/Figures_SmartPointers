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
        return "error";
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
    vector<Type> length(Figure *a);

    Type getP(Figure *a);
    Type getA(Figure *a);

private:
    vector<Figure> setOfFigures;

    virtual vector<Coord> getCoord() = 0;
    virtual vector<Coord> buildVectors(Figure *a) = 0;


    virtual Type perimetr(Figure *figure) = 0;
    virtual Type area(Figure *figure) = 0;


};

///////////////////////////////////////////////

class Triangle: public Figure
{
public:
    // Square();
    // ~Square();
    //Type getP();
    //Type getA();



    vector<Coord> getCoord();
    vector<Coord> buildVectors(Figure *figure);
    //vector <Type> lengthOfVectors(Figure *a);

    Type perimetr(Figure *figure);
    Type area(Figure *figure);

private:
    Type perim, areaOfFigure;
};

//////////////////////////////////////////////

class Square: public Figure
{
public:

    vector<Coord> getCoord();
    vector<Coord> buildVectors(Figure *figure);

    Type perimetr(Figure *figure);
    Type area(Figure *figure);

private:
    Type perim, areaOfFigure;
};

class Circle: public Figure
{
public:

    vector<Coord> getCoord();
    Coord getCenter();
    Type getRadius();

    vector<Coord> buildVectors(Figure *figure);

    Type perimetr(Figure *figure);
    Type area(Figure *figure);

private:
    Type perim, areaOfFigure;
};


#endif
