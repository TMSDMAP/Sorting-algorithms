#include <iostream>
using namespace std;
int main()
{
	int a[20000] = { 0 };
	int N, B;
	cin >> N >> B;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for(int i = 0;i<N-1;i++)
		for(int j = 0;j<N-i-1;j++)
			if (a[j] < a[j + 1])
			{
				int k = a[j];
				a[j] = a[j + 1];
				a[j + 1] = k;
			}
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (sum >= B) { cout << i << endl; break; }
		else
			sum = sum + a[i];
	}
	return 0;
}