#include"swap.h"

void swap(int& x, int& y)
{
	int z;
	z = x;
	x = y;
	y = z;
}