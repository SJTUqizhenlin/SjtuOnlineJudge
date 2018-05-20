#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
	int K, N;
	cin >> K >> N;
	int *stamp = new int[N];
	int max_stamp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> stamp[i];
		if (stamp[i] > max_stamp) max_stamp = stamp[i];
	}
	int *used = new int[max_stamp * K + 1];
	for (int i = 1; i <= max_stamp * K; i++)
		used[i] = K + 1;
	used[0] = 0;
	int sum = 1;
	for (; sum <= max_stamp * K; sum++)
	{
		int tmp = K + 1;
		for (int i = 0; i < N; i++)
			if (sum >= stamp[i])
				if (used[sum - stamp[i]] < K)
					if (used[sum - stamp[i]] + 1 < tmp)
						tmp = used[sum - stamp[i]] + 1;
		if (tmp == K + 1) break;
		used[sum] = tmp;
	}
	//for (int i = 0; i <= max_stamp * K; i++)
	//	cout << used[i] << " ";
	//cout << endl;
	cout << sum - 1 << endl;
	return 0;
}