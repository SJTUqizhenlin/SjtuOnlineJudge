#include <stdio.h>
#include <vector>
using namespace std;

const int maxN = 100000;
vector<int> graph[maxN + 5];
vector<int> querys[maxN + 5];
vector<int> query2id[maxN + 5];
int result[maxN + 5];
int N, Q;
int rootof[maxN + 5];
int visited[maxN + 5];

void init() {
	scanf("%d%d", &N, &Q);
	int u, v;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d%d", &u, &v);
		querys[u].push_back(v);
		querys[v].push_back(u);
		query2id[u].push_back(i);
		query2id[v].push_back(i);
	}
	for (int i = 1; i <= N; i++) rootof[i] = i;
	return;
}

int findRoot(int x) {
	if (rootof[x] == x) return x;
	rootof[x] = findRoot(rootof[x]);
	return rootof[x];
}

void Unite(int x, int y) {
	x = findRoot(x); y = findRoot(y);
	if (x == y) return;
	rootof[x] = y; return;
}

void dfs(int cur) {
	visited[cur] = 1; int siz = graph[cur].size();
	for (int i = 0; i < siz; i++) 
		if (visited[graph[cur][i]] == 0) {
			dfs(graph[cur][i]);
			Unite(graph[cur][i], cur);
		}
	siz = querys[cur].size();
	for (int i = 0; i < siz; i++) {
		if (visited[querys[cur][i]] == 1)
			result[query2id[cur][i]] = findRoot(querys[cur][i]);
	} return;
}

int main() {
	init();
	dfs(1);
	for (int i = 0; i < Q; i++) printf("%d\n", (result[i]));
	printf("\n");
	return 0;
}