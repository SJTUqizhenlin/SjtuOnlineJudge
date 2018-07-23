#include <iostream>
#include <vector>
typedef unsigned long long ULL;
using namespace std;

const ULL MAXN = (ULL)(1e18) + 1;
vector<vector<ULL> > v;

ULL Fn(int k, ULL p)
{
	if (p == 1) return 1;
	if (k == 1) return p;
	if (k == 2) return ((p * (p + 1)) / 2);
	if (k == 3) return (((p * (p - 1) * (p + 1)) / 6) + p);
	return v[k][(int)p];
}

void init_v() {
	for (int i = 0; i <= 3; i++) {
		vector<ULL> tmp;
		v.push_back(tmp);
	}
	for (int i = 4; i <= 100; i++) {
		vector<ULL> tmp;
		tmp.push_back(0); tmp.push_back(1);
		int size = 2;
		while (tmp[size - 1] < MAXN) {
			tmp.push_back(tmp[size - 1] + Fn(i - 1, size - 1) + 1);
			size++;
		}
		v.push_back(tmp);
	}
	return;
}

int main() {
	init_v();
	int T; cin >> T;
	while (T--) {
		int K; ULL N; cin >> K >> N;
		ULL l = 0, r = (ULL)(v[K].size() - 1);
		while (r > l + 1) {
			ULL mid = (l + r) / 2;
			if (Fn(K, mid) >= N) r = mid;
			else l = mid;
		}
		cout << r << endl;
	}
	return 0;
}
