#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int pic[1010][1010], w, h;
char line[1010];

void find_center(double &cx, double &cy)
{
	double sumx = 0, sumy = 0; int count_n = 0;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			if (pic[i][j] == 1)
			{
				sumx += i;
				sumy += j;
				count_n++;
			}
	cx = sumx / count_n;
	cy = sumy / count_n;
	return;
}

bool isEdge(int x, int y)
{
	int s = 0;
	s += pic[x][y]; s += pic[x][y + 1];
	s += pic[x + 1][y]; s += pic[x + 1][y + 1];
	if (s == 4 || s == 0) return false;
	return true;
}

void min_max_dist(double &mindist, double &maxdist,
	double cx, double cy)
{
	double a_dist = 0, deltx = 0, delty = 0;
	for (int i = 1; i < h; i++)
		for (int j = 1; j < w; j++)
		{
			if (isEdge(i, j))
			{
				deltx = i + 0.5 - cx;
				delty = j + 0.5 - cy;
				a_dist = sqrt(deltx * deltx + delty * delty);
				if (a_dist > maxdist)
					maxdist = a_dist;
				if (a_dist < mindist)
					mindist = a_dist;
			}
		}
	return;
}

int main()
{
	cin >> w >> h;
	for (int i = 1; i <= h; i++)
	{
		scanf("%s", line);
		for (int j = 1; j <= w; j++)
			pic[i][j] = line[j - 1] - '0';
	}
	double cx, cy;
	find_center(cx, cy);
	double mindist = 2000, maxdist = 0;
	min_max_dist(mindist, maxdist, cx, cy);
	double ratio = maxdist / mindist;
	if (ratio < 1.2) cout << "circle\n"; //expect 1.0
	else
	{
		if (ratio < 1.6) cout << "square\n"; //expect 1.414
		else cout << "triangle\n";
	}
	return 0;
}
