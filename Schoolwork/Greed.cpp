#define _CRT_SECURE_NO_WARNINGS  1    //防止scanf报错

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include "Function Definition.h"

//贪心


int compare(const void* a, const void* b)
{
	return   (double)((*(Items*)a).weight) / (double)((*(Items*)a).value) - (double)((*(Items*)b).weight) / (double)((*(Items*)b).value);
}

void test05()//背包问题
{
	printf("输入物品数量：");
	int num;
	scanf("%d", &num);
	Items* brr = NULL;
	brr = (Items*)malloc(num * sizeof(Items));
	if (!brr)
	{
		perror("malloc");
		exit(-1);
	}
	int bag;
	printf("物品重量：");
	for (int i = 0; i < num; i++)
		scanf("%d", &brr[i].weight);
	printf("物品价值：");
	for (int i = 0; i < num; i++)
		scanf("%d", &brr[i].value);
	printf("背包总重：");
	scanf("%d", &bag);
	qsort(brr, num, sizeof(Items), compare);
	int MAX_W = 0, MAX_V = 0;
	for (int i = 0; i < num; i++)
	{
		if ( brr[i].weight + MAX_W <= bag)
		{
			MAX_W += brr[i].weight;
			MAX_V += brr[i].value;
		}
	}
	printf("总重量：%d\n总价值：%d", MAX_W, MAX_V);
}