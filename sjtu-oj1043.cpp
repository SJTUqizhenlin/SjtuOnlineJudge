#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int *element = new int[N];
	int *flagarr = new int[N];
	memset(element, 0, sizeof(int) * N);
	memset(flagarr, 0, sizeof(int) * N);
	int parent;
	bool b = true;
	for (int i = 1; i < N; i++)
	{
		scanf("%d", &parent);
		if (flagarr[parent] == 0) { element[i] = element[parent] * 2 + 1; flagarr[i] = 1; }
		else { element[i] = element[parent] * 2 + 2; }
		if (element[i] >= N) { b = false; cout << "false" << endl; break; }
	}
	if (b) cout << "true" << endl;
	return 0;
}