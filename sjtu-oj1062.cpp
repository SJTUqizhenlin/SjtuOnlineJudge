#include <stdio.h>
#include <memory.h>

using namespace std;

int search(int *dp, int tar, int l, int r)
{
	if (r == l) return l;
	int mid = (l + r) / 2;
	if (dp[mid] >= tar) return search(dp, tar, l, mid);
	else return search(dp, tar, mid + 1, r);
}

void fillin(int *h, int *leng, int *dp, int n)
{
	int cur_len = 0;
	for (int i = 0; i < n; i++)
	{
		int pos = search(dp, h[i], 0, cur_len);
		dp[pos] = h[i];
		if (pos == cur_len)
			cur_len++;
		leng[i] = cur_len;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int *h = new int[n];
	int *rev_h = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &h[i]);
		rev_h[n - 1 - i] = h[i];
	}
	int *dp1 = new int[n];
	int *dp2 = new int[n];
	int *for_len = new int[n];
	int *bac_len = new int[n];
	
	memset(dp1, 0, sizeof(int) * n);
	memset(for_len, 0, sizeof(int) * n);
	fillin(h, for_len, dp1, n);
	
	memset(dp2, 0, sizeof(int) * n);
	memset(bac_len, 0, sizeof(int) * n);
	fillin(rev_h, bac_len, dp2, n);

	int ans = 0;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = for_len[i] + bac_len[n - 1 - i] - 1;
		if (tmp > ans) ans = tmp;
	}
	ans = n - ans;
	printf("%d\n", ans);

	//for (int i = 0; i < n; i++)
	//	printf("%d ", dp1[i]);
	//printf("\n");

	//for (int i = 0; i < n; i++)
	//	printf("%d ", dp2[i]);
	//printf("\n");

	//for (int i = 0; i < n; i++)
	//	printf("%d ", for_len[i]);
	//printf("\n");

	//for (int i = 0; i < n; i++)
	//	printf("%d ", bac_len[i]);
	//printf("\n");

	return 0;
}