#include <iostream>
#include <string>
#include <memory.h>


using namespace std;

long long MAX = 2147483647;
void dijkstra(long long link[256][256], long long chart[256][256])
{
	for (int node = 0; node < 256; node++)
	{
		bool flag[256];
		memset(flag, false, sizeof(bool) * 256);
		chart[node][node] = 0;
		flag[node] = true;
		for (int i = 0; i < 256; i++)
			if (link[node][i] != MAX) chart[node][i] = link[node][i];
		bool q = false;
		for (int i = 0; i < 256; i++)
			if (flag[i] == 0 && chart[node][i] != MAX) q = true;
		while (q)
		{
			long long mini_ind = -1;
			long long mini_val = MAX;
			for (int i = 0; i < 256; i++)
			{
				if ((flag[i] == 0) && (chart[node][i] != MAX && chart[node][i] < mini_val))
				{
					mini_val = chart[node][i];
					mini_ind = i;
				}
			}
			flag[mini_ind] = true;
			for (int i = 0; i < 256; i++)
			{
				if (link[mini_ind][i] != MAX)
					if ((chart[node][i] == MAX) || (chart[node][mini_ind] + link[mini_ind][i] < chart[node][i]))
						chart[node][i] = chart[node][mini_ind] + link[mini_ind][i];
			}
			q = false;
			for (int i = 0; i < 256; i++)
				if (flag[i] == 0 && chart[node][i] != MAX) q = true;
		}
	}
}

int main()
{
	string src;
	long long n;
	string opr;
	char c1, c2;
	long long x;
	long long link[256][256];
	long long chart[256][256];
	for (int i = 0; i < 256; i++)
		for (int j = 0; j < 256; j++)
			link[i][j] = MAX;
	for (int i = 0; i < 256; i++)
		for (int j = 0; j < 256; j++)
			chart[i][j] = MAX;
	cin >> src >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> opr;
		if (opr == "change")
		{
			cin >> c1 >> c2 >> x;
			link[c1][c2] = x;
		}
		if (opr == "add")
		{
			cin >> c1 >> x;
			link[0][c1] = x;
		}
		if (opr == "erase")
		{
			cin >> c1 >> x;
			link[c1][0] = x;
		}
	}

	dijkstra(link, chart);
	//cout << endl;
	//for (int i = 97; i < 102; i++)
	//{
	//	for (int j = 0; j < 256; j++)
	//		cout << chart[i][j] << " ";
	//	cout << endl;
	//}

	long long dp[51][51];
	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 51; j++)
			dp[i][j] = 0;
	long long tmp;
	for (int d = 1; d < src.length(); d++)
	{
		for (int i = 0; i < src.length() - d; i++)
		{
			tmp = MAX;
			int j = i + d;

			for (int k = 0; k < 256; k++)
				if (chart[src[i]][k] + chart[src[j]][k] + dp[i + 1][j - 1] < tmp)
					tmp = chart[src[i]][k] + chart[src[j]][k] + dp[i + 1][j - 1];

			for (int k = 0; k < 256; k++)
				if (chart[src[j]][k] + chart[0][k] + dp[i][j - 1] < tmp)
					tmp = chart[src[j]][k] + chart[0][k] + dp[i][j - 1];

			for (int k = 0; k < 256; k++)
				if (chart[src[i]][k] + chart[0][k] + dp[i + 1][j] < tmp)
					tmp = chart[src[i]][k] + chart[0][k] + dp[i + 1][j];

			dp[i][j] = tmp;
			//cout << endl;
			//for (long long m = 0; m < src.length(); m++)
			//{
			//	for (long long l = 0; l < src.length(); l++)
			//	{
			//		cout << dp[m][l] << " ";
			//	}
			//	cout << endl;
			//}

		}
	}

	if (dp[0][src.length() - 1] != MAX)
		cout << dp[0][src.length() - 1] << endl;
	else
		cout << -1 << endl;
	return 0;
}