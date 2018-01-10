#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "../search/header.h"

/**
 *
 * 复杂度为O(nlogn)
 * @param L [description]
 * heap sort也是一种不稳定的排序,不适合数据较少的排序
 */
void heap_sort(SqList *L);
void heap_adjust(SqList *L, int s, int m);

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
    heap_sort(L);
    printf("---sorted data----\n");
    sqlist_print(L);
    return 0;
}

/**
 * 堆排序的思想是,将待排序的序列构造成一个大顶堆,此时整个序列的
 * 最大值就是堆顶的根结点.将它移走(就是将其与数组末尾元素交换,此时
 * 末尾元素就是最大值),然后将剩余的n-1个序列重新构造成一个堆,这样
 * 就会得到n个元素中的次小值,反复执行,便能有一个有序序列了.
 * @param L [description]
 * @param s [description]
 * @param m [description]
 * 已知L->r[s..m]中记录的关键字除L->r[s]之外均满足堆的定义
 * 调整L->r[s]的关键字,使L->r[s..m]成为一个大顶堆
 */
void heap_adjust(SqList *L, int s, int m){
    int temp, j;
    temp = L->r[s];
    //沿关键字较大的孩子结点向下筛选
    //完全二叉树当前结点号是s,其左孩子的序号一定是2s,右孩子一定是2s+1
    for (j = 2*s; j <= m; j *= 2){
        if(j < m && L->r[j] < L->r[j+1])
            ++j;//j为关键字中较大的记录下标
        if(temp >= L->r[j])
            break;//rc应插入在位置s上
        L->r[s] = L->r[j];
        s = j;
    }
    L->r[s] = temp;
}


void heap_sort(SqList *L){
    int i;
    for(i = L->length/2; i > 0; i--){
        //把L中的r构建成一个大项堆
        heap_adjust(L, i, L->length);
    }

    for(i = L->length; i > 1; i--){
        //将堆顶记录和当前未经排序子序列的最后一个记录交换
        swap(L, 1, i);
        //将L->r[1..i-1]重新调整为大顶堆
        heap_adjust(L, 1, i - 1);
    }
}













