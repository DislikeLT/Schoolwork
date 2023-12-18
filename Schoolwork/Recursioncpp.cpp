#define _CRT_SECURE_NO_WARNINGS  1    //��ֹscanf����

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

//�ݹ�


bool Judge(int num)//�ж�ĳ���Ƿ�Ϊ2���ݴη�
{
	if (num == 1)
		return true;
	int sum = num % 2;
	num /= 2;
	if (sum != 0)
		return false;
	Judge(num);
}

void test01()
{
	printf("�������ж����֣�");
	int num;
	scanf("%d", &num);
	if (num <= 0)
	{
		printf("NO");
		return;
	}
	if (Judge(num))
		printf("YES");
	else
		printf("NO");
}

int fcc(int num)//쳲���������,ʱ�临�Ӷ�O(2^n)
{
	if (num == 1 || num == 2)
		return 1;
	else
		return fcc(num - 1) + fcc(num - 2);
}

void test02()
{
	int num = 100;
	printf("%d", fcc(num));
}



void move(char a, char b)
{
	printf("%c --> %c\n", a, b);
}

void Hanoi(char a, char b, char c, int num)//��ŵ����ʱ�临�Ӷ�O(2^n)
{
	if (num == 1)
		move(a, c);
	else
	{
		Hanoi(a, c, b, num - 1);
		move(a, c);
		Hanoi(b, a, c, num - 1);
	}
}

void test09()
{
	int num = 3;//ľ׮����
	char arr[] = "abc";
	Hanoi(arr[0], arr[1], arr[2], num);
}



void Merge_Sort(int* arr, int left, int mid, int right)
{
		/*
		ƽ��ʱ�临�Ӷȣ�O(nlog n)
		���ʱ�临�Ӷȣ�O(n)
		���ʱ�临�Ӷȣ�O(nlogn)
		�ռ临�Ӷȣ�O(n)
		�ȶ��ԣ��ȶ�(����������ֵ���ͬ���֣�����˳�򲻻ύ��)
		*/
	int* brr = NULL;
	int len = right - left + 1;
	brr = (int*)malloc(len * sizeof(int));
	if (!brr)
	{
		perror("malloc");
		exit(-1);
	}
	int L = left;
	int R = mid + 1;
	int pos = 0;
	while (L <= mid && R <= right)
	{
		if (arr[L] < arr[R])
			brr[pos++] = arr[L++];
		else
			brr[pos++] = arr[R++];
	}
	while (L <= mid)
		brr[pos++] = arr[L++];
	while (R <= right)
		brr[pos++] = arr[R++];
	L = left;
	for(int i=0;i<len;i++)
	{
		arr[L++] = brr[i];
	}
	free(brr);
}

void Merge(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	Merge(arr, left, mid);
	Merge(arr, mid + 1, right);
	Merge_Sort(arr, left, mid, right);
}

void test10()
{
	int arr[] = { 1,2,4,2,6,9,12,20,5,32,11,22 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Merge(arr, 0, len - 1);
	for (int i = 0; i < len; i++)
	{
		printf("%d-", arr[i]);
	}
}

