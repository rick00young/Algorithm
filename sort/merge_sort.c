#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "../search/header.h"

/**
 *
 * 复杂度为O(n+logn)
 * @param L [description]
 * merge sort不存在跳跃,是稳定的排序,但比较占用内存
 */
void merge_sort(SqList *L);
void m_sort(int SR[], int TR1[], int s, int t);
void merge(int SR[], int TR[], int i, int m, int n);
void merge_sort2(SqList *L);
void merge_pass(int SR[], int TR[], int s, int n);

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
    // merge_sort(L);
    printf("---sorted data----\n");
    sqlist_print(L);
    return 0;
}

/**
 * 归并排序的原理是假设初始序列含有n个记录,则可以看成是n个记录的子序列,
 * 每个子序列的长度为1,然后两两归并,得到[n/2]([x]表示不小于最小整数)个
 * 长度为2或1的有序子序列,再两两归并,如此重复,直至得到一个长度为n的有序序列为
 * 止.称为2路归并排序.
 * @param L [description]
 */
void merge_sort(SqList *L){
    m_sort(L->r, L->r, 1, L->length);
}

void m_sort(int SR[], int TR1[], int s, int t){
    int m;
    int TR2[MAXSIZE + 1];
    if(s == t){
        TR1[s] = SR[s];
    }else{
        m = (s+t)/2;//将SR[s..t]平分为SR[s..m]和SR[m+1..t]
        m_sort(SR, TR2, s, m);//递归将SR[s..m]归并为有序的TR2[s..m]
        m_sort(SR, TR2, m+1, t);//递归将SR[m+1..t]归并为有序的TR2[m+1..t]
        merge(TR2, TR1, s, m, t);//将TR2[s..m]和TR2[m+1..t]归并到物[s..t]
    }
}


void merge(int SR[], int TR[], int i, int m, int n){
    int j, k, l;
    for(j=m+1, k=i; i<=m && j<=n; k++){//将SR中记录由小到大归并入TR
        if(SR[i]<SR[j]){
            TR[k] = SR[i++];
        }else{
            TR[k] = SR[j++];
        }
    }
    if(i<=m){
        for(l=0; l <= m-i; l++){
            TR[k+l] = SR[i+l];//将剩余的SR[i..m]复制到TR
        }
    }
    if(j<=n){
        for(l=0; l<=n-j; l++){
            TR[k+l] = SR[j+l];//将剩余的SR[j..n]复制到TR
        }
    }
}

/**
 * 非递归实现归并排序
 * @param L [description]
 */
void merge_sort2(SqList *L){
    //申请额外空间
    int *TR = (int *)malloc(L->length*sizeof(int));
    int k = 1;
    while(k < L->length){
        //k=1,将原来无序数组两两归并入TR
        merge_pass(L->r, TR, k, L->length);
        // k的变化是1-2-4-8-16
        k = 2*k;
        //将TR中已经两两归并的有序序列再次归并回数组L->r
        merge_pass(TR, L->r, k, L->length);
        k = 2*k;
    }
}

void merge_pass(int SR[], int TR[], int s, int n){
    int i = 1;
    int j;
    //进行两两归并, i为1到8,最终第9条记录会剩下来,无法归并
    while(i < n - 2*s +1){
        merge(SR, TR, i, i+s-1, i+2*s-1);
        i=i+2*s;
    }
    if(i < n-s+1){//归并最后两个序列
        merge(SR, TR, i, i+s-1, n);
    }else{
        for(j = i; j <= n; j++){
            TR[j] = SR[j];
        }
    }
}










