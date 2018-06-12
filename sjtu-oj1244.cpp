#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

const double EPS = 1e-9;
const double INF = 1e99;
struct coord {
	double x, y;
	coord(double xx, double yy)
		:x(xx), y(yy) {}
};
coord *arr[100005];
int N;
coord *stk[100005];
int stkSize;

double Angle(coord *a, coord *b) {
	if (a->x > b->x - EPS && a->x < b->x + EPS)
		return ((b->y - a->y) / EPS);
	return ((b->y - a->y) / (b->x - a->x));
}

bool cmpAngle(coord *a, coord *b) {
	return (Angle(arr[0], b) - Angle(arr[0], a) > EPS);
}

inline double Distance(coord *a, coord *b) {
	return sqrt(((b->x - a->x) * (b->x - a->x)) +
		((b->y - a->y) * (b->y - a->y)));
}

void init() {
	scanf("%d", &N);
	double x, y;
	for (int i = 0; i < N; i++) {
		scanf("%lf%lf", &x, &y);
		arr[i] = new coord(x, y);
	}
	if (N == 1) return;
	double minX = INF; int minXid = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i]->x < minX - EPS) {
			minX = arr[i]->x;
			minXid = i;
		}
		else {
			if (arr[i]->x > minX - EPS && arr[i]->x < minX + EPS)
				if (arr[i]->y < arr[minXid]->y - EPS) {
					minX = arr[i]->x;
					minXid = i;
				}
		}
	}
	coord *tmp = arr[0];
	arr[0] = arr[minXid];
	arr[minXid] = tmp;
	sort(arr + 1, arr + N, cmpAngle);
	int topid = 1;
	for (int i = 2; i < N; i++) {
		if (Angle(arr[0], arr[i]) - Angle(arr[0], arr[topid]) > EPS)
			arr[++topid] = arr[i];
		else {
			if (arr[i]->x - arr[topid]->x > EPS)
				arr[topid] = arr[i];
		}
	} N = topid + 1;
	return;
}

inline double vecmul(coord *a, coord *b, coord *c) {
	return ((c->x - a->x) * (b->y - a->y) - (b->x - a->x) * (c->y - a->y));
}

void findCH() {
	stk[0] = arr[0]; stk[1] = arr[1]; stk[2] = arr[2];
	stkSize = 3; int l, r, mid;
	for (int i = 3; i < N; i++) {
		l = 1; r = stkSize - 1;
		if (vecmul(stk[r], stk[r - 1], arr[i]) > EPS)
			stk[stkSize++] = arr[i];
		else {
			while (r - l > 1) {
				mid = (l + r) / 2;
				if (vecmul(stk[mid], stk[mid - 1], arr[i]) > EPS)
					l = mid;
				else
					r = mid;
			}
			stk[r] = arr[i];
			stkSize = r + 1;
		}
	} return;
}

int main() {
	init();
	if (N == 1) { printf("0.0000\n"); return 0; }
	if (N == 2) {
		printf("%.4f\n", Distance(arr[0], arr[1]));
		return 0;
	}
	findCH();
	double res = 0, tmp;
	for (int i = 0; i < stkSize; i++)
		for (int j = i + 1; j < stkSize; j++) {
			tmp = Distance(stk[i], stk[j]);
			res = (tmp > res ? tmp : res);
		}
	printf("%.4f\n", res);
	return 0;
}