#include <iostream>
using namespace std;

class base1
{
private:
public:
    virtual void display() const=0;
};

class base2:public base1
{
private:
public:
    virtual void display() const;
};

void base2::display() const{
    cout<<"base2::display"<<endl;
}

class derived:public base2
{
private:
public:
    virtual void display() const;
};

void derived::display() const{
    cout<<"derived::display"<<endl;
}

void fun(base1 * p){
    p->display();
}

int main(int argc, char const *argv[]){
    base2 b2;
    derived d;
    fun(&b2);
    fun(&d);
    return 0;
}
