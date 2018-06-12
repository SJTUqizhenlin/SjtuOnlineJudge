#include <stdio.h>
#include <string.h>
using namespace std;

int N; char s[100005];
int mine[100005];
bool flag = false;

int HaveFilled(int x) {
	int ret = 0;
	ret += mine[x];
	if (x > 0) ret += mine[x - 1];
	if (x < N - 1) ret += mine[x + 1];
	return ret;
}

bool canFill(int cur) {
	if (s[cur] == '*')
		return true;
	else
		return ('0' + HaveFilled(cur)) <= s[cur];
}

bool exactFill(int cur) {
	if (s[cur] == '*')
		return true;
	else
		return ('0' + HaveFilled(cur)) == s[cur];
}

void dfs(int x) {
	if (flag) return;
	if (x < 0) {
		flag = exactFill(0);
		return;
	}
	mine[x] = 1;
	if ((x == N - 1 && canFill(x))
		|| (x < N - 1 && exactFill(x + 1)))
		dfs(x - 1);
	if (flag) return;
	mine[x] = 0;
	if ((x == N - 1 && canFill(x))
		|| (x < N - 1 && exactFill(x + 1)))
		dfs(x - 1);
	return;
}

int main() {
	scanf("%d", &N); scanf("%s", &s);
	dfs(N - 1);
	int minenum = 0;
	for (int i = 0; i < N; i++)
		if (mine[i]) minenum++;
	printf("%d\n", minenum);
	for (int i = 0; i < N; i++) printf("%d", mine[i]);
	printf("\n"); return 0;
}