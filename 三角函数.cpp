#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}				//辗转相除法求最大公约数
int main()
{
	int a[3];
	for (int i = 0; i < 3; i++)
		cin >>a[i];
	sort(a, a + 3); //sort是末尾元素的下一个位置
	int t = gcd(a[2], a[0]);
	cout << a[0] / t << "/" << a[2] / t << endl;
	return 0;
}