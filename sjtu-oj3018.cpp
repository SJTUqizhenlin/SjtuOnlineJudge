#include <stdio.h>
#include <vector>
using namespace std;

const int maxN = 1000;
vector<int> edgeArr[maxN + 5];
int visited[maxN + 5];
int depth[maxN + 5];
int n, m;

void init() {
	scanf("%d%d", &n, &m);
	int u, v;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		edgeArr[u].push_back(v);
	} return;
}

bool dfs(int x) {
	visited[x] = 1; bool ret = true;
	int siz = edgeArr[x].size();
	for (int i = 0; i < siz; i++) {
		if (visited[edgeArr[x][i]] == 0) {
			ret = ret && dfs(edgeArr[x][i]);
			if (!ret) return ret;
			if (depth[edgeArr[x][i]] >= depth[x])
				depth[x] = depth[edgeArr[x][i]] + 1;
		}
		if (visited[edgeArr[x][i]] == 1)
			return false;
		if (visited[edgeArr[x][i]] == 2) {
			if (depth[edgeArr[x][i]] >= depth[x])
				depth[x] = depth[edgeArr[x][i]] + 1;
		}
	}
	visited[x] = 2;
	return ret;
}

int main() {
	init();
	bool isOk = true;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			isOk = isOk && dfs(i);
			if (!isOk) break;
		}
	}
	if (!isOk) printf("hehe\n");
	else {
		int res = 0;
		for (int i = 1; i <= n; i++)
			res += (100 + depth[i]);
		printf("%d\n", res);
	}
	return 0;
}