#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = (1 << 20);
int heights[MAXN];
int N, H;

int NextInt() {
	char c = ' '; int res = 0;
	while (!(c >= '0' && c <= '9')) c = getchar();
	while (c >= '0' && c <= '9') { res = res * 10 + c - '0'; c = getchar(); }
	return res;
}

int main() {
	N = NextInt(); H = NextInt();
	for (int i = 0; i < N; i++) heights[i] = NextInt();
	sort(heights, heights + N);
	int cur = 0, stage = 0;
	for (stage; stage < N; stage++) {
		if (heights[stage] - cur <= H) cur = heights[stage];
		else break;
	}
	int minstg = 0; cur = 0;
	for (int i = 0; i < stage; i++) {
		if (i + 1 >= stage || heights[i + 1] - cur > H) { cur = heights[i]; minstg++; }
		else {}
	}
	printf("%d %d %d\n", heights[stage - 1], stage, minstg);
	return 0;
}