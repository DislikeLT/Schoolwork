#pragma once

//��������

typedef struct
{
	int weight;
	int value;
}Items;


extern void test01();
extern void test02();
extern void test03();
extern void test04();
extern void test05();
extern void test06();
extern void test07();

extern int Search(int arr[], int L, int R, int target);

extern bool Judge(int num);

extern void Reversal(char* arr, int L, int len);

extern void Merng(int* arr, int left, int right);

extern void QuickSort(int *arr,int left,int right);