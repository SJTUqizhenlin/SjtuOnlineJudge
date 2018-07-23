#include <cstdio>  
#include <algorithm>   
#define For(i,j,k) for(int i = j;i <= (int)k;i ++)  
#define max(a, b) (a > b ? a : b);
using namespace std;

int G[205][205];
int degree[205];
long long xi[205], yi[205], vx[205], vy[205];
int N;
int all[205][205], some[205][205], none[205][205];
int resn;

bool cmpdeg(int a, int b) { return degree[a] > degree[b]; }

int canMeet(int a, int b)
{
	if (xi[a] == xi[b] && yi[a] == yi[b]) return 1;
	if (vx[a] == vx[b] && vy[a] == vy[b]) return 0;
	if (vx[a] == vx[b])
		if (xi[a] == xi[b]) return 1; else return 0;
	if (vy[a] == vy[b])
		if (yi[a] == yi[b]) return 1; else return 0;
	if ((vx[a] - vx[b]) * (yi[a] - yi[b]) == (vy[a] - vy[b]) * (xi[a] - xi[b]))
		return 1;
	else return 0;
}

void DFS(int n, int an, int sn, int nn) {
	if (sn + an < resn) return;
	if (!sn && !nn) resn = max(resn, an);
	int key = 1;
	int keynum[205];
	For(i, 1, sn)
	{
		keynum[i] = 0;
		For(j, 1, sn)
			if (G[some[n][i]][some[n][j]]) keynum[i]++;
		if (keynum[i] > keynum[key]) key = i;
	}
	key = some[n][key];
	For(j, 1, sn) {
		int v = some[n][j], tsn = 0, tnn = 0;
		if (G[key][v])continue;
		For(i, 1, an) all[n + 1][i] = all[n][i]; all[n + 1][an + 1] = v;
		For(i, 1, sn) if (G[v][some[n][i]]) some[n + 1][++tsn] = some[n][i];
		For(i, 1, nn) if (G[v][none[n][i]]) none[n + 1][++tnn] = none[n][i];
		DFS(n + 1, an + 1, tsn, tnn);
		some[n][j] = 0, none[n][++nn] = v;
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) 
		scanf("%lld%lld%lld%lld", &xi[i], &yi[i], &vx[i], &vy[i]);
	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++)
			if (canMeet(i, j))
				G[i][j] = G[j][i] = 1;

	resn = 0;
	For(i, 1, N) some[1][i] = i;
	sort(&some[1][1], &some[1][N + 1], cmpdeg);
	DFS(1, 0, N, 0);
	printf("%d\n", resn);

	return 0;
}


