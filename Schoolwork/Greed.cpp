#define _CRT_SECURE_NO_WARNINGS  1    //��ֹscanf����

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include "Function Definition.h"

//̰��


int compare(const void* a, const void* b)
{
	return   (double)((*(Items*)a).weight) / (double)((*(Items*)a).value) - (double)((*(Items*)b).weight) / (double)((*(Items*)b).value);
}

void test05()//��������
{
	printf("������Ʒ������");
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
	printf("��Ʒ������");
	for (int i = 0; i < num; i++)
		scanf("%d", &brr[i].weight);
	printf("��Ʒ��ֵ��");
	for (int i = 0; i < num; i++)
		scanf("%d", &brr[i].value);
	printf("�������أ�");
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
	printf("��������%d\n�ܼ�ֵ��%d", MAX_W, MAX_V);
}