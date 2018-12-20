#include <iostream>
using namespace std;

int lsonarr[100005];
int rsonarr[100005];
int prntarr[100005];
int N, X, Y;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> X >> Y;
	for (int i = 1; i <= N; ++i) {
		cin >> lsonarr[i] >> rsonarr[i];
		if (lsonarr[i] > 0)
			prntarr[lsonarr[i]] = i;
		if (rsonarr[i] > 0)
			prntarr[rsonarr[i]] = i;
	}
	int *Xarr = new int[100005];
	int *Yarr = new int[100005];
	int idx = 0;
	int cur = X;
	while (cur > 0) {
		Xarr[idx++] = cur;
		cur = prntarr[cur];
	}
	int idy = 0;
	cur = Y;
	while (cur > 0) {
		Yarr[idy++] = cur;
		cur = prntarr[cur];
	}
	int t = 1;
	for ( ; ; t++) {
		if (Xarr[idx - t] != Yarr[idy - t])
			break;
	}
	cout << Xarr[idx - t + 1];
	return 0;
}
