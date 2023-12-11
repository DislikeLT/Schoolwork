#define _CRT_SECURE_NO_WARNINGS  1    //防止scanf报错

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

//动态规划


void LCS(char X[], char Y[], char* Z)//最长公共子序列(不是子数组)
{
	int X_len = strlen(X);
	int Y_len = strlen(Y);
	int** arr = NULL;
	arr = (int**)malloc((X_len + 1) * sizeof(int*));
	if (arr == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	for (int i = 0; i < X_len + 1; i++)
	{
		arr[i] = (int*)malloc((Y_len + 1) * sizeof(int));
		if (arr[i] == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		memset(arr[i], 0, (Y_len + 1) * sizeof(int));
	}
	
	for (int i = 1; i <= X_len; i++)
	{
		for (int j = 1; j <= Y_len; j++)
		{
			if (X[i - 1] == Y[j - 1])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = fmax(arr[i - 1][j], arr[i][j - 1]);
		}
	}
	for (int i = 0; i <= X_len; i++)
	{
		for (int j = 0; j <= Y_len; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	int MAX = arr[X_len][Y_len];
	int i = X_len;
	int j = Y_len;
	int Z_len = 0;
	while (i >= 1)
	{
		if (arr[i][j - 1] == MAX)
			j--;
		else if (arr[i - 1][j] == MAX)
			i--;
		else
		{
			Z[Z_len++] = X[i - 1];
			MAX = arr[--i][--j];
		}
	}
}

void test06()
{
	char X[] = "BACDCA";
	char Y[] = "ABDCA";
	char Z[100] = "";
	LCS(X, Y,Z);
	printf("%s", Z);
}





void test07()
{

}