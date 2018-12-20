#include <iostream>
using namespace std;

long long arr[20000];
int hsize;

void Exchange(int id1, int id2) {
	long long t = arr[id1];
	arr[id1] = arr[id2];
	arr[id2] = t;
	return;
}

void down_move(int id) {
	while (id * 2 <= hsize) {
		int nxt;
		if (id * 2 + 1 <= hsize) {
			nxt = (arr[id * 2] < arr[id * 2 + 1] ? id * 2 : id * 2 + 1);
		}
		else {
			nxt = id * 2;
		}
		if (arr[nxt] < arr[id]) {
			Exchange(id, nxt);
			id = nxt;
		}
		else {
			break;
		}
	}
	return;
}

void build_heap() {
	for (int i = hsize / 2; i > 0; i--)
		down_move(i);
	return;
}

long long pop_heap() {
	Exchange(1, hsize);
	hsize -= 1;
	down_move(1);
	return arr[hsize + 1];
}

void up_move(int id) {
	while (id > 1) {
		if (arr[id] < arr[id / 2]) {
			Exchange(id, id / 2);
			id = id / 2;
		}
		else {
			break;
		}
	}
	return;
}

void push_heap(long long v) {
	hsize += 1;
	arr[hsize] = v;
	up_move(hsize);
	return;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> hsize;
	long long temp;
	for (int i = 1; i <= hsize; i++) {
		cin >> temp;
		arr[i] = temp;
	}
	build_heap();
	int H = hsize;
	long long res = 0;
	for (int i = 0; i < H - 1; i++) {
		long long top1 = pop_heap();
		long long top2 = pop_heap();
		res += top1;
		res += top2;
		long long nt = top1 + top2;
		push_heap(nt);
	}
	cout << res;
	return 0;
}
