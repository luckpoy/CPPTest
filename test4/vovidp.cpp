#include <iostream>
using namespace std;

int	main(int argc, char **argv)
{
    void * pv;
    int i=5;
    pv = & i;
    int * print = static_cast<int *>(pv);
    cout<< "* print = "<<*print<<endl;
    return 0;
}
