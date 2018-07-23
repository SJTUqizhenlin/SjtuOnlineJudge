#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int n;
char str[2005];

void solve()
{
	int cnt = 0;
	int a = 0, b = n - 1;
	while (a <= b)
	{
		bool left = false;
		for (int i = 0; a + i <= b; i++) {
			if (str[a + i]<str[b - i]) {
				left = true;
				cnt++;
				break;
			}
			else if (str[a + i]>str[b - i]) {
				cnt++;
				left = false;
				break;
			}
		}
		if (left)putchar(str[a++]);
		else putchar(str[b--]);
		if (cnt % 80 == 0) printf("\n");
	}
	printf("\n");
}

int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 0; i<n; i++)
		{
			cin >> str[i];
		}
		solve();
	}
	return 0;
}