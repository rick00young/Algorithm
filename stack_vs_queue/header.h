#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

/* 存储空间初始分配量 */
#define MAXSIZE 20
/* ElemType类型根据实际情况而定，这里假设为int */

typedef int EleType;

typedef struct
{
    EleType data[MAXSIZE];
    int top;//用于栈顶指针
}SqStack;


//共享栈
typedef struct
{
    EleType data[MAXSIZE];
    int top1;
    int top2;
}SqDouboleStack;

//链栈
typedef struct StackNode
{
    EleType data;
    struct StackNode *next;
}StackNode, *LinkStackPrt;

typedef struct LinkStack
{
    LinkStackPrt top;
    int count;
}LinkStack;


// queue
typedef struct
{
    EleType data[MAXSIZE];
    int front;
    int rear;
} SqQueue;


typedef struct QNode
{
    EleType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front, rear;
}LinkQueue;



