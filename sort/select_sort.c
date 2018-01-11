#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "../search/header.h"

/**
 * 选择排序需要比较n(n-1)/2,复杂度为O(n^2),
 * 但它交换数据的次数要比冒泡排序少
 * @param L [description]
 */
void select_sort(SqList *L);

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
    select_sort(L);
    printf("---sorted data----\n");
    sqlist_print(L);
    return 0;
}

/**
 * 简单选择排序就是通过n-1次关键字间的比较,
 * 从n-i+1个记录中选出关键字最小的记录,并和i(1<=i<=n)个记录交换之.
 * @param L [description]
 */
void select_sort(SqList *L){
	int i, j, min;
	for(i = 1; i < L->length; i++){
		//将当前下标定义为最小值下标
		min = i;
		for(j = i+1; j <= L->length; j++){
			if(L->r[min] > L->r[j]){
				min = j;
			}
		}
		if(i != min){
			swap(L, i, min);
		}
	}
}