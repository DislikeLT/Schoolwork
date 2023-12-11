#define _CRT_SECURE_NO_WARNINGS  1    //防止scanf报错

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

//分治



void test03()//二分查找
{
	int arr[] = { 1,4,6,8,12,17,19,24,29 };//有序
	int target;
	printf("查找元素：");
	scanf("%d", &target);
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d",Search(arr, 0, len, target));//元素位置或待插入位置
}

int Search(int arr[], int L, int R, int target)
{
	if (L > R)
		return L;
	int mid = L + (R - L) / 2;
	if (arr[mid] < target)
		Search(arr, mid + 1, R, target);
	else if (arr[mid] > target)
		Search(arr, L, mid - 1, target);
	else
		return mid;
}


void test04()//快速排序
{
	int arr[] = { 2,13,5,24,45,20,33,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, len - 1);
}

void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	int L = right;
	int R = mid + 1;
	int sum = arr[L];
	while (L < R)
	{
		while (L<R && arr[R]>sum)
			R--;
		arr[L] = arr[R];
		while (L < R && arr[L] < sum)
			L--;
		arr[R] = arr[L];
	}
	arr[L] = sum;
	QuickSort(arr, left, mid-1);
	QuickSort(arr, mid + 1, right);
	return;
}


