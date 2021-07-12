#include <iostream>
#include <typeinfo>
using namespace std;

class base
{
public:
    virtual ~base(){}
};

class derived : public base {};

void fun(base *b){
    const type_info &info1=typeid(b);
    const type_info &info2=typeid(*b);

    cout<<info1.name()<<endl;
    cout<<info2.name()<<endl;

    if (info2==typeid(base))
    {
        cout<<"a base class!"<<endl;
    }
}

int main(int argc, char const *argv[])
{
    base b;
    fun(&b);
    derived d;
    fun(&d);
    return 0;
}
