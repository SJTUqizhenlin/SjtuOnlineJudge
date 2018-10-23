#include <iostream>

using namespace std;

class datetime {
public:
	int y, m, d, td;
	int darray[12];
	void init_darray() {
		darray[0] = 31;
		darray[1] = 28;
		darray[2] = 31;
		darray[3] = 30;
		darray[4] = 31;
		darray[5] = 30;
		darray[6] = 31;
		darray[7] = 31;
		darray[8] = 30;
		darray[9] = 31;
		darray[10] = 30;
		darray[11] = 31;
		return;
	}
	inline bool isRun(int x) {
		return ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0));
	}
	datetime() :y(1850), m(1), d(1), td(1) {
		init_darray();
		if (isRun(y)) darray[1] = 29;
	}
	datetime(int yy, int mm, int dd)
		:y(yy), m(mm), d(dd) {
		init_darray();
		if (isRun(y)) darray[1] = 29;
		calculate_td();
	}
	void calculate_td() {
		int ret = (y - 1850) * 365;
		ret += (y - 1849) / 4;
		ret -= (y - 1801) / 100;
		ret += (y - 1601) / 400;
		for (int i = 0; i < m - 1; i++)
			ret += darray[i];
		ret += d; td = ret;
		return;
	}
	inline int weekday() {
		return ((td % 7) + 1);
	}
	void addone() {
		d += 1;
		if (d > darray[m - 1]) {
			d = 1;
			m += 1;
			if (m >= 12) {
				m = 1;
				y += 1;
				if (isRun(y)) darray[1] += 1;
				if (isRun(y - 1)) darray[1] -= 1;
			}
		}
		td += 1;
		return;
	}
	void print_this() {
		cout << y << "/";
		if (m < 10) cout << "0";
		cout << m << "/";
		if (d < 10) cout << "0";
		cout << d;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int m, n, k;
	int beg, end;
	cin >> m >> n >> k;
	cin >> beg >> end;
	for (int i = beg; i <= end; i++) {
		int cnt = 0;
		datetime *cur = new datetime(i, m, 1);
		while (cur->m == m) {
			if (cur->weekday() == k) {
				cnt += 1;
				if (cnt == n) {
					cur->print_this();
					cout << endl;
					break;
				}
			}
			cur->addone();
		}
		if (cnt < n)
			cout << "none" << endl;
	}
	return 0;
}