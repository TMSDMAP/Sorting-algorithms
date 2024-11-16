#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[1000] = {0};
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		for (int i = 0; i < n; i++)
		{
			if (t == i+1) a[i]++;
		}
	}
	/*for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;*/
	for (int i = 0; i < n; i++)
	{
		while (a[i] != 0)
		{
			cout << i+1<<" ";
			a[i]--;
		}
	}
	return 0;
}