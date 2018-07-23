#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct student
{
	long long g;
	long long w;
	student() :g(0), w(0) {}
	student(long long ig, long long iw) :g(ig), w(iw) {}
};

bool cmp1(const student& s1, const student&s2)
{
	return (s1.w - s1.g) > (s2.w - s2.g);
}

bool cmp2(const student& s1, const student& s2)
{
	return s1.g < s2.g;
}

int main()
{
	long long n, grade, weight;
	cin >> n >> grade >> weight;
	long long g, w;
	vector<student> pre;
	vector<student> suc;
	for (int i = 1; i <= n - 1; i++)
	{
		scanf("%lld%lld", &g, &w);
		if (g > grade) pre.push_back(student(g, w));
		else suc.push_back(student(g, w));
	}
	make_heap(pre.begin(), pre.end(), cmp1);
	sort(suc.begin(), suc.end(), cmp2);
	int res = pre.size();
	while (true)
	{
		if (res > pre.size()) res = pre.size();
		if (pre.empty()) break;
		grade -= (pre[0].w - pre[0].g + 1);
		if (grade < 0) break;
		pop_heap(pre.begin(), pre.end(), cmp1); pre.pop_back();
		while (!suc.empty() && suc[suc.size() - 1].g > grade)
		{
			pre.push_back(suc[suc.size() - 1]);
			suc.pop_back();
			push_heap(pre.begin(), pre.end(), cmp1);
		}
	}
	cout << res + 1 << endl;
	return 0;
}