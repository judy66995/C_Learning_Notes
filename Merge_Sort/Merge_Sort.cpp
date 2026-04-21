#include <stdio.h>
#include "sort.h"

#define arr_len(a) (sizeof(a)/sizeof(a[0]))

int main()
{
	int a[] = { 5,2,4,7,1,3,6,10,9,8 };
	int len = arr_len(a);

	printf("数组长度：%d\n", len);

	printf("排序前：");
	PrintArray(a, len);

	MergeSort(a, 0, len - 1);

	printf("排序后：");
	PrintArray(a, len);

	return 0;
}