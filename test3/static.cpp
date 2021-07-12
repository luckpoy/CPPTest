#include <iostream>
using namespace std;

void fun(){
    static int a=5;
    int b=6;
    return;
}

int main(){
    int a=3;
	cout<<a<<endl;
	return 0;
}
