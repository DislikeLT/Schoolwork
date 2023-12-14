#define _CRT_SECURE_NO_WARNINGS  1    //防止scanf报错

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

//栈

void Starck_increase(int arr[], int arr_len)//单调递增栈
{
	int* stack = NULL;
	stack = (int*)malloc(arr_len * sizeof(int));
	if (!stack)
	{
		perror("malloc");
		exit(-1);
	}
	memset(stack, 0, sizeof(stack));
	int pos = -1;
	int i = 0;
	do
	{
		if (pos == -1)
			stack[pos++] = arr[i++];
		else
		{
			int j = pos;
			while (stack[j] < arr[i])
			{
				stack[j] = arr[i];
				pos--;
			}
			j = pos;
		}
	} while (pos);
	for (int i = 0; i < pos; i++)
	{
		printf("%d ", stack[i]);
	}
}

void test08()
{
	int arr[] = { 10,3,7,4,12 };
	int arr_len = sizeof(arr) / sizeof(arr[0]);
	Starck_increase(arr, arr_len);
}