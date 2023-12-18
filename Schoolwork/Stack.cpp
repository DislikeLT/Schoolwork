#define _CRT_SECURE_NO_WARNINGS  1    //��ֹscanf����

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include "Function Definition.h"

//ջ

#define New_StackSize 5

void CreatStack(SqStack* S)//�����ջ
{
	S->base = (int*)malloc(10 * sizeof(int));
	if (!S->base)
	{
		perror("malloc");
		exit(-1);
	}
	S->top = S->base;
	S->StackSize = 10;
}

int StackLength(SqStack S)//ջ����
{
	return S.top - S.base;
}

void ClearStack(SqStack* S)//���ջ
{
	S->top = S->base;
}


void DeleteStack(SqStack* S)//����ջ
{
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->StackSize = 0;
}

void PushStack(SqStack* S, int num)//��ջ
{
	if (S->top - S->base >= S->StackSize)//ջ��
	{
		S->base = (int*)realloc(S->base, (S->StackSize + New_StackSize) * sizeof(int));
		if (!S->base)
		{
			perror("realloc");
			exit(-1);
		}
		S->top = S->base + S->StackSize;
		S->StackSize += New_StackSize;
	}
	*(S->top)++ = num;
}

void PopStack(SqStack* S,int *e)//��ջ
{
	if (S->top == S->base)
	{
		printf("ջΪ�գ��޷�ɾ��\n");
		return;
	}
	*e = *--S->top;//����ջ��Ԫ��
	return;

}


void StackTraverse(SqStack S, void(*visit)(int))
{
	while (S.top > S.base)
		visit(*S.base++);
	printf("\n");
}

void test08()
{
	SqStack S;
	CreatStack(&S);

	int a = 10;
	int b = 20;
	int c = 30;
	PushStack(&S, a);
	PushStack(&S, b);
	PushStack(&S, c);


	int e;
	PopStack(&S, &e);
	printf("%d", e);
}

