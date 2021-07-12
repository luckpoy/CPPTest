#include <iostream>
using namespace std;

int	main(int argc, char **argv)
{
    float (*p)[2][3]=new float[2][2][3];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                *(*(*(p+i)+j)+k)=static_cast<float>(i*100+j*10+k);
            }
        }
        
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cout<<p[i][j][k]<<" ";
            }
        }
        cout<<endl;

    }
    
    
    delete[] p;
    return 0;
}
