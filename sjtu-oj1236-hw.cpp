	#include <iostream>
	#include <queue>
	using namespace std;
	
	const int MAXL = 100000000;
	int gph[101][101];
	int islink[101][101];
	int res[101];
	int inque[101];
	
	int main() {
		int N, M, S, D;
		cin >> N >> M >> S >> D;
		int x, y, z;
		for (int i = 1; i <= N; ++i) {
			res[i] = MAXL;
			inque[i] = 0;
			for (int j = 1; j <= N; ++j) {
				islink[i][j] = 0;
				gph[i][j] = MAXL;
			}
		}
		for (int i = 0; i < M; ++i) {
			cin >> x >> y >> z;
			islink[x][y] = 1;
			if (z < gph[x][y]) gph[x][y] = z;
		}
		res[S] = 0;
		queue<int> q;
		q.push(S); inque[S] = 1;
		while (!q.empty()) {
			int cur = q.front();
			for (int i = 1; i <= N; ++i) {
				if (islink[cur][i] == 0) continue;
				if (res[cur] + gph[cur][i] < res[i]) {
					res[i] = res[cur] + gph[cur][i];
					if (inque[i] == 0) {
						q.push(i);
						inque[i] = 1;
					}
				}
			}
			q.pop(); inque[cur] = 0;
		}
		cout << res[D];
		return 0;
	}
