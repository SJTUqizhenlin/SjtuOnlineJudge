#include <iostream>
using namespace std;

struct point
{
	int x, y, n;
	point() :x(0), y(0), n(0) {}
	point& operator=(int ix)
	{
		n = ix; x = ix / 5; y = ix % 5;
		return *this;
	}
};

char g[5][5];
point sub_g[7];
int Count;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int queue_0[10];
bool visited[25];

bool inSubG(int x)
{
	for (int i = 0; i < 7; i++)
		if (sub_g[i].n == x) return true;
	return false;
}

bool check_sat()
{
	int num1 = 0, num2 = 0;
	int que_l = 0, que_r = 0;
	int plus_d;
	for (int i = 0; i < 25; i++) visited[i] = 0;
	queue_0[que_r++] = sub_g[0].n;
	visited[sub_g[0].n] = 1;
	while (que_r > que_l)
	{
		int x = queue_0[que_l] / 5, y = queue_0[que_l] % 5;
		if (g[x][y] == 'H') ++num1; else ++num2;
		que_l++;
		for (int dd = 0; dd < 4; dd++)
			if (x + dx[dd] >= 0 && x + dx[dd] <= 4 && y + dy[dd] >= 0 && y + dy[dd] <= 4)
			{
				plus_d = (x + dx[dd]) * 5 + y + dy[dd];
				if (!visited[plus_d] && inSubG(plus_d))
				{
					queue_0[que_r++] = plus_d;
					visited[plus_d] = 1;
				}
			}
	}
	return (num1 + num2 == 7 && num1 < num2);
}

int main()
{
	Count = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> g[i][j];
	int ii[7];
	for (ii[0] = 0; ii[0] < 19; ++ii[0])
		for (ii[1] = ii[0] + 1; ii[1] < ii[0] + 6 && ii[1] < 20; ++ii[1])
			for (ii[2] = ii[1] + 1; ii[2] < ii[1] + 6 && ii[2] < 21; ++ii[2])
				for (ii[3] = ii[2] + 1; ii[3] < ii[2] + 6 && ii[3] < 22; ++ii[3])
					for (ii[4] = ii[3] + 1; ii[4] < ii[3] + 6 && ii[4] < 23; ++ii[4])
						for (ii[5] = ii[4] + 1; ii[5] < ii[4] + 6 && ii[5] < 24; ++ii[5])
							for (ii[6] = ii[5] + 1; ii[6] < ii[5] + 6 && ii[6] < 25; ++ii[6])
							{
								for (int jj = 0; jj < 7; ++jj)
									sub_g[jj] = ii[jj];
								if (check_sat()) ++Count;
							}
	cout << Count << endl;
	return 0;
}