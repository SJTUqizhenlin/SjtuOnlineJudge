//This is actually the implement of "next_permutation"

#include <iostream>
using namespace std;

void Next_Permutate(int *arr, int beg, int end) {
	int p = end - 1;
	while (p > beg) {
		if (*(arr + p) > *(arr + p - 1)) break;
		p--;
	}
	int tmp;
	if (p == beg) {
		for (int i = 0; i * 2 < end - 1 - beg; i++) {
			tmp = *(arr + beg + i);
			*(arr + beg + i) = *(arr + end - 1 - i);
			*(arr + end - 1 - i) = tmp;
		}
		return;
	}
	int p2 = end - 1;
	while (p2 >= p) {
		if (*(arr + p2) > *(arr + p - 1)) break;
		p2--;
	}
	tmp = *(arr + p2);
	*(arr + p2) = *(arr + p - 1);
	*(arr + p - 1) = tmp;
	for (int i = 0; i * 2 < end - 1 - p; i++) {
		tmp = *(arr + p + i);
		*(arr + p + i) = *(arr + end - 1 - i);
		*(arr + end - 1 - i) = tmp;
	}
	return;
}

int main() {
	int N; cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++) cin >> arr[i];
	Next_Permutate(arr, 0, N);
	for (int i = 0; i < N; i++) cout << arr[i] << ' ';
	return 0;
}