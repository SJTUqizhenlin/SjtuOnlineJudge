#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

string s;
stack<int> stk;
unordered_map<int, unordered_set<int> > uomap;
priority_queue<int, vector<int>, cmp> pq;


void link_node(int a, int b)
{
	//cout << "linking" << a << " and " << b << endl;
	uomap[a].insert(b);
	uomap[b].insert(a);
	return;
}

void extract_num()
{
	int pos = 0;
	int tmp = 0;
	int len = s.length();
	int a, b;
	while (pos < len)
	{
		if (s[pos] >= '0' && s[pos] <= '9')
		{
			while (s[pos] >= '0' && s[pos] <= '9' && pos < len)
			{
				tmp = tmp * 10 + s[pos] - '0';
				pos++;
			}
			stk.push(tmp);
			tmp = 0;
		}
		else
		{
			if (s[pos] == ')')
			{
				a = stk.top();
				stk.pop();
				if (stk.empty()) break;
				b = stk.top();
				link_node(a, b);
			}
			pos++;
		}
	}
	return;
}

int main()
{
	getline(cin, s);
	extract_num();
	unordered_map<int, unordered_set<int> >::iterator it;
	for (it = uomap.begin(); it != uomap.end(); it++)
		if (it->second.size() == 1)
			pq.push(it->first);
	int mapsize = uomap.size();
	int curtop;
	int nextnum;
	for (int i = 1; i < mapsize; i++)
	{
		curtop = pq.top();
		pq.pop();
		nextnum = *(uomap[curtop].begin());
		printf("%d ", nextnum);
		uomap.erase(curtop);
		uomap[nextnum].erase(curtop);
		if (uomap[nextnum].size() == 1) pq.push(nextnum);
	}
	printf("\n");
	return 0;
}