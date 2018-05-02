#include <iostream>
#include <stdio.h>
#include <queue>
#include <limits.h>

using namespace std;

struct Pair
{
	long long w_time;
	long long t_time;
	Pair(long long a, long long b)
	{
		w_time = a;
		t_time = b;
	}
};

Pair func1(int *m, int N)
{
	long long w_time = 0;
	long long t_time = 0;
	queue<long long> q[3];
	for (int i = 0; i < N; i++)
		q[i % 3].push(m[i]);
	for (int i = 0; i < 3; i++)
		q[i].push(LLONG_MAX);
	int count = 0;

	while (count < N)
	{
		long long fast = LLONG_MAX;
		for (int i = 0; i < 3; i++)
			if (q[i].front() < fast) fast = q[i].front();
		t_time += fast;
		for (int i = 0; i < 3; i++)
			if (q[i].size() > 2) 
				w_time += (q[i].size() - 2) * fast;
		for (int i = 0; i < 3; i++)
		{
			q[i].front() -= fast;
			if (q[i].front() == 0)
			{
				q[i].pop();
				count += 1;
			}
		}
	}

	Pair ans(w_time, t_time);
	return ans;
}

Pair func2(int *m, int N)
{
	long long w_time = 0;
	long long t_time = 0;
	queue<long long> q;
	for (int i = 0; i < N; i++)
		q.push(m[i]);
	for (int i = 0; i < 3; i++)
		q.push(LLONG_MAX);
	long long win[3];
	for (int i = 0; i < 3; i++)
	{
		win[i] = q.front();
		q.pop();
	}
	int count = 0;
	int rest = N - 3;

	while (count < N)
	{
		long long fast = LLONG_MAX;
		for (int i = 0; i < 3; i++)
			if (win[i] < fast) fast = win[i];
		t_time += fast;
		if (rest > 0) w_time += (fast * rest);
		for (int i = 0; i < 3; i++)
		{
			win[i] -= fast;
			if (win[i] == 0)
			{
				rest -= 1;
				count += 1;
				win[i] = q.front();
				q.pop();
			}
		}
	}

	Pair ans(w_time, t_time);
	return ans;
}

int main()
{
	int N;
	cin >> N;
	int *m = new int[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &m[i]);
	Pair ans1 = func1(m, N);
	Pair ans2 = func2(m, N);
	cout << ans1.w_time << " " << ans1.t_time << endl;
	cout << ans2.w_time << " " << ans2.t_time << endl;
	return 0;
}