#include "object.h"
#include <iostream>
using namespace std;

object::object(int a,char * b)
{
    age=a;
    sex=b;
}

object::~object()
{
}

void object::print(){
    cout<<"I`m "<<age<<endl;
    cout<< "I`m a "<<sex<<endl;
}
