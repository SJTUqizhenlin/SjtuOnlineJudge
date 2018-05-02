#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

const int MAX_ARR = (1 << 16) - 1;
int arr[MAX_ARR];
int posi[30001];

void after_trav(int root)
{
	if (arr[posi[root] * 2 + 1] > 0)
		after_trav(arr[posi[root] * 2 + 1]);
	if (arr[posi[root] * 2 + 2] > 0)
		after_trav(arr[posi[root] * 2 + 2]);
	printf("%d ", root);
	return;
}

int main()
{
	int N;
	cin >> N;
	arr[0] = 1;
	posi[1] = 0;
	int x, y, z;
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		if (y != -1)
		{
			arr[posi[x] * 2 + 1] = y;
			posi[y] = posi[x] * 2 + 1;
		}
		if (z != -1)
		{
			arr[posi[x] * 2 + 2] = z;
			posi[z] = posi[x] * 2 + 2;
		}
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", (posi[i] + 1));
	cout << endl;
	after_trav(1);
	cout << endl;
	return 0;
}