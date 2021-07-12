#include <iostream>
using namespace std;

class complex{
    public:
    complex(double r=0.0,double i=0.0):real(r),imag(i){}
    void display() const;
    complex operator+(const complex &a)const;
    private:
    double real;
    double imag;
};

complex complex::operator+(const complex & a)const{
    return complex(real+a.real,imag + a.imag);
}

void complex::display()const{
    cout<<real<<"+"<<imag<<"i"<<endl;
}

int main(int argc, char const *argv[])
{
    complex c1(5,6),c2(1,3.2),c3;
    cout<<"c1: "; c1.display();
    cout<<"c2: "; c2.display();
    cout<<"c3: "; c3.display();

    c3=c1+c2;
    cout<<"c3: "; c3.display();

    c3=c1+c2+c1;
    cout<<"c3: "; c3.display();

    return 0;
}
