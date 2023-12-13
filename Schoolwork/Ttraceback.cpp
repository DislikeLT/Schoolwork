#define _CRT_SECURE_NO_WARNINGS  1    //防止scanf报错

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>


//回溯


static int n = 3;//物品数量
static int m = 50;//背包总重
static int w[] = { 10,20,30 };//物品重量
static int p[] = { 60,100,120 };//物品价值
static int bag_w = 0;//当前背包总重
static int bag_p = 0;//当前背包总价值
static int* X = (int*)malloc(10 * sizeof(int));//当前最优解，存储1或0代表行或不行
static int MAX_p = 0;//当前最优价值
static int* MAX_X = (int*)malloc(10 * sizeof(int));//全局最优解
static int r;//可用物品价值

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

