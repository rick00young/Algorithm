#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef int EleType;

typedef struct BiTNode
{
    EleType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


//线索二叉树
//Link == 0 表示指向左右孩子指针
//Thread==1 表示指向前驱或后继的线线索
typedef enum {Link, Thread} PointerTag;

typedef struct BiThrNode
{
    EleType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;//左右标志
}BiTNode, *BiThrTree;