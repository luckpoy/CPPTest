#include <iostream>
using namespace std;
int * fun(){
	int e[]={1,2,3};
	int *a =e;
	return a;
}
int main(){
	cout<<*fun()<< *(fun()+1)<<endl;;
	return 0;
}
