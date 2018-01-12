#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <sys/time.h>

//前序遍历---从根到左子树的最左再到右子树的最右
void pre_order_foreach(BiTree T){
    if(T == NULL){
        return;
    }
    printf("%s\n", T->data);
    pre_order_foreach(T->lchild);
    pre_order_foreach(T->rchild);
}

//中序遍历---从左子树的最左到根再到右子树的最右
void in_order_foreach(BiTree T){
    if(T == NULL)
        return;
    in_order_foreach(T->lchild);
    printf("%d\n", T->data);
    in_order_foreach(T->rchild);
}

//后序遍历---从左子树的最左到右子树的最右再到根
void post_order_foreach(BiTree T){
    if(T == NULL)
        return
    post_order_foreach(T->lchild);
    post_order_foreach(T->rchild);
    printf("%d\n", T->data);
}

//如果所用的二叉树需要经常遍历或是查找结点时需要某种遍历序列中的前驱
//或后继,线索二叉树的存储结构是个非常不错摆选择.

int main( int argc, char *argv[] ) /* 带参数形式 */
{

    return 0;
}






