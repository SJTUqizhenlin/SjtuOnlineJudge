#include <iostream>

using namespace std;

int arr[101][101];
int num[101];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	int inN;
	int max, inN2, tmp;
	for (int j = 1; j <= N - 1; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			inN = (i + j - 1) % N + 1;
			max = 0;
			for (int k = i; k < i + j; k++)
			{
				inN2 = (k - 1) % N + 1;
				tmp = arr[i][inN2] + arr[inN2 % N + 1][inN] + num[i] * num[inN2 % N + 1] * num[inN % N + 1];
				if (tmp > max)
					max = tmp;
			}
			arr[i][inN] = max;
		}
	}
	tmp = 0;
	for (int i = 1; i <= N; i++)
	{
		inN = (i + N - 2) % N + 1;
		if (arr[i][inN] > tmp)
			tmp = arr[i][inN];
	}
	cout << tmp << endl;
	return 0;
}