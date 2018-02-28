#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a;
    a=sizeof(int);
    printf("int在内存中所占空间是:%d\n",a);
    char b;
    b=sizeof(char);
    printf("char在内存中所占空间是:%d\n",b);
    short c;
    c=sizeof(short);
    printf("short在内存中所占空间是:%d\n",c);
    int d;
    d=sizeof(long);
    printf("long在内存中所占空间是:%d\n",d);
    int e;
    e=sizeof(float);
    printf("float在内存中所占空间是:%d\n",e);
    int f;
    f=sizeof(double);
    printf("double在内存中所占空间是:%d\n",f);
    system("pause");
    return 0;
}