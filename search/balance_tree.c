#include <stdio.h>
#include <stdlib.h>
#include "header.h"


//平衡二叉树(Self-Balancing Binary Search Tree)
//是一种二叉排序树,其中每一个节点的左子树和右子树的高度差至多
//等于1.
//即AVL树
//二叉树上结点的左子树深度减去右子树深度的值称为平衡因子(Balance Factor)
//距离插入点最近的,且平衡因子的绝对值大于1的结点为根的子树,称为最小不平衡树



//对以p为根的二叉排序树作右旋处理
//处理之后p指向新的树根结点,即旋转处理之前的左子村的根结点
void r_rotate(BiTree *P){
    BiTree L;
    //L指向P的左子树根结点
    L = (*P)->lchild;
    //P的左子树挂接L的右子树
    (*P)->lchild = L->rchild;
    L->rchild = (*P);
    //P指向新的根结点
    *P = L;
}

//对以P为根结点的二叉树作左旋处理
//处理之后的P指向新的树根结点,即旋转处理之前的右子树的根结点
void l_rotate(BiTree *P){
    BiTree R;
    //R指向P的右子树的根结点
    R = (*P)->rchild;
    //P的右子树挂接R的左子树
    (*P)->rchild = R->lchild;
    R->lchild = (*P);
    //P指向新的根结点
    *P = R;
}

#define LH 1;//左高
#define EH 0;//等高
#define RH -1;//右高

//对以指针T所指结点为根的二叉树作左平衡处理
//最终T指向新的根结点
void left_balane(BiTree *T){
    BiTree L, Lr;
    //L指向T的左子树根结点
    L = (*T)->lchild;
    switch(L->bf){
        //检查T的左子树的平衡度,并作相应平衡处理
        case LH:
            //新结点插入在T的左孩子的左子树上,要作单右旋转处理
            (*T)->bf = L->bf = EH;
            r_rotate(T);
            break;
        case RH:
            //新结点插入在T的左孩子的右子树上,要作双旋转处理
            //Lr指向T的左孩子的右子树根
            Lr = L->rchild;
            //修改T及左孩子的平衡因子
            switch(Lr->br){
                case LH:
                    (*T)->bf = RH;
                    L-bf = EH;
                    break;
                case EH:
                    (*T)->bf = L->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    L->bf = LH;
                    break;
            }
            Lr->bf = EH;
            //对T的左子树作左平衡处理
            l_rotate(&(*T)->lchild);
            //对T作右平衡处理
            r_rotate(T);
    }
}



int main( int argc, char *argv[] ) /* 带参数形式 */
{

    return 0;
}