#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ivec(1000, 0);
const int maxval = 40000001;

int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &ivec[i]);
	sort(ivec.begin(), ivec.begin() + n);
	int tmp;
	if (ivec[0] == 1)
	{
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &tmp);
			printf("YES\n");
		}
	}
	else
	{
		int base = ivec[0];
		int *rest = new int[base];
		for (int i = 1; i < base; i++) rest[i] = maxval;
		rest[0] = 0;
		for (int i = 1; i < n; i++)
			if (ivec[i] % base)
			{
				for (int j = 1; j < base; j++)
				{
					for (int k = 0; k < base; k++)
						if (j * ivec[i] + rest[k] < rest[(j * ivec[i] + rest[k]) % base])
							rest[(j * ivec[i] + rest[k]) % base] = j * ivec[i] + rest[k];
				}
			}
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &tmp);
			if (tmp >= rest[tmp % base]) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}