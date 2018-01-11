#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <sys/time.h>


int fbi(int i){
    if(i<2){
        return i == 0 ? 0: 1;
    }
    return fbi(i-1) + fbi(i-1);
}

int main( int argc, char *argv[] ) /* 带参数形式 */
{
    int i;
    for (int i = 0; i < 10; ++i)
    {
        /* code */
        printf("%d\n", fbi(i));
    }
    return 0;
}






