#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "../search/header.h"

/**
 * 增量的限值为: dlta[k] = 2^(t-k+1) - 1 st (0 <= k <= t <= [log2(n+1)])
 * 复杂度为O(n^3/2),并不是一种循名抱稳定算法
 * @param L [description]
 */
void shell_sort(SqList *L);

int main( int argc, char *argv[] ) /* 带参数形式 */
{
    SqList *L = (SqList *)malloc(sizeof(SqList));
    int a[] = {9,1,5,8,3,7,4,6,2};
    L->length = 9;
    for(int i = 0; i < L->length; i++){
    	L->r[i+1] = a[i];
    }
    printf("---origin data----\n");
    sqlist_print(L);
    shell_sort(L);
    printf("---sorted data----\n");
    sqlist_print(L);
    return 0;
}

/**
 * 将原本有大量记录数的记录进行分组.分割成若干个子序列,
 * 然后对这些子序列进行内进行直接插入排序.当整个序列基本有序时,
 * 再对整体记录进行一次直接插入排序.
 * @param L [description]
 */
void shell_sort(SqList *L){
    int i, j;
    int increment = L->length;
    do{
        //增量序列
        increment = increment/3 + 1;
        for(i = increment + 1; i <= L->length; i++){
            if(L->r[i] < L->r[i - increment]){
                //需将L->r[i]插入到时有序增量子表
                L->r[0] = L->r[i];//暂存在L->r[0]
                for(j = i - increment;
                    j > 0 && L->r[0] < L->r[j];
                    j-=increment){

                    //记录后移,查找插入位置
                    L->r[j+increment] = L->r[j];
                }
                L->r[j + increment] = L->r[0];
            }
        }
    }while(increment > 1);
}













