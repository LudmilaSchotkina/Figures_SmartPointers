#include <iostream>
#include "affTransformations.h"
#include "setOfFigures.h"
#include "smartPtr.h"

using namespace std;

int main()
{
    vector<SmartPtr<SetOfFigures> > allFigures;

    Triangle *triangle=new Triangle;
    Square *square=new Square;
    Circle *circle=new Circle;

        SmartPtr<SetOfFigures> a=new SetOfFigures(triangle);
        SmartPtr<SetOfFigures> b=new SetOfFigures(square);
        SmartPtr<SetOfFigures> c=new SetOfFigures(circle);


    allFigures.push_back(a);
    allFigures.push_back(b);
    allFigures.push_back(c);


    try
    {
    cout<<"__________TRIANGLE___________"<<endl;
    cout<<"Perimetr = "<<a->getPerimetr(triangle,0)<<endl;
    cout<<"Area = "<<a->getArea(triangle,0)<<endl;
    cout<<"Relation between perimetr and area = "<<a->getRelation(triangle,0)<<endl;
}
    catch(exception &ex)
    {
        cout<<ex.what();
    }
    cout<<endl<<endl<<"__________SQUARE___________"<<endl;
    cout<<"Perimetr = "<<b->getPerimetr(square,0)<<endl;
    cout<<"Area = "<<b->getArea(square,0)<<endl;
    cout<<"Relation between perimetr and area = "<<b->getRelation(square,0)<<endl;

    cout<<endl<<endl<<"__________CIRCLE___________"<<endl;
    cout<<"Perimetr = "<<c->getPerimetr(circle,0)<<endl;
    cout<<"Area = "<<c->getArea(circle,0)<<endl;
    cout<<"Relation between perimetr and area = "<<c->getRelation(circle,0)<<endl;

    //////////////////////////////////////////////////////////////////////////
    cout<<endl<<endl<<endl<<"---------------AFTER TRANSFORMATIONS--------------"<<endl<<endl;
    cout<<"__________TRIANGLE___________"<<endl;
    cout<<"Perimetr = "<<a->getPerimetr(triangle,1)<<endl;
    cout<<"Area = "<<a->getArea(triangle,1)<<endl;
    cout<<"Relation between perimetr and area = "<<a->getRelation(triangle,1)<<endl;

    cout<<endl<<endl<<"__________SQUARE___________"<<endl;
    cout<<"Perimetr = "<<b->getPerimetr(square,1)<<endl;
    cout<<"Area = "<<b->getArea(square,1)<<endl;
    cout<<"Relation between perimetr and area = "<<b->getRelation(square,1)<<endl;

    cout<<endl<<endl<<"__________CIRCLE___________"<<endl;
    cout<<"Perimetr = "<<c->getPerimetr(circle,1)<<endl;
    cout<<"Area = "<<c->getArea(circle,1)<<endl;
    cout<<"Relation between perimetr and area = "<<c->getRelation(circle,1)<<endl;


    delete triangle;
    triangle=0;
    delete square;
    square=0;
    delete circle;
    circle=0;

    return 0;
}
