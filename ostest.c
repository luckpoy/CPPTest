#include <stdio.h>

int main(int argc, char const *argv[])
{
    if(!fork()){
        while (1)
        {
            printf("A");
        }
    }
    if(!fork()){
        while (1)
        {
            printf("B");
        }
    }
    wait();
    return 0;
}
