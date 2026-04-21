#include <stdio.h>
#include <stdlib.h>
#include "print_arr.h"
#include "swap.h"

int find_maxdigit(int a[],int len);
void radixsort(int a[],int len);

int main()
{
	int a[] = {194,451,934,847,223,373,223,6,965,510};
	int len = arr_len(a);
	printf("数组a[]=");
	print_arr(a, len);
	printf("\n数组的长度为%d\n", len);

	radixsort(a, len);
	printf("\n排序后a[]=");
	print_arr(a, len);

	return 0;
}

//找出最大数的位数
int find_maxdigit(int a[], int len)
{
	int max = a[0];
	for (int i = 0; i < len; i++)
	{
		if (a[i] > max) max = a[i];
	}
	printf("最大数是%d\n", max);
	int digit = 0;
	if (max == 0)
	{
		digit = 1;
	}
	else while (max)
	{
		digit++;
		max /= 10;
	}
	printf("最大数的位数是%d", digit);
	return digit;
}

void radixsort(int a[], int len)
{
	int digit = find_maxdigit(a, len);
	int i, j, k;
	int r;
	int exp = 1;//低位first
	
	int* tmp = (int*)calloc(len, sizeof(int));
	if (tmp == NULL)
	{
		perror("calloc fail!");
		return;
	}

	for (i = 0; i < digit; i++)
	{
		int count[10] = { 0 };//用于储存 统计当前位0~9每个数字出现多少次 的结果
		
		//1.统计：当前位0~9每个数字出现多少次
		for (j = 0; j < len; j++)//扫描a[]数组
		{
			r = (a[j] / exp) % 10;//取出当前位的数字
			count[r]++;//统计当前位0~9每个数字出现多少次
		}
		//print_arr(count, 10);
		
		//2.定位：计算前缀和，确定每个数字应该放在那个位置
		for (k = 1; k < 10; k++)
		{
			count[k] = count[k] + count[k - 1];
		}
		//print_arr(count, 10);
		//3.回填：从后往前遍历（保证稳定）原数组，把数组放进临时数组tmp里
		//从后往前遍历原数组，根据前缀和算出的位置，把元素放进 tmp 数组，每放一个就把位置往前挪一个。

		for (k = len-1; k >= 0; k--)//从后往前遍历
		{
			r = (a[k] / exp) % 10;//取出当前位的数字

			tmp[count[r] - 1] = a[k];
			count[r]--;
		}

		//4.复制回原数组
		for (j = 0; j < len; j++)
		{
			a[j] = tmp[j];
		}

		exp *= 10;//下一位
	}
	free(tmp);
	tmp = NULL;
}