#include <iostream>
#include <cstring>
using namespace std;



int W, H;
unsigned long long cnt = 1;
unsigned long long dp[30][1 << 12];

void build_line(int line, int from, int cur) {
	if (cur == W) {
		dp[line][from] += cnt;
		return;
	}
	build_line(line, from, cur + 1);
	if (cur <= W - 2 
		&& !(from & (1 << cur)) 
		&& !(from & (1 << (cur + 1)))  
		) {
		int next = from | (1 << cur) | (1 << (cur + 1));
		build_line(line, next, cur + 2);
	}
	return;
}


int main(int argc, char const *argv[])
{
	while (1) {
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;
		if (W > H) {
			int t; t = W; W = H; H = t;
		}

		if (W*H % 2 == 1) {
			cout << 0 << endl;
			continue;
		}

		memset(dp, 0, sizeof(dp));
		cnt = 1;
		build_line(1, 0, 0); 
		for (int i = 2; i <= H; ++i)
		{
			for (int j = 0; j < (1 << W); ++j)
			{
				if (dp[i - 1][j] > 0) {
					cnt = dp[i - 1][j];
				}
				else
					continue;
				build_line(i, (~j) & ((1 << W) - 1), 0);
			}
		}
		cout << dp[H][((1 << W) - 1)] << endl;
	}
	return 0;
}