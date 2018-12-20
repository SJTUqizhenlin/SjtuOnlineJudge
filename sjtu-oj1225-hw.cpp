#include <iostream>
using namespace std;

int arr[1000005];
int N;
int heapsize = 0;

void DownMove(int id) {
	while (id * 2 <= heapsize) {
		int nxt = id * 2;
		if (id * 2 + 1 <= heapsize)
			if (arr[id * 2 + 1] > arr[id * 2]) nxt = id * 2 + 1;
		if (arr[id] < arr[nxt]) {
			int tmp = arr[id];
			arr[id] = arr[nxt];
			arr[nxt] = tmp;
			id = nxt;
		}
		else
			break;
	}
	return;
}

void HeapSort() {
	for (int i = heapsize / 2; i > 0; --i)
		DownMove(i);
	for (int i = 0; i < N - 1; ++i) {
		int tmp = arr[1];
		arr[1] = arr[heapsize];
		arr[heapsize] = tmp;
		heapsize--;
		DownMove(1);
	}
	return;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	heapsize = N;
	for (int i = 1; i <= N; ++i) cin >> arr[i];
	HeapSort();
	int res = 1;
	for (int i = 1; i < N; ++i)
		if (arr[i + 1] > arr[i]) ++res;
	cout << res;
	return 0;
}
