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

void Reversal(char* arr, int L, int len)//��ת�ַ���
{
	if (L >= (len / 2))
		return;
	char sum = arr[L];
	arr[L] = arr[len - L - 1];
	arr[len - L - 1] = sum;
	Reversal(arr, ++L, len);
}

void test02()
{
	char arr[] = "asdfg1234";
	int len = strlen(arr);
	Reversal(arr, 0, len);
	printf("%s", arr);
}


