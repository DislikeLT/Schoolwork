#define _CRT_SECURE_NO_WARNINGS  1    //∑¿÷πscanf±®¥Ì

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include "Function Definition.h"

//’ª

#define New_StackSize 5

void CreatStack(SqStack* S)//ππ‘Ïø’’ª
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

int StackLength(SqStack S)//’ª≥§∂»
{
	return S.top - S.base;
}

void ClearStack(SqStack* S)//«Âø’’ª
{
	S->top = S->base;
}


void DeleteStack(SqStack* S)//œ˙ªŸ’ª
{
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->StackSize = 0;
}

void PushStack(SqStack* S, int num)//»Î’ª
{
	if (S->top - S->base >= S->StackSize)//’ª¬˙
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

void PopStack(SqStack* S,int *e)//≥ˆ’ª
{
	if (S->top == S->base)
	{
		printf("’ªŒ™ø’£¨Œﬁ∑®…æ≥˝\n");
		return;
	}
	*e = *--S->top;//∑µªÿ’ª∂•‘™Àÿ
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

