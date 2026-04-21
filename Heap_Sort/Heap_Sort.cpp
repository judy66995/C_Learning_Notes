#include <stdio.h>
#include "print_arr.h"
#include "swap.h"

int heap(int a[], int len, int n);
void heapsort(int a[], int len);

int main() 
{
	int a[] = { 12, 11, 13, 5, 6, 7 ,9,20,3,4,100,0,88,80,66,12};
	int len = arr_len(a);
	printf("数组长度为：%d\n",len);

	printf("排序前：");
	print_arr(a, len);
	

	heapsort(a,len);

	printf("\n排序后：");
	print_arr(a, len);
	return 0;
}

void heapsort(int a[], int len)
{
	for (int i=len/2-1 ; i >= 0; i--)
	{//建堆：从最后一个非叶子节点向前扫描，每经过一个节点，就将其所在及下面树建好堆
		heap(a,len,i);
	}
	for (int j = len - 1; j >= 0; j--)
	{
		swap(a[0], a[j]);//逐渐交换堆顶和末尾
		heap(a, j, 0);//堆长度越来越小
	}
}

int heap(int a[], int len, int n) //堆调整：以节点位置n，通过和其左右孩子比较大小
								   //将最大的调整到节点位置n，并通过递归调整下面可能被影响的子树
{//传入数组a，数组长度len，节点位置n
	int largest = n;//默认当前节点位置的元素为最大值
	int left = 2 * n + 1;//左孩子节点位置
	int right = 2 * n + 2;//右孩子节点位置

	if ( left < len && a[largest] < a[left] )
	{
		largest = left;
	}
	if (right < len && a[largest] < a[right])
	{
		largest = right;
	}
	//上面的两个if判断largest是否需要更新为左孩子位置或者右孩子位置

	if (largest != n)//如果最大值不是a[n],就交换，同时交换后有可能破坏子树，故需递归
	{
		swap(a[largest], a[n]);
		heap(a, len, largest);//递归调整下面可能受到影响的子树
	}
	return 0;
}