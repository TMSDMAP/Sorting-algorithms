/*
* 题目描述
将读入的 N 个数从小到大排序后输出。
输入格式
第一行为一个正整数 N 。
第二行包含 N 个空格隔开的正整数 ai，为你需要进行排序的数。
输出格式
将给定的 N 个数从小到大输出，数之间空格隔开，行末换行且无空格。
*/
//Lomuto法效率比Hoare慢,这种大数据题不如用Hoare,用LomutoAC不了
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int N;
int arr[100000];
int partition(int arr[], int low, int high)
{
	int mid = low + (high - low) / 2;
	//int pivotindex = low + rand() % (high - low + 1);
	int pivot = arr[mid];
	swap(arr[high], arr[mid]);   //Lomuto前后指针是把基准元素放到high位置上来比较
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}
void qsort(int arr[],int low,int high)
{
	if (low >= high) return;
	if (low < high)			//注意条件是<不是<=
	{
		int q = partition(arr, low, high);
		qsort(arr, low, q - 1);
		qsort(arr, q + 1, high);
	}
}
int main()
{
	
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
		scanf("%d",&arr[i]);
	qsort(arr, 0, N - 1);
	printf("%d",arr[0]);
	for (int i = 1; i < N; i++)
		printf(" %d",arr[i]);
	printf("\n");
}