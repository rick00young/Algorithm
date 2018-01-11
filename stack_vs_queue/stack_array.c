#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <sys/time.h>

Status push(SqStack *S, EleType e){
    if(S->top == MAXSIZE-1)//栈满
    {
        return ERROR;
    }
    S->top++;
    S->data[S->top] = e;
    return OK;
}

Status pop(SqStack *S, EleType *e){
    if(S->top == -1){
        return ERROR;
    }
    *e = S->data[S->top];
    S->top--;
    return OK;
}

void foreach_stack(SqStack *S){
    int top = S->top;
    while(top>0){
        printf("the stack[%d] is: %d\n", top, S->data[top]);
        top--;
    }
}

Status d_push(SqDouboleStack *S, EleType e, int stack_no){
    if(S->top1+1 == S->top2){//栈已满
        return ERROR;
    }
    if(stack_no == 1){
        S->data[++S->top1] = e;
    }else if(stack_no == 2){
        S->data[--S->top2] = e;
    }
    return OK;
}

Status d_pop(SqDouboleStack *S, EleType *e, int stack_no){
    if(1 == stack_no){
        if(S->top1 == -1){
            return ERROR;
        }
        *e = S->data[S->top1--];
    }else if(2 == stack_no){
        if(S->top2 == MAXSIZE){
            return ERROR;
        }
        *e = S->data[S->top2++];
    }
    return OK;
}

int main( int argc, char *argv[] ) /* 带参数形式 */
{
    SqStack *S = (SqStack*)malloc(sizeof(SqStack));
    Status res1 = push(S, 1);
    Status res2 = push(S, 2);
    Status res3 = push(S, 3);
    printf("---push statck---\n");

    foreach_stack(S);

    printf("---pop statck---\n");
    EleType pop_res;
    pop(S, &pop_res);
    foreach_stack(S);
    printf("---pop res---%d\n", pop_res);
    return 0;
}






