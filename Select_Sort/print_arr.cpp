#include "print_arr.h"
#include <stdio.h>

void print_arr(int a[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
}