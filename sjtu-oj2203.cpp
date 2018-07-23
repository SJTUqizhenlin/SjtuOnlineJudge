#include<queue>
#include<vector>
#include<stdio.h>
#include<string.h>
#define FOR(a,b,c) for(int a=(b);a<=(c);a++)
using namespace std;

const int N = 2005;
const int INF = (int)(1e9);

struct Edge {
	int u, v, w;
	Edge(int u, int v, int w)
		:u(u), v(v), w(w) {}
};
int n, m, a1, b1, a2, b2, ans;
int dx1[N], dx2[N], dy1[N], dy2[N];
int in[N], dis[N], inq[N];
vector<Edge> es, G[N];
vector<int> g[N];
queue<int> q;

void adde(int u, int v, int w) {
	es.push_back(Edge(u, v, w));
	g[u].push_back((int)es.size() - 1);
}
void add(int u, int v, int w) {
	G[u].push_back(Edge(u, v, w));
	in[v]++;
}

void spfa(int s, int* dis) {
	memset(inq, 0, sizeof(inq));
	FOR(i, 1, n) dis[i] = INF;
	dis[s] = 0; inq[s] = 1; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop(); inq[u] = 0;
		for (int i = 0; i<g[u].size(); i++) {
			Edge& e = es[g[u][i]];
			int v = e.v;
			if (dis[v]>dis[u] + e.w) {
				dis[v] = dis[u] + e.w;
				if (!inq[v])
					inq[v] = 1, q.push(v);
			}
		}
	}
}

void topo() {
	FOR(i, 1, n)
		if (!in[i]) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i<G[u].size(); i++) {
			int v = G[u][i].v;
			if (dis[v]<dis[u] + G[u][i].w) {
				dis[v] = dis[u] + G[u][i].w;
				ans = max(ans, dis[v]);
			}
			if (!(--in[v])) q.push(v);
		}
	}
}

int main() {
	scanf("%d%d%d%d%d%d", &n, &m, &a1, &b1, &a2, &b2);
	int u, v, w;
	FOR(i, 1, m) {
		scanf("%d%d%d", &u, &v, &w);
		adde(u, v, w), adde(v, u, w);
	}
	spfa(a1, dx1); spfa(b1, dy1);
	spfa(a2, dx2); spfa(b2, dy2);
	for (int i = 0; i<es.size(); i += 2) {
		int u = es[i].u, v = es[i].v, w = es[i].w;
		int len1 = min(dx1[u], dx1[v]) + min(dy1[u], dy1[v]) + w;
		int len2 = min(dx2[u], dx2[v]) + min(dy2[u], dy2[v]) + w;
		if (len1 == dx1[b1] && len2 == dx2[b2]) {
			if (dx1[u]<dx1[v]) add(u, v, w);
			else add(v, u, w);
		}
	}
	topo();
	printf("%d", ans);
	return 0;
}