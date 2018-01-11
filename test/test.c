#include <stdio.h>
#include <stdlib.h>
#include "../search/header.h"
/**
 * 冒泡需要比较n(n-1)/2,排序复杂度为O(n^2)
 */


int main( int argc, char *argv[] ) /* 带参数形式 */
{
    int a[4] = {1,2,3,4};
    for (int i = 0; i < 4; ++i)
    {
        printf("%d\n", a[i]);
    }
    a[3] = 8;
    int j = -1;
    printf("---%d\n", a[j]);
    return 0;
}
