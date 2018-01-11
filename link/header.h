#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

/* 存储空间初始分配量 */
#define MAXSIZE 20
/* ElemType类型根据实际情况而定，这里假设为int */
typedef int ElemType;
typedef struct
{
    /* 数组存储数据元素，最大值为MAXSIZE */
    ElemType data[MAXSIZE];
    /* 线性表当前长度 */
    int length;
} SqList;


typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList;


