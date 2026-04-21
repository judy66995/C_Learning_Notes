#include <stdio.h>
#define arr_len(a) (sizeof(a)/sizeof(a[0]))

int insert_sort(int a[], int len);

int main()
{
	int i;
	int a[] = { 2,4,1,3,9,7,5,6,70,43,90,2,899,0 };
	int len= arr_len(a);
	printf("数组的长度为：%d\n",len);
	printf("排序前的数组为： ");
	for (i = 0; i <= len - 1; i++) 
	{
		printf("%d ", a[i]);
	}

	insert_sort(a, len);

	printf("\n排序后的数组为： ");
	for (i = 0; i <= len - 1; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

int insert_sort(int a[], int len)
{
	int j,i,z,cur_index;
	for (cur_index = 1; cur_index < len ; cur_index++)
	{
		z = a[cur_index];
		for (i = cur_index - 1; i >= 0; i--)
		{
			if (z < a[i])
			{
				a[i + 1] = a[i];
			}
			else
			{
				break;
			}
		}
		a[i + 1] = z;
	}
	return 0;
}