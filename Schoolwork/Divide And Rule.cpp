#define _CRT_SECURE_NO_WARNINGS  1    //��ֹscanf����

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

//����


int Search(int arr[], int L, int R, int target)//���ֲ��ң�ʱ�临�Ӷ�O(log 2 n)
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

void test03()
{
	int arr[] = { 1,4,6,8,12,17,19,24,29 };//����
	int target;
	printf("����Ԫ�أ�");
	scanf("%d", &target);
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d",Search(arr, 0, len, target));//Ԫ��λ�û������λ��
}


void QuickSort(int* arr, int left, int right)//��������,ʱ�临�Ӷ�O(nlong n),���ȶ�
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

void test04()
{
	int arr[] = { 2,13,5,24,45,20,33,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, len - 1);
	for (int i = 0; i < len; i++)
		printf("%d-", arr[i]);
}



int QuickSelect(int* arr, int left, int right, int k)//��KС����
{
	if (left == right && left == k - 1)//���ҪѰ�ҵ���������ֻ��һ��Ԫ�������Ԫ��������Ҫ�ҵĵ�kСԪ��
		return arr[left];
	else if (left < right)
	{
		int L = left;
		int R = right;
		int sum = arr[L];
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

		/*---  ����һ�˿��������arr[L]���ȫΪС����������ұ�ȫΪ���������  ---*/

		if (L == k - 1)
			return arr[left];
		else if (k - 1 < L)//Ҫ�ҵ�Ԫ����������,������������ݹ����
			QuickSelect(arr, left, L - 1, k);
		else//Ҫ�ҵ�Ԫ����������,������������ݹ����
			QuickSelect(arr, L + 1, right, k);
	}
}


void  test11()
{
	int arr[] = { 4,6,1,12,14,34,22,17 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int k = 4;
	for (int k = 1; k <= len; k++)
	{
		int res = QuickSelect(arr, 0, len - 1, k);
		printf("��%dС��Ԫ����%d\n", k, res);
	}
}



int MAX_Son_Sum(int arr[], int left, int right)//����Ӷκ�
{
	int MAX = 0;

#if 1
	int L_MAX = 0, R_MAX = 0;
	int LL_sum = 0, RR_sum = 0;
	if (left == right)
	{
		if (arr[left] > 0)
			MAX = arr[left];
		else
			MAX = 0;
	}
#endif

#if 0
	int L_MAX = -999999, LR_MAX = 0, R_MAX = -999999;
	int LL_sum = 0, RR_sum = 0;
	if (left == right)
		MAX = arr[left];
#endif

	else
	{
		int mid = left + (right - left) / 2;
		LL_sum = MAX_Son_Sum(arr, left, mid);
		RR_sum = MAX_Son_Sum(arr, mid + 1, right);
		for (int i = mid; i >= left; i--)
		{
			L_MAX = L_MAX > (L_MAX + arr[i]) ? L_MAX : (L_MAX + arr[i]);
		}
		for (int i = mid + 1; i <= right; i++)
		{
			R_MAX = fmax(R_MAX, (R_MAX + arr[i]));
		}
		MAX = L_MAX + R_MAX;
		MAX = (LL_sum > RR_sum ? LL_sum : RR_sum) > MAX ? (LL_sum > RR_sum ? LL_sum : RR_sum) : MAX;
	}
	return MAX;
}

void test12()
{
	//int arr[] = { -1,3,2,-4,1,5,-1,2 };
	int arr[] = { -20,11,-4,13,-5,-2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d", MAX_Son_Sum(arr, 0, len - 1));
}

