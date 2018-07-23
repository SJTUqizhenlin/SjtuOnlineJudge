#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

map<int, priority_queue<int> > mp;

int main()
{
	int n; scanf("%d", &n);
	int a, b, c;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a == 1)
		{
			scanf("%d%d", &b, &c);
			mp[b].push(c);
		}
		if (a == 2)
		{
			scanf("%d", &b);
			mp[b].pop();
		}
		if (a == 3)
		{
			scanf("%d", &b);
			printf("%d\n", mp[b].top());
		}
	}
	return 0;
}