#include <iostream>
using namespace std;
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define MAXHLTH 31010
#define NEGINF -(1 << 15)

struct act
{
	int dh, dw;
	act() :dh(0), dw(0) {};
};

int dp[405][MAXHLTH + 1000];
act acts[405];
int n;
int curMaxw;

void init()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
		cin >> acts[i].dh >> acts[i].dw;
	return;
}

void build()
{
	for (int i = 0; i < 405; i++)
		for (int j = 0; j < MAXHLTH + 1000; j++) dp[i][j] = NEGINF;
	dp[0][acts[0].dh] = acts[0].dw;
	curMaxw = acts[0].dh;
	for (int i = 1; i <= n; i++)
	{
		curMaxw += (acts[i].dh > 0 ? acts[i].dh : 0);
		for (int j = 0; j <= curMaxw; j++)
		{
			if (j >= acts[i].dh && dp[i - 1][j - acts[i].dh] > NEGINF)
				dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - acts[i].dh] + acts[i].dw);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return;
}

void getRes()
{
	int res = 0;
	for (int j = 1; j <= curMaxw; j++)
		if (dp[n][j] > 70)
			res = Max(res, dp[n][j] * j);
	if (res) cout << res << endl;
	else cout << "Death" << endl;
	return;
}

int main()
{
	init();
	build();
	getRes();
	return 0;
}
