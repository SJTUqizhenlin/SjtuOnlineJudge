#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	int *arr = new int[3000];
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	int M; cin >> M;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		bool flag = false;
		for (int j = 0; j < N; ++j) {
			if (arr[j] == tmp) {
				cout << "Y\n";
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "N\n";
		}
	}
	return 0;
}
