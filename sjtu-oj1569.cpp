#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int lowbit(int x)
{
	return x & (-x);
}

void Update(int *tr, int no, int num, int MAX)
{
	while (no <= MAX)
	{
		tr[no] += num;
		no += lowbit(no);
	}
}

int Sum(int *tr, int no)
{
	int res = 0;
	while (no)
	{
		res += tr[no];
		no -= lowbit(no);
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	int *tr = new int[N + 1];
	for (int i = 0; i <= N; i++)
		tr[i] = 0;
	int tmp;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &tmp);
		Update(tr, i, tmp, N);
	}
	string order;
	int x, y;
	cin >> order;
	while (order != "end")
	{
		scanf("%d%d", &x, &y);
		if (order == "inc")
		{
			Update(tr, x, y, N);
		}
		if (order == "dec")
		{
			Update(tr, x, -y, N);
		}
		if (order == "query")
		{
			printf("%d\n", Sum(tr, y) - Sum(tr, x - 1));
		}
		cin >> order;
	}
	return 0;
}