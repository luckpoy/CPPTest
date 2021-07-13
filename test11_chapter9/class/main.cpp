#include <iostream>
#include <cstdlib>
using namespace std;

struct student
{
    int id;
    float gpa;
};

template<class T>
class store{
private:
    T item;
    bool flag;

public:
    store();
    T &getitem();
    void putelem(const T &x);
};

template<class T>
store <T>::store():flag(false),item(){}//加上item(),防止编译器警告

template<class T>
T &store <T>::getitem(){
    if(!flag){
        cout<<"error:no item!"<<endl;
        exit(1);
    }
    return item;
}

template<class T>
void store<T>::putelem(const T &x){
    flag=true;
    item=x;
}

int main(int argc, char const *argv[])
{
    store<int>s1,s2;
    s1.putelem(5);
    s2.putelem(-1);
    cout<<s1.getitem()<<" "<<s2.getitem()<<endl;

    student g={100,56};
    store<student>s3;
    s3.putelem(g);
    cout<<"student: "<<s3.getitem().gpa<<endl;

    store<double> d;
    d.getitem();

    return 0;
}

