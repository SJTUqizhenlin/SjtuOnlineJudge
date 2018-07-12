#include <stdio.h>
#include <queue>
using namespace std;

const int maxN = 1000;
int MapArr[maxN + 5][maxN + 5];
int FromBeg[maxN + 5][maxN + 5];
int FromEnd[maxN + 5][maxN + 5];
int visitedBeg[maxN + 5][maxN + 5];
int visitedEnd[maxN + 5][maxN + 5];
int M, N;
struct Pos {
	int x, y;
	Pos(int xx, int yy)
		:x(xx), y(yy) {}
};
Pos *Beg, *End;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

void init_Map() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", &(MapArr[i][j]));
			if (MapArr[i][j] == 2) Beg = new Pos(i, j);
			if (MapArr[i][j] == 3) End = new Pos(i, j);
		}
	return;
}

void cal_FromBeg() {
	queue<Pos*> q;
	q.push(Beg); visitedBeg[Beg->x][Beg->y] = 1;
	Pos *pFront; int nx, ny;
	while (!q.empty()) {
		pFront = q.front();
		for (int d = 0; d < 4; d++) {
			nx = pFront->x + dx[d];
			ny = pFront->y + dy[d];
			if (nx < 1 || nx > M || ny < 1 || ny > N) continue;
			if ((visitedBeg[nx][ny] == 0) && (MapArr[nx][ny] != 1)) {
				q.push((new Pos(nx, ny)));
				visitedBeg[nx][ny] = 1;
				FromBeg[nx][ny] = FromBeg[pFront->x][pFront->y] + 1;
			}
		}
		q.pop();
	}
	return;
}

void cal_FromEnd() {
	queue<Pos*> q;
	q.push(End); visitedEnd[End->x][End->y] = 1;
	Pos *pFront; int nx, ny;
	while (!q.empty()) {
		pFront = q.front();
		for (int d = 0; d < 4; d++) {
			nx = pFront->x + dx[d];
			ny = pFront->y + dy[d];
			if (nx < 1 || nx > M || ny < 1 || ny > N) continue;
			if ((visitedEnd[nx][ny] == 0) && (MapArr[nx][ny] != 1)) {
				q.push((new Pos(nx, ny)));
				visitedEnd[nx][ny] = 1;
				FromEnd[nx][ny] = FromEnd[pFront->x][pFront->y] + 1;
			}
		}
		q.pop();
	}
	return;
}

int main() {
	init_Map();
	cal_FromBeg();
	cal_FromEnd();
	int res = maxN * maxN * 3;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++) {
			if (MapArr[i][j] == 4 && (FromBeg[i][j] > 0 && FromEnd[i][j] > 0)) {
				if (FromBeg[i][j] + FromEnd[i][j] < res)
					res = FromBeg[i][j] + FromEnd[i][j];
			}
		}
	printf("%d\n", res);
	return 0;
}