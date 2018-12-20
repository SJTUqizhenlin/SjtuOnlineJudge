#include <iostream>
using namespace std;

int N, k;
const int MAXN = (1 << 21);
int arr[MAXN];
int copyarr[MAXN];
int Res;

void PushHeap(int cur) {
	while (cur > 1) {
		++Res;
		if (arr[cur] < arr[cur / 2]) {
			int tmp = arr[cur];
			arr[cur] = arr[cur / 2];
			arr[cur / 2] = tmp;
			cur = cur / 2;
		}
		else
			break;
	}
	return;
}

void PopHeap(int cur) {
	int tmp = arr[1];
	arr[1] = arr[cur];
	arr[cur] = tmp;
	cur -= 1;
	int id = 1;
	while (id * 2 <= cur) {
		int nxt = id * 2;
		if (id * 2 + 1 <= cur) {
			++Res;
			if (arr[id * 2 + 1] < arr[id * 2]) nxt = id * 2 + 1;
		}
		++Res;
		if (arr[id] > arr[nxt]) {
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
	int heapsize = 0;
	while (++heapsize <= N) PushHeap(heapsize);
	while (--heapsize > 0) PopHeap(heapsize);
	return;
}

void MergeSort(int a, int b) {
	int leng = b - a + 1;
	if (leng <= 1) return;
	int mid = (a + b + 1) / 2 - 1;
	MergeSort(a, mid);
	MergeSort(mid + 1, b);
	for (int i = a; i <= b; ++i) copyarr[i] = arr[i];
	int head1 = a, head2 = mid + 1, head = a;
	while (head1 <= mid && head2 <= b) {
		++Res;
		if (copyarr[head1] < copyarr[head2])
			arr[head++] = copyarr[head1++];
		else
			arr[head++] = copyarr[head2++];
	}
	while (head1 <= mid)
		arr[head++] = copyarr[head1++];
	while (head2 <= b)
		arr[head++] = copyarr[head2++];
	return;
}

void QuickSort(int a, int b) {
	if (b - a + 1 <= 1) return;
	int x = arr[a];
	int cur = b;
	for (int i = b; i > a; --i) {
		++Res;
		if (arr[i] > x) {
			int tmp = arr[i];
			arr[i] = arr[cur];
			arr[cur] = tmp;
			--cur;
		}
	}
	for (int i = a; i < cur; ++i)
		arr[i] = arr[i + 1];
	arr[cur] = x;
	QuickSort(a, cur - 1);
	QuickSort(cur + 1, b);
	return;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> k; Res = 0;
	for (int i = 1; i <= N; ++i) cin >> arr[i];
	if (k == 1) HeapSort();
	if (k == 2) MergeSort(1, N);
	if (k == 3) QuickSort(1, N);
	cout << Res << endl;
	return 0;
}
