#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <sys/time.h>

/**
 * 合并两个循环列表
 * a,b两都有头指针和尾指针
 */
void merge_link(LinkList rear_a, LinkList rear_b){
    LinkList p;
    //将a表头指针赋值p
    p = rear_a->next;
    //将b表的第一个结点(不是头指针)
    //赋值给rear_a->next赋值rear_a->next
    rear_a->next = rear_b->next->next;
    //将原a表的头指针赋值给rear_b->next
    rear_b->next = p;
    // free(p);
    // b表的头指针无用,可以释放了
    free(rear_b->next);
}

int main( int argc, char *argv[] ) /* 带参数形式 */
{

    return 0;
}