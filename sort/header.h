#define MAXSIZE 10
typedef struct 
{
	int r[MAXSIZE+1];
	int length;
} SqList;

/**
 * 交换数据
 * @param L [description]
 * @param i [description]
 * @param j [description]
 */
void swap(SqList *L, int i, int j){
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/**
 * [bubble_print description]
 * @param L [description]
 */
void sqlist_print(SqList *L){
	if (L == NULL){
		return;
	}
	for (int i = 1; i < L->length; ++i)
    {
    	printf("%d\n", L->r[i]);
    }
}