#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

class MinHeap {
public:
	static const int MAXN = 20010;
	int* arr;
	int size;
	MinHeap() {
		arr = new int[MAXN];
		size = 1;
	}
	void insert(int x) {
		arr[size] = x;
		size += 1;
		int cur = size - 1;
		while (cur > 1) {
			if (arr[cur / 2] > arr[cur]) {
				int tmp = arr[cur];
				arr[cur] = arr[cur / 2];
				arr[cur / 2] = tmp;
				cur = cur / 2;
			}
			else break;
		}
		return;
	}
	int find(int x) {
		int ret = 0;
		int min = INT32_MAX;
		for (int i = 1; i < size; i++) {
			if (arr[i] <= x) continue;
			if (arr[i] < min) {
				min = arr[i];
				ret = i;
			}
		}
		return ret;
	}
	void Dec(int x, int v) {
		int cur = x;
		arr[cur] -= v;
		while (cur > 1) {
			if (arr[cur / 2] > arr[cur]) {
				int tmp = arr[cur];
				arr[cur] = arr[cur / 2];
				arr[cur / 2] = tmp;
				cur = cur / 2;
			}
			else break;
		}
		return;
	}
};

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	int M; cin >> M;
	MinHeap* h = new MinHeap();
	string cmmd; int tmp = 0, tmp2 = 0;
	for (int i = 0; i < M; i++) {
		cin >> cmmd;
		if (cmmd[0] == 'i') {
			cin >> tmp;
			h->insert(tmp);
		}
		if (cmmd[0] == 'f') {
			cin >> tmp;
			cout << h->find(tmp) << endl;
		}
		if (cmmd[0] == 'd') {
			cin >> tmp >> tmp2;
			h->Dec(tmp, tmp2);
		}
	}
	return 0;
}