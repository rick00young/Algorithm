#include <stdio.h>
/**
 * 顺序查找
 */

int sequential_search(int *a, int n, int key);

int main()
{
    /* 我的第一个 C 程序 */
    printf("Hello, World! \n");

    int a[] = {1, 2, 3};
    int result = sequential_search(a, 3, 2);
    printf("%d\n", result);
 
    return 0;
}

/*
int sequential_search(int *a, int n, int key){
	int i;
	for(i = 1; i <= n; i ++){
		if (a[i] == key){
			return i;
		}
	}
	return 0;
}
*/