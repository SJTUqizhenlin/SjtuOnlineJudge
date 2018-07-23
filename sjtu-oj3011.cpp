#include <stdio.h>
#include <algorithm>
using namespace std;

int begarr[5010];
int endarr[5010];
int N;

void init() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &(begarr[i]), &(endarr[i]));
	sort(begarr, begarr + N);
	sort(endarr, endarr + N);
	return;
}

int main() {
	init();
	int head1 = -1, head2 = -1;
	int res1 = 0, res2 = 0;
	int BEG = begarr[0];
	for (int i = 0; i < N * 2; i++) {
		if (head1 < N - 1)
			(begarr[head1 + 1] <= endarr[head2 + 1] ? ++head1 : ++head2);
		else
			++head2;
		if (head1 == head2) {
			if (endarr[head2] - BEG > res1)
				res1 = endarr[head2] - BEG;
			if (head1 < N - 1) {
				if (begarr[head1 + 1] - endarr[head2] > res2)
					res2 = begarr[head1 + 1] - endarr[head2];
				BEG = begarr[head1 + 1];
			}
		}
	}
	printf("%d %d\n", res1, res2);
	return 0;
}