/*
* 题目描述
将读入的 N 个数从小到大排序后输出。
输入格式
第一行为一个正整数 N 。
第二行包含 N 个空格隔开的正整数 ai，为你需要进行排序的数。
输出格式
将给定的 N 个数从小到大输出，数之间空格隔开，行末换行且无空格。
*/
/*#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>  // 用于rand函数
using namespace std;

int N;
int arr[100000];

// 霍尔分区函数
int hoarePartition(int arr[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1); 
     // 随机选择基准
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[low]);  // 将基准放到起始位置
    int keyi = low;

    while (low<high) {
        // 从左往右找大于等于 pivot 的元素
        while (low<high && arr[high]>=arr[keyi]) high--;

        // 从右往左找小于等于 pivot 的元素
        while (low < high && arr[low] <= arr[keyi]) low++;
        if (low >= high) return low;

        // 交换 arr[i] 和 arr[j]
        if(low<high)
        swap(arr[low], arr[high]);
    }
    swap(arr[keyi], arr[low]);
    keyi = low;
    return keyi;
}

// 快速排序主函数
void qsort(int arr[], int low, int high) {
    if (low >= high) return;
        int q = hoarePartition(arr, low, high);  // 霍尔分区
        qsort(arr, low, q);         // 排序左半部分
        qsort(arr, q + 1, high);    // 排序右半部分
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    qsort(arr, 0, N - 1);  // 调用快速排序

    printf("%d", arr[0]);
    for (int i = 1; i < N; i++)
        printf(" %d", arr[i]);
    printf("\n");

    return 0;
}*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>  // 用于rand函数
using namespace std;

int N;
int arr[100000];

// 霍尔分区函数
int hoarePartition(int arr[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);  // 随机选择基准
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[low]);  // 将基准放到起始位置

    int i = low - 1;
    int j = high + 1;

    while (true) {
        // 从左往右找大于等于 pivot 的元素
        do {
            i++;
        } while (arr[i] < pivot);

        // 从右往左找小于等于 pivot 的元素
        do {
            j--;
        } while (arr[j] > pivot);

        // 两指针相遇，返回分界点
        if (i >= j)
            return j;

        // 交换 arr[i] 和 arr[j]
        swap(arr[i], arr[j]);
    }
}               //这种排序方式要比上面那中高效不少

// 快速排序主函数
void qsort(int arr[], int low, int high) {
    if (low < high) {
        int q = hoarePartition(arr, low, high);  // 霍尔分区
        qsort(arr, low, q-1);         // 排序左半部分,q这个元素是需要再次比较的!!!
        qsort(arr, q + 1, high);    // 排序右半部分
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    qsort(arr, 0, N - 1);  // 调用快速排序

    printf("%d", arr[0]);
    for (int i = 1; i < N; i++)
        printf(" %d", arr[i]);
    printf("\n");

    return 0;
}


