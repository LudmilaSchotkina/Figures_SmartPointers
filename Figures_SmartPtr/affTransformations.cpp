#include "affTransformations.h"
#include "setOfFigures.h"

vector<Coord> Figure::getCoordinates()
{
    return getCoord();
}

vector<Coord> Figure::buildFigure(Figure *figure)
{
    return buildVectors(figure);
}

vector<Type> Figure::length(Figure *a, bool upd)
{
    vector<Coord> vect;
    vect=updLength(a, upd);

    vector <Type> sides;
    vector<Coord>::iterator i;

    for (i= vect.begin(); i< vect.end(); ++i)
        sides.push_back(sqrt(((*i).x)*((*i).x)+((*i).y)*((*i).y)));

    return sides;
}

Type **Figure::getVector(Figure *a)
{
    vector <Coord> temp=buildVectors(a);
    int size=temp.size();

    vector <Coord> vect, vectChanged;
    vect=buildVectors(a);

    Type **matrixVectors;
    matrixVectors=new Type *[size];
    for (int i=0; i<2; i++)
    {
        matrixVectors[i]=new Type[size];
        for (int j=0; j<size; j++)
            matrixVectors[i][j]=0.0;
    }

    int w=0;
    vector<Coord>::iterator i;
    for (i=vect.begin(); i<vect.end(); ++i)
    {
        matrixVectors[0][w]=(*i).x;
        matrixVectors[1][w]=(*i).y;
        ++w;
    }

    return matrixVectors;

}

Type **Figure::affTransf()
{
    Type **matrixA=new Type *[2];
    for (int l=0; l<2; l++)
    {
        matrixA[l]=new Type[2];
        for (int k=0; k<2; k++) //задаем матрицу аффинного преобразования например:
        {
            matrixA[l][k]=0.0;     //1 0
            matrixA[l][l]=l+1.0;   //0 2
        }
    }
    return matrixA;
}

vector<Coord> Figure::changeSize(Figure *a)
{
    Type **matrixVectors=getVector(a);
    Type **matrixA=affTransf();

    vector <Coord> temp=buildVectors(a);
    int size=temp.size();

    Type **changedMatrix=new Type *[size];
    for (int i=0; i<2; i++)
    {
        changedMatrix[i]=new Type[size];
        for (int j=0; j<size; j++)
            changedMatrix[i][j]=0.0;
    }

    for(int i=0; i<2; ++i)
    {
        for(int j=0; j<size; ++j)
        {
            for(int p=0; p<2; ++p)
                changedMatrix[i][j]+=matrixA[i][p] * matrixVectors[i][j];
        }
    }

    vector <Coord> vect;
    Coord value;

    for(int j=0; j<size; ++j)
    {
        value.x=changedMatrix[0][j];
        value.y=changedMatrix[1][j];
        vect.push_back(value);
    }

    for (int i=0; i<2; i++)
        delete [] changedMatrix[i];
    delete [] changedMatrix;

    return vect;
}

vector<Coord> Figure::updLength(Figure *a, bool update)
{
    vector <Coord> vect;

    if(update)
        vect=changeSize(a);
    else
        vect=buildVectors(a);

    return vect;

}

Type Figure::getP(Figure *square, bool update)
{
    return perimetr(square,  update);
}
Type Figure::getA(Figure *square, bool update)
{
    return  area(square,  update);
}
