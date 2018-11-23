#include <iostream>

using namespace std;

class myque {
public:
	int *arr;
	int MAXN, MAXM;
	int front; int back;
	long long Sum;
	myque(int N, int M) {
		MAXN = N; MAXM = M;
		front = 0; back = 0;
		Sum = 0;
		arr = new int[N];
		for (int i = 0; i < N; i++) arr[i] = 0;
	}
	void push(int x) {
		arr[back] = x;
		back++;
		Sum += x;
		if (back - front > MAXM) {
			Sum -= arr[front];
			front++;
		}
		cout << int(Sum / (back - front)) << endl;
		return;
	}
};

int main() {
	int n, m; cin >> n >> m;
	myque* q = new myque(m + 5, n);
	int tmp;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		q->push(tmp);
	}
	return 0;
}