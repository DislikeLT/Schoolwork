#define _CRT_SECURE_NO_WARNINGS  1    //��ֹscanf����

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>


//����


static int n = 3;//��Ʒ����
static int m = 50;//��������
static int w[] = { 10,20,30 };//��Ʒ����
static int p[] = { 60,100,120 };//��Ʒ��ֵ
static int bag_w = 0;//��ǰ��������
static int bag_p = 0;//��ǰ�����ܼ�ֵ
static int* X = (int*)malloc(10 * sizeof(int));//��ǰ���Ž⣬�洢1��0�����л���
static int MAX_p = 0;//��ǰ���ż�ֵ
static int* MAX_X = (int*)malloc(10 * sizeof(int));//ȫ�����Ž�
static int r;//������Ʒ��ֵ

void bag(int i)
{
	if (i > n)
	{
		if (bag_p > MAX_p)
		{
			MAX_p = bag_p;
			for (int j = 1; j <= n; j++)
				MAX_X[j] = X[i];
		}
		return;
	}
	r -= p[i];
	if (bag_w + w[i] <= m)
	{
		X[i] = 1;
		bag_w += w[i];
		bag_p += p[i];
		bag(i + 1);
		bag_w -= w[i];
		bag_p -= p[i];
	}
	if (bag_p + r > MAX_p)
	{
		X[i] = 0;
		bag(i + 1);
	}
	r += p[i];
}

void test09()
{
	for (int i = 0; i < n; i++)
		r += w[i];
	bag(1);
	printf("%d\n", MAX_p);
}

void tsp(int i)
{
	if (i > n)
	{
		int t = citycode(now[n]);
		nowd += d[t][1];
		if (nowd < mind)
		{
			mind = nowd;
			for (int j = 1; j <= n; j++)
				x[j] = nowx[j];
		}
		nowd -= d[t][1];
	}
}