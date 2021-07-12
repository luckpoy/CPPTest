#include <iostream>
using namespace std;
double multiplier(double a , double b);

int main(){
    double x;
    double a,b;
    cin>>a>>b;
    x = multiplier(a,b);
	cout<<a<<"x"<<b<<"="<<x<<endl;
	return 0;
}

double multiplier(double a , double b){
    return a*b;
}