#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <sys/time.h>


/**
 * 单链表结构与顺序结构存储结构的优缺点
 * 存储分配方式:
 *     1.顺序存储结构用一段连续的存储单元依次存储线性表的数据元素
 *     2.单链表采用链式存储结构,用一组任意的存储单元存放线性表的元素
 *
 * 时间性能:
 *     查找:
 *         1.顺序存储结构O(1)
 *         2.单链表O(n)
 *
 *      插入与删除:
 *          1.顺序存储结构需要平均移动表长一半的元素,时间为O(n)
 *          2.单链表在线出某位置的指针后,插入与删除时间仅为O(1)
 *
 * 空间性能:
 *     1.顺序存储结构需要预分配存储空间,分大了浪费,小了上溢
 *     2.单链表不需要分配存储空间,只要有就可以分配,元素个数也不受限制.
 */


/**
 * 初始条件: 顺序线性表L已存在,1<=i<=ListLength(L)
 * 时间复杂度为O(n)
 * @param  L [description]
 * @param  i [description]
 * @param  e [description]
 * @return   [description]
 */
Status get_elem(LinkList L, int i, ElemType *e){
    int j;
    LinkList p;
    p = L->next;
    j = 1;
    while(p && j < i){
        p = p->next;
        ++j;
    }
    if(!p || j>i){
        //第i个元素不存在
        return ERROR;
    }
    *e = p->data;
    return OK;
}


Status list_insert(LinkList *L, int i, ElemType e){
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while(p && j < i){
        p = p->next;
        ++j;
    }
    if(!p || j>i){
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    printf("j is: %d; insert value is: %d\n", j, e);
    //将p的后继结点赋值给s的后继
    //一定不能反
    s->next = p->next;
    //将s赋值给p的后继
    p->next = s;
    return OK;
}


Status list_delete(LinkList *L, int i, ElemType *e){
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while(p->next && j<i){
        p = p->next;
        ++j;
    }
    if(!(p->next) || j>i){
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

void create_list_head(LinkList *L, int n){
    LinkList p;
    int i;
    // srand(time(0));
    srand(1);
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    for(i = 0; i < n; i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100 + 1;
        //头插法,始终让新结点在每一位置
        p->next = (*L)->next;
        (*L)->next = p;
    }

}

void create_list_tail(LinkList *L, int n){
    LinkList p, r;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r = *L;
    for (i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = rand()%100+1;
        //将表尾终端结点指向新结点
        r->next = p;
        //将当前的新结点定义为表尾端结点
        r = p;
    }
    //表示当前链表结束
    r->next = NULL;
}

Status clear_list(LinkList *L){
    LinkList p, q;
    p = (*L)->next;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

void foreach_list(LinkList *L){
    LinkList p;
    p = (*L)->next;
    int i = 1;
    if(!p){
        printf("empty list!\n");
    }
    while(p){
        printf("--i is: %d --%d----\n",i,  p->data);
        p = p->next;
        i++;
    }
}

int main( int argc, char *argv[] ) /* 带参数形式 */
{
    LinkList head;
    create_list_head(&head, 10);
    foreach_list(&head);
    // Status res = list_insert(&head, 4, 999);
    // printf("insert res is: %d\n", res);
    // ElemType ele;
    // list_delete(&head, 3, &ele);
    // printf("deleted ele is :%d\n", ele);
    clear_list(&head);

    printf("********\n");
    foreach_list(&head);
    return 0;
}






