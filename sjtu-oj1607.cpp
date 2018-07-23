#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct q_node
{
	int id;
	queue<int> p;
	q_node(int i) :id(i){}
};

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	int rest_front = 0;
	vector<q_node> q;
	unordered_map<int, int> idmap;
	int m;
	cin >> m;
	int order;
	int q_front = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &order);
		if (order == 0)
		{
			if (rest_front == v.size()) continue;
			if (idmap.find(v[rest_front]) == idmap.end())
			{
				idmap[v[rest_front]] = q.size();
				q.push_back(q_node(v[rest_front]));
				q[q.size() - 1].p.push(rest_front + 1);
			}
			else
			{
				if (idmap[v[rest_front]] >= q_front)
					q[idmap[v[rest_front]]].p.push(rest_front + 1);
				else
				{
					idmap[v[rest_front]] = q.size();
					q.push_back(q_node(v[rest_front]));
					q[q.size() - 1].p.push(rest_front + 1);
				}
			}
			rest_front++;
		}
		else
		{
			if (q_front == q.size()) { printf("-1\n"); continue; }
			printf("%d\n", q[q_front].p.front());
			if (q[q_front].p.size() > 1) q[q_front].p.pop();
			else q_front++;
		}
	}
	return 0;
}