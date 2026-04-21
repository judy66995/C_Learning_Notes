#include "print_arr.h"
#include <stdio.h>
//源文件，只放实现
void print_arr(int a[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
}