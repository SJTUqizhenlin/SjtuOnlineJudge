#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int tmp;
int *height;
int *posi;
int *numo;
bool flag = false;

void set_heap(int i, int size)
{
	if (2 * i > size) return;
	if (2 * i + 1 > size)
	{
		if (height[i * 2] < height[i])
		{
			tmp = height[i];
			height[i] = height[i * 2];
			height[i * 2] = tmp;
			posi[numo[i]] = 2 * i;
			posi[numo[2 * i]] = i;
			tmp = numo[i];
			numo[i] = numo[2 * i];
			numo[2 * i] = tmp;
		}
	}
	else
	{
		if (height[i * 2] < height[i] && height[i * 2 + 1] < height[i])
		{
			if (height[i * 2] <= height[i * 2 + 1])
			{
				tmp = height[i];
				height[i] = height[i * 2];
				height[i * 2] = tmp;
				posi[numo[i]] = 2 * i;
				posi[numo[2 * i]] = i;
				tmp = numo[i];
				numo[i] = numo[2 * i];
				numo[2 * i] = tmp;
				set_heap(2 * i, size);
			}
			else
			{
				tmp = height[i];
				height[i] = height[i * 2 + 1];
				height[i * 2 + 1] = tmp;
				posi[numo[i]] = 2 * i + 1;
				posi[numo[2 * i + 1]] = i;
				tmp = numo[i];
				numo[i] = numo[2 * i + 1];
				numo[2 * i + 1] = tmp;
				set_heap(2 * i + 1, size);
			}
		}
		else if (height[i * 2] < height[i])
		{
			tmp = height[i];
			height[i] = height[i * 2];
			height[i * 2] = tmp;
			posi[numo[i]] = 2 * i;
			posi[numo[2 * i]] = i;
			tmp = numo[i];
			numo[i] = numo[2 * i];
			numo[2 * i] = tmp;
			set_heap(2 * i, size);
		}
		else if (height[i * 2 + 1] < height[i])
		{
			tmp = height[i];
			height[i] = height[i * 2 + 1];
			height[i * 2 + 1] = tmp;
			posi[numo[i]] = 2 * i + 1;
			posi[numo[2 * i + 1]] = i;
			tmp = numo[i];
			numo[i] = numo[2 * i + 1];
			numo[2 * i + 1] = tmp;
			set_heap(2 * i + 1, size);
		}
	}
}

void fixing(int i)
{
	if (i == 1) return;
	int mid = i / 2;
	if (height[i] < height[mid])
	{
		tmp = height[i];
		height[i] = height[mid];
		height[mid] = tmp;
		posi[numo[i]] = mid;
		posi[numo[mid]] = i;
		tmp = numo[i];
		numo[i] = numo[mid];
		numo[mid] = tmp;
		fixing(mid);
	}
}

void find_min(int x, int n, int res, int respos)
{
	int ndot = n;
	while (n)
	{
		tmp = height[n];
		height[n] = height[1];
		height[1] = tmp;
		posi[numo[1]] = n;
		posi[numo[n]] = 1;
		tmp = numo[1];
		numo[1] = numo[n];
		numo[n] = tmp;
		set_heap(1, n - 1);
		if (height[n] > x && !flag)
		{
			res = height[n];
			respos = numo[n];
			flag = true;
		}
		else if (flag && height[n] == res)
		{
			if (numo[n] < respos)
				respos = numo[n];
		}
		else if (flag && height[n] > res)
		{
			while (n <= ndot)
			{
				fixing(n);
				n++;
			}
			printf("%d\n", respos);
			flag = false;
			break;
		}
		if (n == 1)
		{
			while (n <= ndot)
			{
				fixing(n);
				n++;
			}
			printf("%d\n", respos);
			flag = false;
			break;
		}
		n--;
	}
}

int main()
{
	int n;
	cin >> n;
	height = new int[n + 1];
	posi = new int[n + 1];
	numo = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &height[i]);
		posi[i] = i;
		numo[i] = i;
	}
	for (int i = n / 2; i > 0; i--)
	{
		set_heap(i, n);
	}
	string com;
	int a, b, x;
	while (cin >> com)
	{
		if (com == "findmin")
		{
			cin >> x;
			find_min(x, n, 0, -1);
		}
		if (com == "decrease")
		{
			cin >> a >> b;
			height[posi[a]] -= b;
			fixing(posi[a]);
		}
	}
	return 0;
}