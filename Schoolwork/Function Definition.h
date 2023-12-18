#pragma once

//函数定义

typedef struct//背包问题
{
	int weight;
	int value;
}Items;

typedef struct SqStack//顺序栈
{
	int* base;		//
	int* top;		//
	int StackSize;	//
}SqStack;

typedef struct StructNode//链栈
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

extern int Search(int arr[], int L, int R, int target);//二分查找

extern int fcc(int num);//斐波那契数列

extern void QuickSort(int *arr,int left,int right);//快速排序

extern void Merge(int* arr, int left, int right);//归并排序
