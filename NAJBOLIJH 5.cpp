#include <iostream>
#include <algorithm>
using namespace std;
#define N 8
struct Number {
	int data;
	int id;
};
int main()
{
	Number a[8];
	for (int i = 0; i < N; i++)
	{
		cin >> a[i].data;
		a[i].id = i + 1;
	}
	int k;
	for (int i = 0; i < N-1; i++)
	{
		k = i;
		for (int j = i + 1; j < N; j++)
		{
			if (a[j].data > a[k].data) {
				k = j;
			}
		}
		Number q = a[i];
		a[i] = a[k];
		a[k] = q;
	}
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += a[i].data;
	}
	cout << sum << endl;
	int ID[5];
	for (int i = 0; i < 5; i++)
		ID[i] = a[i].id;
	sort(ID, ID + 5);
	cout << ID[0];
	for (int i = 1; i < 5; i++)
		cout << " " << ID[i];
	cout << endl;

}