#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 100005;
const int MOD = 1000000007;
int arr[maxn];
int in_arr[maxn];
int id[maxn];
long long dp[maxn][11];
long long tr[maxn];

int n;

int lowbit(int x)
{
	return x & (-x);
}

void add(int x, long long d)
{
	while (x <= n)
	{
		tr[x] += d;
		tr[x] %= MOD;
		x = x + lowbit(x);
	}
}

long long Sum(int x)
{
	long long ans = 0;
	while (x)
	{
		ans += tr[x];
		ans %= MOD;
		x = x - lowbit(x);
	}
	return ans;
}

int main()
{
	int k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		in_arr[i] = arr[i];
		dp[i][1] = 1;
	}
	if (k == 1)
	{
		cout << n << endl;
		return 0;
	}
	sort(in_arr + 1, in_arr + n + 1);
	for (int i = 1; i <= n; i++)
		id[i] = lower_bound(in_arr + 1, in_arr + n + 1, arr[i]) - in_arr;

	//for (int i = 1; i <= n; i++)
	//	cout << id[i] << " ";
	//cout << endl;


	for (int l = 2; l <= k; l++)
	{
		for (int i = 1; i <= n; i++) tr[i] = 0;
		int ii;
		for (int i = n; i >= 1; i--)
		{
			ii = id[i];
			while (dp[ii][l]) ii++;
			dp[ii][l] = Sum(id[i] - 1);
			add(ii, dp[ii][l - 1]);
		}

		//for (int i = 1; i <= n; i++)
		//	cout << tr[i] << " ";
		//cout << endl;

		//for (int i = 1; i <= n; i++)
		//	cout << dp[i][l] << " ";
		//cout << endl;

	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += dp[i][k];
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}