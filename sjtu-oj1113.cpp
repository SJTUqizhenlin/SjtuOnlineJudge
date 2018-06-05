#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct stu
{
	int grade;
	int schol;
	stu()
		:grade(0), schol(0) {}
	stu(int g, int s)
		:grade(g), schol(s) {}
};

bool cmp(const stu &s1, const stu &s2)
{
	return s1.grade < s2.grade;
}

bool cmp2(const stu &s1, const stu &s2)
{
	return s1.schol < s2.schol;
}

int main()
{
	int n, c, f;
	cin >> n >> c >> f;
	stu *arr = new stu[c];
	for (int i = 0; i < c; i++)
		scanf("%d%d", &arr[i].grade, &arr[i].schol);
	sort(arr, arr + c, cmp);
	long long *minisum1 = new long long[c];
	long long *minisum2 = new long long[c];
	int half = n >> 1;
	stu *maxheap = new stu[half];
	
	int cur = 0;
	minisum1[half - 1] = 0;
	for (; cur < half; cur++)
	{
		maxheap[cur] = arr[cur];
		minisum1[half - 1] += maxheap[cur].schol;
	}
	make_heap(maxheap, maxheap + half, cmp2);
	for (; cur < c; cur++)
	{
		minisum1[cur] = minisum1[cur - 1];
		if (arr[cur].schol < maxheap[0].schol)
		{
			minisum1[cur] -= maxheap[0].schol;
			minisum1[cur] += arr[cur].schol;
			pop_heap(maxheap, maxheap + half, cmp2);
			maxheap[half - 1] = arr[cur];
			push_heap(maxheap, maxheap + half, cmp2);
		}
	}
	
	cur = c - 1;
	minisum2[c - half] = 0;
	for (; cur >= c - half; cur--)
	{
		maxheap[c - 1 - cur] = arr[cur];
		minisum2[c - half] += maxheap[c - 1 - cur].schol;
	}
	make_heap(maxheap, maxheap + half, cmp2);
	for (; cur >= 0; cur--)
	{
		minisum2[cur] = minisum2[cur + 1];
		if (arr[cur].schol < maxheap[0].schol)
		{
			minisum2[cur] -= maxheap[0].schol;
			minisum2[cur] += arr[cur].schol;
			pop_heap(maxheap, maxheap + half, cmp2);
			maxheap[half - 1] = arr[cur];
			push_heap(maxheap, maxheap + half, cmp2);
		}
	}

	for (int i = c - half - 1; i > half - 1; i--)
	{
		if (minisum1[i - 1] + minisum2[i + 1] + arr[i].schol <= f)
		{
			cout << arr[i].grade << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}