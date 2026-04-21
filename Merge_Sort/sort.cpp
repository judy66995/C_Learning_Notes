#include "sort.h"
#include <stdio.h>

// 打印数组
void PrintArray(int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// 归并排序
void MergeSort(int a[], int left, int right)
{
	int t[100];
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);

		int i = left, j = mid + 1, k = 0;
		while (i <= mid && j <= right)
		{
			if (a[i] < a[j])
				t[k++] = a[i++];
			else
				t[k++] = a[j++];
		}

		while (i <= mid)
			t[k++] = a[i++];
		while (j <= right)
			t[k++] = a[j++];

		k = 0;
		for (i = left; i <= right; i++)
		{
			a[i] = t[k++];
		}
	}
}