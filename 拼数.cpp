/*
 题目简介
设有n个正整数a1 …an，将它们联接成一排，相邻数字首尾相接，组成一个最大的整数。
输入格式
第一行有一个整数，表示数字个数n。第二行有n 个整数，表示给出的n 个整数ai
 。
输出格式
一个正整数，表示最大的整数*/

/*#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool compare(const string& s1, const string& s2)
{
	int i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] > s2[i]) return true;
		else if (s1[i] < s2[i]) return false;
		i++;
	}
	int j = i;
	if (s1[i])
	{
		if (s1[i] > s2[0])
			return true;
		if (s1[i] < s2[0]) return false;
	}
	if (s2[i])
	{
		if (s2[i] > s1[0])
			return false;
		if (s1[0] > s2[i]) return true;
	}
}    //这个手动实现有漏洞(比如3232321和32,应该是323232321而不是323232132) 只不过数据漏洞依然AC了QAQ
int main()
{
	int n;
	string s[20];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s, s + n, compare);
	for (int i = 0; i < n; i++)
		cout << s[i];
}*/





#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 自定义比较函数：决定排序规则
bool compare(const string& x, const string& y) {
	return x + y > y + x;  // 拼接后比较字典序
}			//666,从未设想的道路

int main() {
	int n;
	cin >> n;
	vector<string> numbers(n);

	// 输入数字，并转为字符串存储
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	// 按自定义规则排序
	sort(numbers.begin(), numbers.end(), compare);

	// 特殊情况：如果排序后的第一个数字是 "0"，那么结果为 "0"
	if (numbers[0] == "0") {
		cout << "0" << endl;
		return 0;
	}

	// 拼接排序后的数字
	string result;
	for (const string& num : numbers) {
		result += num;
	}

	// 输出结果
	cout << result << endl;

	return 0;
}
