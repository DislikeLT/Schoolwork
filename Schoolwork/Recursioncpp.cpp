#define _CRT_SECURE_NO_WARNINGS  1    //防止scanf报错

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

//递归


bool Judge(int num)//判断某数是否为2的幂次方
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
	printf("请输入判断数字：");
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

void Reversal(char* arr, int L, int len)//反转字符串
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


