#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int n;
	int a[1000];
	int diff[1000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
	{
		diff[i] = abs(a[i] - a[i + 1]);
	}
	int flag = 0;
	sort(diff, diff + n - 1);
	for (int i = 0; i < n - 1; i++)
		if (diff[i] != i + 1) {
			flag = 1; break;
		}
	if (flag == 0) cout << "Jolly";
	else cout << "Not jolly";
	return 0;
}
