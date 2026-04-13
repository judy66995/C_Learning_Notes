#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

#define arr_len(a) (sizeof(a) / sizeof((a)[0]))

int BubbleSort(int a[], int len);
int main()
{
    int a[8];
    int i;
    int len;
    printf("请输入8个数\n");
    for (i = 0; i < 8; i++)
    {
        scanf_s("%d", &a[i]);
    }
    len = arr_len(a);
    printf("输入数组的长度为%d\n", len);

    BubbleSort(a,len);

    for (i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

int BubbleSort(int a[], int len)
{
    int i, j, z;
    for (i = 0; i < len-1; i++)
    {
        for (j = 0; j < len - i - 1; j++)
        {
        if (a[j] > a[j + 1])
            {
                z = a[j];
                a[j] = a[j + 1];
                a[j + 1] = z;
            }
        }
    }
    return 0;
}