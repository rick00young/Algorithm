#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <sys/time.h>

Status en_queue(LinkQueue *Q, EleType e){
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if(!s){
        exit(1);
    }
    s->data = e;
    s->next = NULL;
    //把拥有元素e新结点赋值给原队尾结点的后继
    Q->rear->next = s;
    // 把当前的s结点设置为队尾结点,rear指向s
    Q->rear = s;
    return OK;
}

Status de_queue(LinkQueue *Q, EleType *e){
    QueuePtr p;
    if(Q->front == Q->rear){
        return ERROR;
    }
    //将欲删除的队头结点暂存给p
    p = Q->front->next;
    *e = p->data;
    //将原队头结点后继p->next赋值给头结点后继
    Q->front->next = p->next;

    //若队头是队尾,删除后将rear指向头结点
    if(Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return OK;
}


int main( int argc, char *argv[] ) /* 带参数形式 */
{

    return 0;
}






