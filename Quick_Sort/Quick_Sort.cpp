#include <stdio.h>
#include "print_arr.h"
#include "swap.h"

int quicksort(int a[], int left, int right);

int main()
{
	int len;
	int a[] = { 65,58,95,10,57,62,13,106,78,23,85,100 };
	len = arr_len(a);
	printf("数组的长度为:%d\n",len);
	printf("排序前的数组为:");
	print_arr(a, len);
	quicksort(a, 0, len - 1);
	printf("\n交换后为:");
	print_arr(a, len);
	return 0;
}

int quicksort(int a[], int left, int right)
{
	int i, j, tem;

	tem = a[left];//分治区间的第一个元素作为基准值
	i = left;//左扫描的index
	j = right;//右扫描的index
	if (left >= right) return 0;//递归停止条件：子数组长度<=1,不用排序，直接返回
	while (i!=j)//直到左右扫描的index相遇，跳出循环
	{
	
		while (a[j] >= tem && j > i)//扫描右边，发现有小于基准值的跳出循环
		{
			j--;
		}
		while (a[i] <= tem && i < j)//扫描左边，发现有大于基准值的跳出循环
		{
			i++;
		}
		swap(a[i],a[j]);//把小于基准值的交换到左边，把大于基准值的交换到右边
	}
		
	if (i == j)//左右扫描的index相遇,把基准值和子区间的第一个元素做交换，
	{		   //交换后原来基准值的交换后的index成为区分子区间的分界点，而另一个被交换过去的成为新的基准值
		swap(a[left], a[i]);
	}
	
	quicksort(a,  left, i-1);
	quicksort(a,  i+1, right);

	return 0;
}