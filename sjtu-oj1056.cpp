#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

struct comp
{
	bool operator()(const int a, const int b) const
	{
		return a > b;
	}
};

int parent[500001];
int height[500001];
int num_of[500001];
multiset<int, comp> mset;

int find_par(int x)
{
	if (parent[x] == x || parent[x] == -1)
		return parent[x];
	else
	{
		parent[x] = find_par(parent[x]);
		return parent[x];
	}
}

int count_in(int x)
{
	if (find_par(x) != -1)
	{
		num_of[x] = num_of[parent[x]];
		return num_of[x];
	}
	else return 0;
}

void unite(int x, int y)
{
	if (find_par(x) == find_par(y)) return;
	if (parent[x] == -1 || parent[y] == -1) return;
	if (height[parent[x]] < height[parent[y]])
	{
		num_of[parent[y]] += num_of[parent[x]];
		parent[parent[x]] = parent[y];
	}
	else
	{
		num_of[parent[x]] += num_of[parent[y]];
		if (height[parent[x]] == height[parent[y]])
			height[parent[x]]++;
		parent[parent[y]] = parent[x];
	}
	return;
}

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		height[i] = 1;
		num_of[i] = 1;
		mset.insert(1);
	}
	char op;
	int x, y, sum;
	multiset<int, comp>::iterator it;
	vector<int> top10;
	for (int i = 0; i < M; i++)
	{
		scanf("\n%c", &op);
		if (op == 'C')
		{
			scanf("%d%d", &x, &y);
			if (find_par(x) > 0 && find_par(y) > 0)
			{
				if (parent[x] != parent[y])
				{
					sum = count_in(x) + count_in(y);
					it = mset.find(num_of[x]);
					if (it != mset.end())
						mset.erase(it);
					it = mset.find(num_of[y]);
					if (it != mset.end())
						mset.erase(it);
					mset.insert(sum);
				}
			}
			unite(x, y);
		}
		if (op == 'D')
		{
			scanf("%d", &x);
			if (find_par(x) > 0)
			{
				it = mset.find(num_of[parent[x]]);
				if (it != mset.end())
					mset.erase(it);
				num_of[parent[x]] = 0;
				parent[parent[x]] = -1;
			}
		}
		if (op == 'Q')
		{
			scanf("%d", &x);
			for (int j = 0; j < 10; j++)
			{
				if (mset.empty()) break;
				top10.push_back(*mset.begin());
				mset.erase(mset.begin());
			}
			if (top10.size() < x)
			{
				printf("%d\n", 0);
			}
			else
			{
				printf("%d\n", top10[x - 1]);
			}
			for (int j = 0; j < top10.size(); j++)
				mset.insert(top10[j]);
			top10.clear();
		}
	}
	return 0;
}