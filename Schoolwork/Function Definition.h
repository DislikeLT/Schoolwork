#pragma once

//��������

typedef struct//��������
{
	int weight;
	int value;
}Items;

typedef struct SqStack//˳��ջ
{
	int* base;		//
	int* top;		//
	int StackSize;	//
}SqStack;

typedef struct StructNode//��ջ
{

};


extern void test01();
extern void test02();
extern void test03();
extern void test04();
extern void test05();
extern void test06();
extern void test07();
extern void test08();
extern void test09();
extern void test10();
extern void test11();
extern void test12();

extern int Search(int arr[], int L, int R, int target);//���ֲ���

extern int fcc(int num);//쳲���������

extern void QuickSort(int *arr,int left,int right);//��������

extern void Merge(int* arr, int left, int right);//�鲢����
