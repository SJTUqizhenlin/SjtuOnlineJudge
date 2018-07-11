#include <iostream>
#include <algorithm>
using namespace std;

class fraction {
public:
	long long nume; long long deno;
	fraction()
		:nume(0), deno(1) {}
	bool operator<(const fraction &rhs) const {
		return (nume * rhs.deno < deno * rhs.nume);
	}
	bool operator==(const fraction &rhs) const {
		return (nume * rhs.deno == deno * rhs.nume);
	}
};

long long x[710];
long long y[710];
int n;

int MaxRes(int i) {
	fraction *seq = new fraction[n - 1];
	int id = 0;
	for (int j = 0; j < n; j++) {
		if (j == i) continue;
		seq[id].deno = y[j] - y[i];
		seq[id].nume = x[j] - x[i];
		id++;
	}
	sort(seq, seq + n - 1);
	int l = 0, r = 0, ret = 0;
	while (l < n - 1) {
		while (r < n - 1 && seq[r] == seq[l]) r++;
		if (r - l > ret) ret = r - l;
		l = r;
	}
	return ret + 1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	int res = 0, tmp;
	for (int i = 0; i < n; i++) {
		tmp = MaxRes(i);
		res = (tmp > res ? tmp : res);
	}
	cout << res << endl;
	return 0;
}