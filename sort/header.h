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