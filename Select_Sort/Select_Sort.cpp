#include <stdio.h>
#include "print_arr.h"



int select_sort(int a[], int len);


int main()
{
	int i,len;
	int a[] = { 2,4,1,3,9,7,5,6,70,43,90,2};
	len = arr_len(a);
	printf("排序前的数组为：");
	
	print_arr(a,len);

	printf("\n该数组的长度为%d\n", len);
	printf("排序后的数组为：");
	select_sort(a,len);

	print_arr(a, len);

	return 0;
}

int select_sort(int a[],int len)
{
	int i,j,z,min_index;
	for (j = 0; j <= len-1; j++)
	{ 
		min_index = j;
		z = a[j];
		for(i = j; i <= len-1; i++)
		{
			while (a[i] < a[min_index])
			{
				min_index = i;
			}
		}	
		a[j] = a[min_index];
		a[min_index] = z;
	}
	return 0;
}

