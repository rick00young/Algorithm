#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <sys/time.h>

Status init_queue(SqQueue *Q){
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

int queue_length(SqQueue Q){
    return (Q.rear - Q.front + MAXSIZE)%MAXSIZE;
}

int en_queue(SqQueue *Q, EleType e){
    //队列满的判断
    if((Q->rear + 1)%MAXSIZE == Q->front){
        return ERROR;
    }
    Q->data[Q->rear] = e;
    //rear指针向后移一位置
    //若到最后则转到数组头部
    Q->rear = (Q->rear+1)%MAXSIZE;
    return OK;
}

Status de_queue(SqQueue *Q, EleType *e){
    //队列为空
    if(Q->front == Q->rear){
        return ERROR;
    }
    *e = Q->data[Q->front];
    //front指针向后移一位置,若到最后则转到数头部
    Q->front = (Q->front+1)/MAXSIZE;
    return OK;
}


int main( int argc, char *argv[] ) /* 带参数形式 */
{

    return 0;
}






