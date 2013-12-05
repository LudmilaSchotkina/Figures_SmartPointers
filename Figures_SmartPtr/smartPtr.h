#ifndef SMARTPTR_H
#define SMARTPTR_H


template <typename Name>
class SmartPtr
{
public:
    typedef Name *Ptr;
    typedef Name &Ref;

    SmartPtr (Ptr p):
        ptr(p)
    {}

    ~SmartPtr()
    {
        delete ptr;
    }
    Ref operator*()const;
    Ptr operator->()const;
    void reset (Ptr ptr);

private:
    Ptr ptr;

};


#endif // SMARTPTR_H
