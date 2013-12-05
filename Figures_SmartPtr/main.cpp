#include <iostream>
#include "affTransformations.h"
#include "setOfFigures.h"

using namespace std;

int main()
{
    vector<SetOfFigures> allFigures;
    // try
    //{
    Triangle *triangle=new Triangle;
    Square *square=new Square;
    Circle *circle=new Circle;

    SetOfFigures a(triangle);
    SetOfFigures b(square);
    SetOfFigures c(circle);


    allFigures.push_back(a);
    allFigures.push_back(b);
    allFigures.push_back(c);
    /* }
     catch(exception &ex)
    {
         cout<<ex.what();
     }
     */
    cout<<"__________TRIANGLE___________"<<endl;
    /*
    a.getCoordinatesOfFigure();
    a.getVectors(triangle);
    a.getLengthOfVectors(triangle);
    a.getPerimetr(triangle);
    a.getArea(triangle);
    */
    cout<<"Relation between perimetr and area = "<<a.getRelation(triangle)<<endl;

    cout<<endl<<endl<<"__________SQUARE___________"<<endl;
    /*b.getCoordinatesOfFigure();
    b.getVectors(square);
    b.getLengthOfVectors(square);
    b.getPerimetr(square);
    b.getArea(square);
    */
    cout<<"Relation between perimetr and area = "<<b.getRelation(square)<<endl;

    cout<<endl<<endl<<"__________CIRCLE___________"<<endl;
    /*
    c.getCoordinatesOfFigure();
    c.getPerimetr(square);
    c.getArea(square);
    */
    cout<<"Relation between perimetr and area = "<<c.getRelation(square)<<endl;

    return 0;
}
