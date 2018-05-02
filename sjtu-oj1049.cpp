#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int T, N, M, tmpint;
	cin >> T;
	stack<int> stk;
	queue<int> q;
	for (int i = 0; i < T; i++)
	{
		scanf("%d%d", &N, &M);
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &tmpint);
			q.push(tmpint);
		}
		for (int j = 0; j < N; j++)
		{
			stk.push(j);
			while (!stk.empty() && !q.empty())
			{
				if (stk.top() == q.front())
				{
					stk.pop();
					q.pop();
				}
				else break;
			}
			if (stk.size() > M)
				break;
		}
		if (q.empty()) printf("YES\n");
		else printf("NO\n");
		while (!stk.empty()) stk.pop();
		while (!q.empty()) q.pop();
	}
	return 0;
}