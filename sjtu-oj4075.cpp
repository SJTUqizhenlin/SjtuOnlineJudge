#include <stdio.h>
#include <string.h>

using namespace std;

void compute_prefunc(int *arr, char *s)
{
	int m = strlen(s + 1);
	arr[1] = 0;
	int k = 0;
	for (int q = 2; q <= m; q++)
	{
		while (k > 0 && s[k + 1] != s[q])
			k = arr[k];
		if (s[k + 1] == s[q])
			k += 1;
		arr[q] = k;
	}
}

int kmp_matcher(char *src, char *pat)
{
	int n = strlen(src + 1);
	int m = strlen(pat + 1);
	int *prefunc = new int[n + 5];
	for (int i = 0; i < n + 5; i++) prefunc[i] = 0;
	compute_prefunc(prefunc, pat);
	int q = 0;
	for (int i = 1; i <= n; i++)
	{
		while (q > 0 && pat[q + 1] != src[i])
			q = prefunc[q];
		if (pat[q + 1] == src[i])
			q += 1;
		if (q == m) return i - m;
		//if (q == m) { printf("%d ", i - m); q = prefunc[q]; }
	}
}

int main()
{
	char src[1000005];
	char pat[100005];
	src[0] = '0';
	pat[0] = '0';
	scanf("%s", &src[1]);
	scanf("%s", &pat[1]);
	printf("%d\n", kmp_matcher(src, pat));
	return 0;
}
