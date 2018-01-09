#include <stdio.h>
/**
 * /
 * @param  a   [description]
 * @param  n   [description]
 * @param  key [description]
 * @return     [description]
 * 算法复杂法: O(log(n))
 */
int binary_search(int *a, int n, int key);

int main()
{
    /* 我的第一个 C 程序 */
    printf("Hello, World! \n");

    int a[] = {0,1,16,24,35,47,59,62,73,88,99};
    int result = binary_search(a, 11, 2);
    printf("%d\n", result);
 
    return 0;
}

int binary_search(int *a, int n, int key){
	int low, high, mid;
	low = 1;
	high = n;
	while(low <= high){
		//折半
		mid = (low + high)/2;
		// 这样更高效,同时(key - a[low])/(a[high] - a[low])为插值法
		// mid = low + (high - low)*(key - a[low])/(a[high] - a[low]);
		//若查找值比中值小
		if (key <= a[mid]){
			high = mid - 1;
		}else if(key > a[mid]){
			low = mid + 1;
		}else{
			return mid;
		}
	}
	return 0;
}