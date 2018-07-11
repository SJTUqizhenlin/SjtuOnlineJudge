#include <stdio.h>
using namespace std;

int arr[1000][1000];
int N;

int NextInt() {
	char c = ' '; int res = 0;
	while (!(c >= '0' && c <= '9')) c = getchar();
	while (c >= '0' && c <= '9') { res = res * 10 + c - '0'; c = getchar(); }
	return res;
}

void init() {
	N = NextInt();
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++) arr[i][j] = NextInt();
	return;
}

void calculate() {
	for (int i = N - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			arr[i][j] += (arr[i + 1][j] > arr[i + 1][j + 1] ? 
				arr[i + 1][j] : arr[i + 1][j + 1]);
	return;
}

int main() {
	init();
	calculate();
	printf("%d\n", arr[0][0]);
	return 0;
}