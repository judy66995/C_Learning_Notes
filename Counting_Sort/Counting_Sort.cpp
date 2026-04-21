#include <stdio.h>
#include <stdlib.h>
#include "print_arr.h"
#include "swap.h"

void countingsort(int a[],int len);
int findmin(int a[],int len);
int findmax(int a[], int len);
void forcount_std(int a[], int len);

int main()
{
	int a[] = {4,6,10,18,3,41,16,5,7,8,6,5,47,9};
	int len = arr_len(a);
	printf("数组a[]的长度为%d\n未排序前a[]=", len);
	print_arr(a, len);

	countingsort(a,len);
	return 0;
}

void countingsort(int a[],int len)
{
	int min = findmin(a, len);
	int max = findmax(a, len);
	int range = max - min + 1;

	//向系统申请一块连续的内存空间，用来存放 range 个 int 类型的变量，并且把所有元素自动初始化为 0。
	int* tmp = (int*)calloc(range, sizeof(int));
	//(int*) 是强制类型转换，把 calloc 返回的 void* 指针转换成 int* 类型，方便后续按 int 数组来访问这块内存。
	if (tmp == NULL)
	{
		perror("calloc fail!\n");
		return;
	}

	forcount_std(a, len);//为计数标准化
	printf("\n数组归一化后a_std[]=");
	print_arr(a, len);
	
	for (int i = 0; i < len; i++)//遍历数组中的每一个元素
	{
		tmp[a[i]]++;//计数排序真正的优势
		/*for (int j = 0; j < l; j++)
		{
			if (a[i] == j)//若a_std[i] = tem的index,则tem[index]+=1
			{
				tem[j] = tem[j] + 1;
			}
		}*/

	}
	printf("\n中间变量tem[]=");
	print_arr(tmp, range);
	printf("\n排序后：");


	for (int j = 0; j < range; j++)
	{
		for (int k = 0; k < tmp[j]; k++)
			printf("%d ", j + min);
		/*if (tem[j] > 1)
		{
			for (int i = 0; i < tem[j]; i++)
			{
				printf("%d ", j + min);
			}
		}
		if (tem[j] == 1)
		{
			printf("%d ", j + min);
		}*/
	}
	//释放资源，避免内存泄漏
	free(tmp);
	tmp = NULL;
}

int findmin(int a[],int len)
{
	int min = a[0];
	for (int i = 1; i < len; i++)
	{
		if(a[i] < min)
		{
			min = a[i];
		}
	}
	return min;
}

int findmax(int a[], int len)
{
	int max = a[0];
	for (int i = 1; i < len; i++)
	{
		if(a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

void forcount_std(int a[],int len)//为计数标准化
{
	int min = findmin(a, len);
	for (int i = 0; i < len; i++)
	{
		a[i] = a[i] - min;
	}
}