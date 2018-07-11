#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned long long ULL;


int number[100000 + 10];

int front[100000 + 10];
int nex[100000 + 10];

void out(int x) {
	nex[front[x]] = nex[x];
	front[nex[x]] = front[x];
}

void in(int x, int w) { 
	nex[w] = nex[x];
	nex[x] = w;
	front[nex[w]] = w;
	front[w] = x;
}

int main(int argc, char const *argv[])
{
	int M;
	int m; 
	cin >> M >> m;
	for (int i = 1; i <= M; ++i)
	{
		number[i] = i;
		front[i] = (i == 1) ? M : i - 1;
		nex[i] = (i == M) ? 1 : i + 1;
	}
	int cur = 1;
	int cnt = M;
	int K;
	ULL res = ((1 + M)*M) / 2;
	for (int i = 0; i < m; ++i)
	{
		int flag;
		scanf("%d", &flag);
		if (flag == 0) {
			scanf("%d", &K);
			K %= (cnt);
			if (K == 0)    K += cnt;
			for (int i = 0; i < K - 1; ++i)
				cur = nex[cur];
			out(cur);
			res -= number[cur];
			cur = nex[cur];
			cnt--;

		}
		else {
			int W;
			scanf("%d %d", &K, &W);
			K %= (cnt);
			number[++M] = W;
			if (K == 0)    K += cnt;
			for (int i = 0; i < K - 1; ++i)
				cur = nex[cur];
			in(cur, M);
			res += W;
			cur = M;
			cnt++;
		}
	}
	cout << res << endl;
	return 0;
}