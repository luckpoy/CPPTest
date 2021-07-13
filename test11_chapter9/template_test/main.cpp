#include <iostream>
using namespace std;

template<typename T>
T abs(T x){
    return x<0 ? -x:x;
}

int main(int argc, char const *argv[])
{
    cout<<abs(-5)<<endl;
    cout<<abs(-8.3)<<endl;
    return 0;
}
