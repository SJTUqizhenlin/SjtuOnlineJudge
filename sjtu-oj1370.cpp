#include <stdio.h>
using namespace std;

int res[170][50][170];

int getRes(int a, int b, int mini)
{
	if (res[a][b][mini])
		return res[a][b][mini];
	if (b == 1)
	{
		if (a == mini)
			return res[a][b][mini] = 1;
		else
			return res[a][b][mini] = 0;	
	}
	int maxi = (a - mini) / (b - 1);
	int ans = 0;
	for (int i = mini; i <= maxi; i++)
		ans += getRes(a - mini, b - 1, i);
	return res[a][b][mini] = ans;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		for (int i = 0; i <= a; i++)
			for (int j = 0; j <= b; j++)
				for (int k = 0; k <= a; k++)
					res[i][j][k] = 0;
		int ans = 0, maxi = a / b;
		for (int i = 1; i <= maxi; i++)
			ans += getRes(a, b, i);
		printf("%d\n", ans);
	}
	return 0;
}