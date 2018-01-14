#include <stdio.h>
#include <stdlib.h>
#include "header.h"
/*
散列
    散列技术是在记录的存储位置和它的关键字之间建立一个确定的对应
    关系f,使得每个关键字key对应一个存储位置f(key)


散列函数构造方法:
    1.直接选址
    2.数字分析法
        适合提前获知关键字分布均匀
    3.平方取中法
        适合不知道关键字分布,而位数又不是很大的情况.
    4.折叠法
        将关键字从左到右分割成位数相等的几部分(最后一部分不够可以短些)
        然后将这几部分叠加求和,并按散列表表长,取后几位作为散列地址;
        折叠法事先不需要知道关键字的分布,适合关键字位数较多的情况
    5.除留余数法
        f(key)=key mod p;(p<=m);
        p通常为小于或等于表长或接近m的最小质数;
    6.随机数法
        选取一个随机数,取关键字的随机函数值为它的散列地址.

散列冲突:
    1.开放地址
        线性探测:反复去寻找可用的地址,称为线性探测;容易出现堆积;
            如: addr = f(f(key) + 1)
        二次探测:fi(key) = (f(key) + di) mod m (di=1^2, -1^2, 2^2,-2^2,...q^2, -q^2, q<=m/2)
            增加平方的运算是为了不让关键字都聚集在某一区域,称为二次探测.

    2.再散列函数
        多个散列函数
    3.链地址法
    4.公共溢出区法
        为所有冲突的关键字建立一个公共溢出区来存放

 */

int m = 0;

Status init_HashTable(HashTable *H){
    int i;
    m = HASHSIZE;
    H->count = m;
    H->elem = (int *)malloc(m*sizeof(int));
    for (i = 0; i < m; i++)
    {
        H->elem[i] = NULLKEY;
    }
    return OK;
}

int hash(int key){
    return key % m;
}

void insert_hash(HashTable *H, int key){
    int addr = hash(key);
    while(H->elem[addr] != NULLKEY){
        addr = (addr+1) % m;
    }
    H->elem[addr] = key;
}

Status search_hash(HashTable H, int key, int *addr){
    *addr = hash(key);
    while(H.elem[*addr] != key){
        *addr = (*addr+1)%m;
        if(H.elem[*addr] == NULLKEY || *addr == hash(key)){
            return UNSUCCESS;
        }
    }
    return SUCCESS;
}


int main( int argc, char *argv[] ) /* 带参数形式 */
{

    return 0;
}