#include <iostream>
using namespace std;
// int * fun(){
// 	int e[]={1,2,3};
// 	//int *a =e;
// 	return e;
// }
// int main(){
// 	cout<<*fun()<< *(fun()+1)<<endl;;
// 	return 0;
// }
int main(int argc, char const *argv[])
{
    int a[2][2]={{1,2},{3,4}};
    cout<<a[0][0]<<endl;
    cout<<a[0][1]<<endl;
    cout<<a[1][0]<<endl;
    cout<<a[1][1]<<endl;

    cout<<*(*(a)+2)<<endl;
    return 0;
}

