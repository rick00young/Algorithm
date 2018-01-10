#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "../search/header.h"
/**
 * 冒泡需要比较n(n-1)/2,排序复杂度为O(n^2)
 */

void bubble_sort_0(SqList *L);
void bubble_sort(SqList *L);
void bubble_sort_2(SqList *L);
// void bubble_print(SqList *L);

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

    // bubble_sort_0(L);
    // bubble_sort(L);
    bubble_sort_2(L);
    printf("---sorted data----\n");
    sqlist_print(L);
    return 0;
}



void bubble_sort_0(SqList *L){
	int i, j;
	for(i = 1; i < L->length; i++){
		for(j = i + 1; j < L->length; j++){
			if(L->r[i] > L->r[j]){
				swap(L, i, j);
			}
		}
	}
}
/**
 * 这才是真正的冒泡算法
 * @param L [description]
 */
void bubble_sort(SqList *L){
	int i, j;
	for(i = 1; i < L->length; i++){
		for(j = L->length - 1; j >= i; j--){
			if(L->r[j] > L->r[j+1]){
				swap(L, j, j+1);
			}
		}
	}
}


/**
 * 冒泡算法优化
 * @param L [description]
 */
void bubble_sort_2(SqList *L){
	int i, j;
	Status flag = TRUE;
	for(i = 1; i < L->length && flag; i++){
		flag = FALSE;
		for(j = L->length - 1;j >= i; j--){
			if(L->r[j] > L->r[j+1]){
				swap(L, j, j+1);
				flag = TRUE;
			}
		}
	}
}









