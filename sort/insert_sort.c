#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "../search/header.h"

/**
 * 插入排序需要比较(n+2)(n-1)/2,复杂度为O(n^2),但它交换数据的次数要比冒泡排序少
 * @param L [description]
 */
void insert_sort(SqList *L);

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
    insert_sort(L);
    printf("---sorted data----\n");
    sqlist_print(L);
    return 0;
}

/**
 * 插入排序的基本操作是将一个记录插入到已经排好序的有序列表中,
 * 从而得到一个新的,记录数为1的有序表
 * @param L [description]
 */
void insert_sort(SqList *L){
    int i, j;
    for(i = 2; i <= L->length; i++){
        //需要将L->r[i]插入有序表
        if(L->r[i] < L->r[i-1]){
            //设置哨兵
            L->r[0] = L->r[i];
            for(j = i - 1; L->r[j] > L->r[0]; j--){
                //记录后移
                L->r[j+1] = L->r[j];
            }
            //插入到正确的位置
            L->r[j+1] = L->r[0];
        }
    }
}