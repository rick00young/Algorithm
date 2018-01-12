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