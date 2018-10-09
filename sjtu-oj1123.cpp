#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

class pair_xy {
public:
	int x; int y;
	pair_xy() :x(0), y(0) {}
	pair_xy(int xx, int yy)
		:x(xx), y(yy) {}
	bool operator<(const pair_xy& b) const {
		return x < b.x;
	}
	bool operator==(const pair_xy& b) const {
		return x == b.x;
	}
};

int N, K;
const int MOD = 100007;
const int MAXI = 100005;
pair_xy pair_arr[60000];

class Bit1 {
public:
	int buf[MAXI];
	Bit1() {
		memset(buf, 0, sizeof(int) * MAXI);
	}
	void Add_at(int num, int index) {
		while (index < MAXI) {
			buf[index] += num;
			buf[index] %= MOD;
			index += index & (-index);
		}
		return;
	}
	int Sum_at(int index) {
		int ret = 0;
		while (index) {
			ret += buf[index];
			ret %= MOD;
			index -= index & (-index);
		}
		return ret;
	}
};

class Bit2 {
public:
	const static int MAXI = 100005;
	int buf[MAXI];
	Bit2() {
		memset(buf, 0, sizeof(int) * MAXI);
	}
	void Add_at(int num, int index) {
		index = MAXI - index;
		while (index < MAXI) {
			buf[MAXI - index] += num;
			buf[MAXI - index] %= MOD;
			index += index & (-index);
		}
		return;
	}
	int Sum_at(int index) {
		index = MAXI - index;
		int ret = 0;
		while (index) {
			ret += buf[MAXI - index];
			ret %= MOD;
			index -= index & (-index);
		}
		return ret;
	}
};

Bit1 up_arr1[11];
Bit1 down_arr1[11];
Bit2 up_arr2[11];
Bit2 down_arr2[11];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	int tmpx, tmpy;
	for (int i = 0; i < N; i++) {
		cin >> tmpx >> tmpy;
		pair_arr[i].x = tmpx;
		pair_arr[i].y = tmpy;
	}
	sort(pair_arr, pair_arr + N);
	int y;
	int mid1, mid2;
	for (int i = 0; i < N; i++) {
		y = pair_arr[i].y;
		up_arr1[0].Add_at(1, y);
		up_arr2[0].Add_at(1, y);
		down_arr1[0].Add_at(1, y);
		down_arr2[0].Add_at(1, y);
		for (int j = 1; j <= 10; j++) {
			mid1 = (up_arr1[j].Sum_at(y - 1) + down_arr1[j - 1].Sum_at(y - 1)) % MOD;
			up_arr1[j].Add_at(mid1, y);
			up_arr2[j].Add_at(mid1, y);
			mid2 = (down_arr2[j].Sum_at(y + 1) + up_arr2[j - 1].Sum_at(y + 1)) % MOD;
			down_arr2[j].Add_at(mid2, y);
			down_arr1[j].Add_at(mid2, y);
		}
	}
	cout << (up_arr1[K].Sum_at(MAXI - 1) + down_arr2[K].Sum_at(0)) % MOD << endl;
	return 0;
}