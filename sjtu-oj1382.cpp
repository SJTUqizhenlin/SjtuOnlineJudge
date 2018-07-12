#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
unsigned int l[100000 + 5] = { 0 };

int main(int argc, char const *argv[])
{
	cin >> N >> S;
	for (int i = 1; i <= N; ++i)
		cin >> l[i];
	unsigned long long ans = 0;
	sort(l + 1, l + N + 1);
	int cur = N;
	for (int i = 1; i <= N; ++i)
	{
		for (; cur >= 1; cur--) {
			if (l[cur] + l[i] <= S)
				break;
		}
		if (cur<i)
			break;
		ans += cur - i;
	}
	cout << ans << endl;
	return 0;
}