#pragma once
// 只放声明、宏，绝对不放函数实现、全局变量
void print_arr(int a[], int len);
#define arr_len(a) (sizeof(a) / sizeof(a[0]))
