#include <iostream>
#include <stdio.h>
#include <deque>

using namespace std;

int N, K;

int main()
{
	cin >> N >> K;
	int res = 0;
	int *ele = new int[N + K];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &ele[i]);
		if (i < K) ele[N + i] = ele[i];
		if (ele[i] > res) res = ele[i];
	}
	deque<int> q;
	deque<int> q1;
	q.push_back(ele[0]);
	q1.push_back(0);
	for (int i = 1; i < N + K; i++)
	{
		if (i - q1.front() >= K)
		{
			q.pop_front();
			q1.pop_front();
		}
		while (q.size() >= 1 && q.back() <= ele[i])
		{
			q.pop_back();
			q1.pop_back();
		}
		q.push_back(ele[i]);
		q1.push_back(i);
		if (i >= K - 1)
		{
			if (q.front() < res) res = q.front();
		}
	}
	cout << res << endl;
	return 0;
}