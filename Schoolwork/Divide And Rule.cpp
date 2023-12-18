#define _CRT_SECURE_NO_WARNINGS  1    //防止scanf报错

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

//分治


int Search(int arr[], int L, int R, int target)//二分查找，时间复杂度O(log 2 n)
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
	int arr[] = { 1,4,6,8,12,17,19,24,29 };//有序
	int target;
	printf("查找元素：");
	scanf("%d", &target);
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d",Search(arr, 0, len, target));//元素位置或待插入位置
}


void QuickSort(int* arr, int left, int right)//快速排序,时间复杂度O(nlong n),不稳定
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



int QuickSelect(int* arr, int left, int right, int k)//第K小问题
{
	if (left == right && left == k - 1)//如果要寻找的子序列中只有一个元素且这个元素正好是要找的第k小元素
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

		/*---  经过一趟快速排序后，arr[L]左边全为小于其的数，右边全为大于其的数  ---*/

		if (L == k - 1)
			return arr[left];
		else if (k - 1 < L)//要找的元素在左区间,对右区间继续递归查找
			QuickSelect(arr, left, L - 1, k);
		else//要找的元素在右区间,对右区间继续递归查找
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
		printf("第%d小的元素是%d\n", k, res);
	}
}



int MAX_Son_Sum(int arr[], int left, int right)//最大子段和
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

