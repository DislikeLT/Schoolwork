#define _CRT_SECURE_NO_WARNINGS  1    //��ֹscanf����

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

//����


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

void test03()//���ֲ���
{
	int arr[] = { 1,4,6,8,12,17,19,24,29 };//����
	int target;
	printf("����Ԫ�أ�");
	scanf("%d", &target);
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d",Search(arr, 0, len, target));//Ԫ��λ�û������λ��
}


void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int L = left;
	int R = right;
	int sum = arr[left];
	while (L < R)
	{
		while (L<R && arr[R]>sum)
			R--;
		arr[L] = arr[R];
		while (L < R && arr[L] < sum)
			L++;
		arr[R] = arr[L];
	}
	arr[L] = sum;
	QuickSort(arr, left, L - 1);
	QuickSort(arr, L + 1, right);
	return;
}

void test04()//��������
{
	int arr[] = { 2,13,5,24,45,20,33,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, len - 1);
	for (int i = 0; i < len; i++)
		printf("%d-", arr[i]);
}

