#include <stdio.h>
#include <stdlib.h>
#include "header.h"


typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

Status searchBST(BiTree T, int key, BiTree f, BiTree *p);
Status insertBST(BiTree *T, int key);
void forwardForeach(BiTree T);
void middleForeach(BiTree T);
void backwardForeach(BiTree T);
Status deleteBST(BiTree *T, int key);
Status delete(BiTree *p);


int main( int argc, char *argv[] ) /* 带参数形式 */
{
    // BiTree f = malloc(sizeof(BiTNode));
    // f->data = 100;
    // printf("%d\n", f->data);
    // BiTree f;
    // insertBST(&f, 222);
    // printf("%d\n", f->data);
    int i;
    int a[] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
    BiTree T = NULL;
    for(i = 0; i < 10; i++){
    	insertBST(&T, a[i]);
    }
    // forwardForeach(T);
    middleForeach(T);
    return 0;
}

void forwardForeach(BiTree T){
	if (T == NULL){
		return;
	}
	printf("%d\n", T->data);
	forwardForeach(T->lchild);
	forwardForeach(T->rchild);
}

void middleForeach(BiTree T){
	if (T == NULL){
		return;
	}
	middleForeach(T->lchild);
	printf("%d\n", T->data);
	middleForeach(T->rchild);
}

void backwardForeach(BiTree T){
	if (T == NULL){
		return;
	}
	backwardForeach(T->lchild);
	backwardForeach(T->rchild);
	printf("%d\n", T->data);
}


Status searchBST(BiTree T, int key, BiTree f, BiTree *p){
	if(!T){
		*p = f;
		return FALSE;
	}
	else if(key == T->data){
		*p = T;
		return TRUE;
	}else if(key < T->data){
		return searchBST(T->lchild, key, T, p);
	}else{
		searchBST(T->rchild, key, T, p);
	}
	return FALSE;
}

Status insertBST(BiTree *T, int key){
	BiTree p, s;
	if (!searchBST(*T, key, NULL, &p)){
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if(!p){
			*T = s;
		}else if(key < p->data){
			p->lchild = s;
		}else{
			p->rchild = s;
		}
		return TRUE;
	}else{
		return FALSE;
	}
}

Status deleteBST(BiTree *T, int key){
	/**
	 * 1. 叶子结点
	 * 2. 仅有左或右子树的结点
	 * 3. 左右子树都有结点
	 * 若二叉排序树T中存在关键字等于key的数据元素,则删除该数据元素结点,
	 * 并返回TRUE,否则返回FALSE
	 */
	if (!T){
		return FALSE;
	}else{
		if(key == (*T)->data)
			return delete(T);
		else if(key < (*T)->data)
			return deleteBST(&(*T)->lchild, key);
		else
			return deleteBST(&(*T)->rchild, key);
	}
}

/**
 * 从二叉排序树中删除结点p,并重接它的左或右子树
 * @param  p [description]
 * @return   [description]
 */
Status delete(BiTree *p){
	BiTree q, s;
	//右子树空则只需要重接它的左子树
	if((*p)->rchild == NULL){
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	//左子树为空只需要重接它的右子树
	else if((*p)->lchild == NULL){
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	//左右子树都不为空
	//找到需要删除的结点的直接前驱或是直接后继s,用要代替p,然后删除s
	else{
		q = *p;
		s = (*p)->lchild;
		//转左,然后向右到尽头(找到待删除结点的前驱)
		while(s->rchild){
			q = s;
			s = s->rchild;
		}
		//s指向被删除结点的直接前驱
		(*p)->data = s->data;
		if(q != *p)
			q->lchild = s->lchild;//重接q的右子树
		else
			q->lchild = s->lchild;//重接q的左子树
	}
	return TRUE;
}



















