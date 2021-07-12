#include <iostream>
using namespace std;

class A
{
private:
    int a;
protected:
    int b;
public:
    int c;
};

class B:public A{
    public:
    int d;
    void fun1();
    void print();
    protected:
    int e;
    private:
    int f;
};

class C:public B{
    public:
    void print();
};

void B::fun1(){
    this->f=111;
    this->b=222;
    this->e=123;
}
void B::print(){
    std::cout << this->f<<" "<<this->b<<" "<<this->e << std::endl;
}
void C::print(){
    this->e=0;
    std::cout << this->b<<" "<<this->c<<" "<<this->d <<" "<<this->e << std::endl;
}

int main(int argc, char const *argv[])
{
    B *b;
    b = new B;
    C *c = new C;
    b->fun1();
    b->print();
    cout<< b->c<<endl;
    c->print();
    delete b,c;
    return 0;
}
