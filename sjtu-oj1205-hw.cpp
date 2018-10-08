#include <iostream>

using namespace std;

long long ack[10][100000];

long long ackerman(long long m, long long n) {
	if (ack[m][n]) return ack[m][n];
	if (m == 0) return (n + 1);
	if (n == 0) return ack[m][n] = ackerman(m - 1, 1);
	return ack[m][n] = ackerman(m - 1, ackerman(m, n - 1));
}

int main() {
	long long m, n;
	cin >> m >> n;
	cout << ackerman(m, n) << endl;
	return 0;
}