#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;


typedef struct BiTNode
{
    int data;
    int bf;//平衡因子
    struct BiTNode *lchild, rchild;
}BiTNode, *BiTree;

#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12
#define NULLKEY -32768

typedef struct
{
    int *elem;
    int count;
}HashTable;