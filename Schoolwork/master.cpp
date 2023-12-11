#define _CRT_SECURE_NO_WARNINGS  1    //∑¿÷πscanf±®¥Ì

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include "Function Definition.h"
#include<setjmp.h>
#include <cassert>

int Allocation_handled = 0;
jmp_buf Allocate_Failed;

void* allocate(unsigned n)
{
	void* brr = malloc(n);
	if (!brr)
		return brr;
	if (Allocation_handled)
		longjmp(Allocate_Failed, 1);
	assert(0);
}
int main()
{
	void* arr;
	arr = allocate(10);
}
