#include <stdio.h>
#include <string>
using namespace std;

int N, M, Galaxy;
int rootof[100005];
int rankof[100005];

void init(int n) {
	Galaxy = 0;
	for (int i = 0; i <= n; i++) {
		rootof[i] = i;
		rankof[i] = 1;
	} return;
}

int FindRoot(int a) {
	if (rootof[a] == a) return a;
	rootof[a] = FindRoot(rootof[a]);
	return (rootof[a]);
}

void Unite(int a, int b) {
	a = FindRoot(a); b = FindRoot(b);
	if (a == b) return;
	if (rankof[a] == 1 && rankof[b] == 1)
		Galaxy++;
	if (rankof[a] > 1 && rankof[b] > 1)
		Galaxy--;
	if (rankof[a] < rankof[b]) {
		rootof[a] = b;
		rankof[b] += rankof[a];
	}
	else {
		rootof[b] = a;
		rankof[a] += rankof[b];
	} return;
}

int main() {
	scanf("%d%d", &N, &M);
	init(N);
	char op; int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%c", &op);
		while (!(op == 'a' || op == 'b' || op == 'c'))
			scanf("%c", &op);
		if (op == 'a') {
			scanf("%d%d", &a, &b);
			Unite(a, b);
		}
		if (op == 'b') {
			printf("%d\n", Galaxy);
		}
		if (op == 'c') {
			scanf("%d%d", &a, &b);
			if (FindRoot(a) == FindRoot(b))
				printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}