#include <iostream>
using namespace std;

int N, Enter, Exit;
int prnt[200005];
int sizz[200005];
int flag[200005];
int wall[200005][4];
int isOver = 0;

int getId(int row, int col) {
	row -= 1;
	return (((row * (row + 1)) / 2) + col);
}

int getRow(int x) {
	if (x == 1) return 1;
	int low = 1, high = N;
	x = x * 2;
	while (high - low > 1) {
		int mid = (high + low) / 2;
		if (mid * (mid + 1) >= x)
			high = mid;
		else
			low = mid;
	}
	return high;
}

int getCol(int x) {
	int r = getRow(x) - 1;
	return (x - ((r * (r + 1)) / 2));
}

int findprnt(int x) {
	int cur = x;
	while (prnt[cur] != cur) cur = prnt[cur];
	int root = cur;
	cur = x;
	int tmp;
	while (prnt[cur] != root) {
		tmp = prnt[cur];
		prnt[cur] = root;
		cur = tmp;
	}
	return root;
}

void Union(int a, int b) {
	a = findprnt(a);
	b = findprnt(b);
	if (a == b) return;
	if (sizz[a] < sizz[b]) { prnt[a] = b; sizz[b] += sizz[a]; }
	else { prnt[b] = a; sizz[a] += sizz[b]; }
	return;
}

void BreakWall(int x, int y) {
	int r = getRow(x), c = getCol(x);
	int nr, nc;
	if (y == 0) { nr = r - 1; nc = c - 1; }
	if (y == 1) { nr = r - 1; nc = c; }
	if (y == 2) { nr = r + 1; nc = c; }
	if (y == 3) { nr = r + 1; nc = c + 1; }
	if (nr < 1 || nr > N || nc < 1 || nc > nr) return;
	int n = getId(nr, nc);
	Union(x, n); wall[x][y] = 1; wall[n][3 - y] = 1;
	return;
}

void DFS(int *Path, int top) {
	if (isOver == 1) return;
	int cur = Path[top];
	if (cur == Exit) {
		for (int i = 0; i < top; ++i)
			cout << Path[i] << " ";
		cout << Exit << endl;
		isOver = 1;
		return;
	}
	int r = getRow(cur), c = getCol(cur);
	for (int y = 0; y < 4; ++y) {
		int nr, nc;
		if (y == 0) { nr = r - 1; nc = c - 1; }
		if (y == 1) { nr = r - 1; nc = c; }
		if (y == 2) { nr = r + 1; nc = c; }
		if (y == 3) { nr = r + 1; nc = c + 1; }
		if (nr < 1 || nr > N || nc < 1 || nc > nr) continue;
		int n = getId(nr, nc);
		if (wall[cur][y] == 0 || flag[n] > 0) continue;
		flag[n] = 1;
		Path[top + 1] = n;
		DFS(Path, top + 1);
		flag[n] = 0;
	}
	return;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> Enter >> Exit;
	for (int i = 0; i <= (N * (N + 1)) / 2; ++i) {
		prnt[i] = i;
		sizz[i] = 1;
	}
	int x, y;
	while (1) {
		int pEnter = findprnt(Enter);
		int pExit = findprnt(Exit);
		if (pEnter == pExit) {
			int *Path = new int[N * N + 1];
			Path[0] = Enter;
			flag[Enter] = 1;
			DFS(Path, 0);
			return 0;
		}
		cin >> x >> y;
		BreakWall(x, y);
	}
	return 0;
}
