#ifndef SMARTPTR_H
#define SMARTPTR_H

template <typename Name>
class SmartPtr
{
public:
    SmartPtr(Name *ptr=0);
    ~SmartPtr();

    SmartPtr(const SmartPtr &orig);
    SmartPtr &operator=(const SmartPtr &orig);

    Name &operator*();
    Name *operator->();
    int getCounter();
    void deletePtr();

private:
    Name *pointer;
    int *counter;
};

//////////////////////////////////////////////////////
template <typename Name>
SmartPtr<Name>::SmartPtr(Name *ptr):
    pointer(ptr)
{
    counter=new int;
    if(ptr) *counter=1;
    else *counter=0;
}

template <typename Name>
SmartPtr<Name>::~SmartPtr()
{
    deletePtr();
}

template <typename Name>
SmartPtr<Name>::SmartPtr(const SmartPtr<Name> &orig)
{
    pointer=orig.pointer;
    counter=orig.counter;
    (*counter)++;
}

template <typename Name>
SmartPtr<Name> &SmartPtr<Name>::operator= (const SmartPtr<Name> &orig)
{
    if(&orig != this)
    {
        deletePtr();
        pointer = orig.pointer;
        counter = orig.counter;
        (*counter)++;
    }
    return *this;
}

//////////////////////////////////////////////////////////////////
template <typename Name>
Name& SmartPtr<Name>::operator*()
{
    return *pointer;
}

template <typename Name>
Name* SmartPtr<Name>::operator->()
{
    return pointer;
}

template <typename Name>
int SmartPtr<Name>::getCounter()
{
    return *counter;
}

template<typename Name>
void SmartPtr<Name>::deletePtr()
{
    if(!(--(*counter)))
    {
        delete counter;
        counter=0;
        if(pointer)
        {
            delete pointer;
            pointer=0;
        }
    }
}
#endif // SMARTPTR_H
