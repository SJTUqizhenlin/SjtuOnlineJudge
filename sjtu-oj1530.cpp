#include <stdio.h>
using namespace std;

char srcarr[1000005];
char resarr[1000005];
int N;

void init_arr()
{
	for (int i = 0; i <= N + 1; i++)
	{
		srcarr[i] = 0;
		resarr[i] = 0;
	}
	return;
}

void inorder(int x, int &y)
{
	if (x * 2 <= N) inorder(x * 2, y);
	resarr[y] = srcarr[x]; ++y;
	if (x * 2 + 1 <= N) inorder(x * 2 + 1, y);
	return;
}

void preorder(int x, int &y)
{
	resarr[y] = srcarr[x]; ++y;
	if (x * 2 <= N) preorder(x * 2, y);
	if (x * 2 + 1 <= N) preorder(x * 2 + 1, y);
	return;
}

void postorder(int x, int &y)
{
	if (x * 2 <= N) postorder(x * 2, y);
	if (x * 2 + 1 <= N) postorder(x * 2 + 1, y);
	resarr[y] = srcarr[x]; ++y;
	return;
}

void r_inorder(int bg, int ed, int p)
{
	int x = 1; while (x << 1 <= ed - bg) x = (x << 1) + 1;
	int mid;
	if (ed - bg - x <= x >> 1) mid = ed - (x >> 1);
	else mid = bg + x;
	resarr[p] = srcarr[mid];
	if (mid > bg) r_inorder(bg, mid - 1, p << 1);
	if (mid < ed) r_inorder(mid + 1, ed, (p << 1) + 1);
	return;
}

void r_preorder(int bg, int ed, int p)
{
	resarr[p] = srcarr[bg];
	int x = 1; while (x << 1 <= ed - bg) x = (x << 1) + 1;
	int mid;
	if (ed - bg - x <= x >> 1) mid = ed - (x >> 1);
	else mid = bg + x;
	if (mid > bg) r_preorder(bg + 1, mid, p << 1);
	if (mid < ed) r_preorder(mid + 1, ed, (p << 1) + 1);
	return;
}

void r_postorder(int bg, int ed, int p)
{
	resarr[p] = srcarr[ed];
	int x = 1; while (x << 1 <= ed - bg) x = (x << 1) + 1;
	int mid;
	if (ed - bg - x <= x >> 1) mid = ed - (x >> 1);
	else mid = bg + x;
	if (mid > bg) r_postorder(bg, mid - 1, p << 1);
	if (ed > mid) r_postorder(mid, ed - 1, (p << 1) + 1);
	return;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		char o1[20]; char o2[20];
		scanf("%s", &o1); scanf("%s", &o2);
		init_arr();
		scanf("%s", &srcarr[1]);
		if (o2[1] == 'N') //ENCODE
		{
			if (o1[1] == 'N') { int x = 1, y = 1; inorder(x, y); }//INORDER
			if (o1[1] == 'R') { int x = 1, y = 1; preorder(x, y); }//PREORDER
			if (o1[1] == 'O') { int x = 1, y = 1; postorder(x, y); }//POSTORDER
		}
		else //DECODE
		{
			if (o1[1] == 'N') r_inorder(1, N, 1);//INORDER
			if (o1[1] == 'R') r_preorder(1, N, 1);//PREORDER
			if (o1[1] == 'O') r_postorder(1, N, 1);//POSTORDER
		}
		printf("%s\n", &resarr[1]);
	}
	return 0;
}