#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "../search/header.h"

/**
 *
 * 复杂度为O(nlogn)
 * @param L [description]
 * quick sort也是一种不稳定的排序,不适合数据较少的排序
 */
void quick_sort(SqList *L);
void q_sort(SqList *l, int low, int high);
int partition(SqList *L, int low, int high);

int main( int argc, char *argv[] ) /* 带参数形式 */
{
    SqList *L = (SqList *)malloc(sizeof(SqList));
    int a[] = {50,10,90,30,70,40,80,60,20};
    L->length = 9;
    for(int i = 0; i < L->length; i++){
    	L->r[i+1] = a[i];
    }
    printf("---origin data----\n");
    sqlist_print(L);
    quick_sort(L);
    printf("---sorted data----\n");
    sqlist_print(L);
    return 0;
}

/**
 * 快速排序的基本思想: 通过一趟排序将待排记录分割成独立的两部分,
 * 其中一部分记录的关键字均比另一部分的关键字小,则可分别对
 * 这两部分记录继续进行排序,以达到整个序列有序的目的.
 * @param L [description]
 * 已知L->r[s..m]中记录的关键字除L->r[s]之外均满足堆的定义
 * 调整L->r[s]的关键字,使L->r[s..m]成为一个大顶堆
 */
void quick_sort(SqList *L){
    q_sort(L, 1, L->length);
}
/**
 * 对顺序表L中的子序列L->r[low..high]作快速排序
 * @param l    [description]
 * @param low  [description]
 * @param high [description]
 */
void q_sort(SqList *L, int low, int high){
    int pivot;
    //可以在这里设阀值,大于某个数据则用快速排序,否则用简单排序,数据
    //一般是7或是50.
    /*
    if((high-low) > max_length_inser_sort){
        ....
    }else{
        ...
    }
    */
    if(low < high){
        //将L->r[loww..high]一分为二,算出枢轴值pivot
        pivot = partition(L, low, high);
        //对低子表递归排序
        q_sort(L, low, pivot -1);
        //对高子表递归排序
        q_sort(L, pivot +1, high);
    }
}

/**
 * 交换顺序表L中子表的记录,使枢轴记录到位,并返回出所在位置
 * 此时在它之前(之后)的记录均不大于(小于)它
 * @param  L    [description]
 * @param  low  [description]
 * @param  high [description]
 * @return      [description]
 */
int partition(SqList *L, int low, int high){
    int pivotkey;
    pivotkey = L->r[low];
    while(low < high){
        while(low < high && L->r[high] >= pivotkey)
            high--;
        //将比枢轴记录小的记录交换到低端
        swap(L, low, high);

        while(low < high && L->r[low] <= pivotkey)
            low++;
        //将比枢轴记录大的记录交换到高端
        swap(L, low, high);
    }
    return low;
}








