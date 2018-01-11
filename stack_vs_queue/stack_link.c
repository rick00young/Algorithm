#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <sys/time.h>

Status push(LinkStack *S, EleType e){
    LinkStackPrt s = (LinkStackPrt)malloc(sizeof(StackNode));
    s->data = e;
    //头节点插入
    s->next = S->top;
    S->top = s;

    S->count++;
    return OK;
}

Status pop(LinkStack *S, EleType *e){
    LinkStackPrt p;
    if(S->count == 0){
        printf("empty stack!\n");
        return ERROR;
    }
    *e = S->top->data;
    //栈顶结点赋值p
    p = S->top;
    //栈项指针下移一位
    S->top = S->top->next;
    free(p);
    S->count--;
    return OK;
}

void foreach_stack(LinkStack *S){
    LinkStackPrt top;
    top = S->top;
    int count = S->count;
    while(count > 0){
        printf("top prt is: %p\n", top);
        printf("stakc[%d] -- %d\n", count, top->data);
        count--;
        top = top->next;
    }
}

int main( int argc, char *argv[] ) /* 带参数形式 */
{
    LinkStack *S = (LinkStack *)malloc(sizeof(LinkStack));
    push(S, 2);
    push(S, 3);
    push(S, 4);
    printf("count is:%d\n", S->count);
    printf("push stack\n");
    foreach_stack(S);

    printf("\n");
    printf("pop stack\n");
    EleType res;
    pop(S, &res);
    foreach_stack(S);
    return 0;
}






