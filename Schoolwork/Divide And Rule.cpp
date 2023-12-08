#define _CRT_SECURE_NO_WARNINGS  1    //防止scanf报错

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

//分治

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

void test03()//二分查找
{
	int arr[] = { 1,4,6,8,12,17,19,24,29 };//有序
	int target;
	printf("查找元素：");
	scanf("%d", &target);
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d",Search(arr, 0, len, target));//元素位置，或待插入位置


}
