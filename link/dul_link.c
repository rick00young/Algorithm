#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <sys/time.h>

//某一个点的前驱和后驱都是它自己
p->next->prev = p = p->prev->next

//insert
//p<->[q]     p<->s<->[q]
//将s插入p之后
s = new(DulNode);

s->prev = p;
s->next = p->next;
p->next->prev = s;
p->next = s;


//delete
//a<->p<->b 删除a
p->prev->next = p->next;
p->next->prev = p->prev;
free(p);

int main( int argc, char *argv[] ) /* 带参数形式 */
{

    return 0;
}