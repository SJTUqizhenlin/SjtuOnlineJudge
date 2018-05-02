#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct comp
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

struct girl_group
{
	priority_queue<int, vector<int>, comp> pq;
	girl_group(int ele)
	{
		pq.push(ele);
	}
	void delete_min()
	{
		pq.pop();
	}
	void add_in(int new_one)
	{
		pq.push(new_one);
	}
	void merge_with(girl_group &another)
	{
		int tmp;
		while (!another.pq.empty())
		{
			tmp = another.pq.top();
			this->add_in(tmp);
			another.pq.pop();
		}
	}
};

int main()
{
	int N, M;
	cin >> N >> M;
	vector<girl_group> v;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		v.push_back(girl_group(tmp));
	}
	int order, num1, num2;
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &order);
		if (order == 0)
		{
			scanf("%d%d", &num1, &num2);
			v[num1].merge_with(v[num2]);
		}
		if (order == 1)
		{
			scanf("%d", &num1);
			if (v[num1].pq.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", v[num1].pq.top());
				v[num1].delete_min();
			}
		}
		if (order == 2)
		{
			scanf("%d%d", &num1, &num2);
			v[num1].add_in(num2);
		}
	}
	return 0;
}