#pragma once

//函数定义

typedef struct//背包问题
{
	int weight;
	int value;
}Items;

typedef struct SElemType//顺序栈
{
	int data[100];
	int top;

}SqStack;

typedef struct StructNode
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

extern int Search(int arr[], int L, int R, int target);

extern bool Judge(int num);

extern void Reversal(char* arr, int L, int len);

extern void Merng(int* arr, int left, int right);

extern void QuickSort(int *arr,int left,int right);

extern void Starck_increase(int arr[], int arr_len);
