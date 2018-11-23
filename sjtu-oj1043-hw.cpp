#include <iostream>

using namespace std;

int id[1000010];
int state[1000010];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	int p;
	id[0] = 0;
	for (int i = 1; i < N; ++i) {
		cin >> p;
		if (state[p] == 0) {
			id[i] = id[p] * 2 + 1;
			state[p] = 1;
		}
		else
			id[i] = id[p] * 2 + 2;
		if (id[i] >= N) {
			cout << "false\n";
			return 0;
		}
	}
	cout << "true\n";
	return 0;
}