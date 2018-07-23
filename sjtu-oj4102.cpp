#include <string>
#include <stdio.h>
#include <queue>

#define ll long long
using namespace std;

#define max(a, b) (a > b ? a : b);

int read()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x;
}

int l, K, n, ans = 1;
ll a[3000005];

struct myData {
	int pos; ll val;
	myData(int a, ll b) :pos(a), val(b) {}
	bool operator<(const myData &b) const
	{
		return val < b.val;
	}
};

priority_queue<myData> q1, q2;

void solve()
{
	int l = 1;
	for (int i = 1; i <= n; i++)
	{
		q1.push(myData(i, a[i]));
		q2.push(myData(i, -a[i]));
		while (q1.top().val + q2.top().val > K)
		{
			l++;
			while (!q1.empty() && q1.top().pos<l)q1.pop();
			while (!q2.empty() && q2.top().pos<l)q2.pop();
		}
		ans = max(ans, i - l + 1);
	}
}

int main()
{
	K = read(); n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	solve();
	printf("%d\n", ans);
	return 0;
}