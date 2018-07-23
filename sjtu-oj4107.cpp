#include <stdio.h>
#include <string.h>
using namespace std;

char P[10000005];
char S[10000005];
int m, n;
int kmparr[10000005];
int fst, Count;

void find_kmparr(char *P)
{
	kmparr[1] = 0;
	int k = 0;
	for (int q = 2; q <= m; q++)
	{
		while (k > 0 && P[q] != P[k + 1])
			k = kmparr[k];
		if (P[k + 1] == P[q]) k++;
		kmparr[q] = k;
	}
	return;
}

void kmp_find(char *P, char *S)
{
	find_kmparr(P);
	int q = 0;
	for (int i = 1; i <= n; i++)
	{
		while (q > 0 && P[q + 1] != S[i])
			q = kmparr[q];
		if (P[q + 1] == S[i]) q++;
		if (q == m)
		{
			if ((Count++) == 0) fst = i - m;
			q = kmparr[q];
		}
	}
	return;
}

int main()
{
	char e; S[0] = P[0] = '#';
	scanf("%[^\n]", &P[1]);
	scanf("%c", &e);
	scanf("%[^\n]", &S[1]);
	m = strlen(&P[1]);
	n = strlen(&S[1]);
	for (int i = 1; i <= m; i++)
		if (P[i] >= 'a') P[i] = (char)(P[i] - 32);
	for (int i = 1; i <= n; i++)
		if (S[i] >= 'a') S[i] = (char)(S[i] - 32);
	fst = -1; Count = 0;
	kmp_find(P, S);
	if (Count) printf("%d %d\n", Count, fst);
	else printf("-1\n");
	return 0;
}