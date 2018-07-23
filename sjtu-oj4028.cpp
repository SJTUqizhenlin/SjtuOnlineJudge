#include <stdio.h>
using namespace std;

int pic[1005][1005];
int stampi[1000010];
int stampj[1000010];
int stampnum;
int scanned[1005][1005];

void init(int m, int n, int p, int q)
{
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &pic[i][j]);
			scanned[i][j] = 0;
		}
	int tmp;
	stampnum = 0;
	for (int i = 1; i <= p; i++)
		for (int j = 1; j <= q; j++)
		{
			scanf("%d", &tmp);
			if (tmp)
			{
				++stampnum;
				stampi[stampnum] = i;
				stampj[stampnum] = j;
			}
		}
	return;
}

int main()
{
	int T; scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int m, n, p, q;
		scanf("%d%d%d%d", &m, &n, &p, &q);
		init(m, n, p, q);
		if (stampnum == 0)
		{
			int Count_pic = 0;
			for (int i = 1; i <= m; i++)
				for (int j = 1; j <= n; j++)
				{
					Count_pic += pic[i][j];
				}
			if (Count_pic == 0) { printf("Yes\n"); }
			else { printf("No\n"); }
			continue;
		}
		bool flag = true;
		int di, dj;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
				if (pic[i][j] && !scanned[i][j])
				{
					scanned[i][j] = 1;
					for (int k = 1; k <= stampnum; k++)
					{
						di = stampi[k] - stampi[1] + i;
						dj = stampj[k] - stampj[1] + j;
						if (di < 1 || di > m) { flag = false; break; }
						if (dj < 1 || dj > n) { flag = false; break; }
						if (!pic[di][dj]) { flag = false; break; }
						pic[di][dj] = 0;
						scanned[di][dj] = 1;
					}
				}
			if (!flag) break;
		}
		if (!flag) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}