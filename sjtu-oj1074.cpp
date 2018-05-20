#include <stdio.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	bool **m = new bool*[N + 1];
	for (int i = 0; i <= N; i++)
		m[i] = new bool[M + 1];
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++)
			m[i][j] = false;
	char chr;
	for (int i = 1; i <= N; i++)
	{
		scanf("%c", &chr);
		for (int j = 1; j <= M; j++)
		{
			scanf("%c", &chr);
			if (chr == '-') m[i][j] = 1;
		}
	}
	int **s = new int*[N + 1];
	for (int i = 0; i <= N; i++)
		s[i] = new int[M + 1];
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++)
			s[i][j] = 0;
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 2; j <= M; j++)
		{
			if (!m[i][j] || !m[i][j - 1]) continue;
			int upper = s[i - 1][j - 2];
			int test = 1;
			for (; test <= upper; test++)
			{
				if (!m[i - test][j - 1] || !m[i - test][j]) break;
				if (!m[i][j - test * 2] || !m[i][j - test * 2 - 1]) break;
			}
			s[i][j] = test;
			if (s[i][j] > ans) ans = s[i][j];
		}
	}
	//for (int i = 0; i <= N; i++)
	//{
	//	for (int j = 0; j <= M; j++)
	//		printf("%d ", s[i][j]);
	//	printf("\n");
	//}
	printf("%d\n", ans * ans * 2);
	return 0;
}