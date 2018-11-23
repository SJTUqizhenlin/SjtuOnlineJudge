#include <iostream>

using namespace std;

const int MAXN = (1 << 16);
int id[MAXN];
int lson[MAXN];
int rson[MAXN];
int par[MAXN];

void postOrder(int root) {
	if (lson[root] > 0) postOrder(lson[root]);
	if (rson[root] > 0) postOrder(rson[root]);
	cout << root << " ";
	return;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int a, b, c;
	id[1] = 1;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		if (b > 0) { lson[a] = b; par[b] = a; id[b] = id[a] * 2; }
		if (c > 0) { rson[a] = c; par[c] = a; id[c] = id[a] * 2 + 1; }
	}
	for (int i = 1; i <= n; ++i) cout << id[i] << " ";
	cout << endl;
	postOrder(1);
	return 0;
}