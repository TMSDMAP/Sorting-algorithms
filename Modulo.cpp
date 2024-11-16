#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
		a[i] = a[i];
	}
	for (int i = 0; i < 10; i++)
	{
		while (a[i] / 42 != 0)
			a[i] = a[i] % 42;
	}
	int count = 0;
	sort(a, a + 10);
	count = 1;
	for (int i = 1; i < 10; i++)
	{
		if (a[i] != a[i - 1]) count++;
	}
	cout << count << endl;
	return 0;
}