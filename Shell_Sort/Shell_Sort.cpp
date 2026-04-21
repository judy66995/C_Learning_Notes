#include <stdio.h>
#define arr_len(a) (sizeof(a)/sizeof(a[0]))

int shell_sort(int a[], int len);

int main()
{
	int a[] = { 2,4,1,3,9,7,5,6,70,43,90,2,899,0 ,12,8};
	int len = arr_len(a);
	int i;
	printf("数组的长度为：%d\n", len);
	printf("排序前的数组为： ");
	for (int i = 0; i <= len - 1; i++)
	{
		printf("%d ", a[i]);
	}

	shell_sort(a, len);

	printf("\n排序后的数组为： ");
	for (i = 0; i <= len - 1; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}

int shell_sort(int a[], int len)
{
	int z,i,j,gap;
	for (gap = len / 2; gap >= 1; gap /= 2)
	{
		for (i = gap; i < len; i++)
		{
			z = a[i];
			j = i;
			while (j >= gap && z < a[j-gap])
			{
				a[j] = a[j - gap];
				j -= gap;
			}
			a[j] = z;
		}
	}
	return 0;
}