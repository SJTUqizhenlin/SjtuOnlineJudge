#include <stdio.h>
#include <stdint.h>
#include <map>
#include <algorithm>

using namespace std;


const int minval = -100001;
int a[100005];
int b[100005];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	map<int, int> m;
	for (int i = 0; i < k; i++)
	{
		if (m.find(a[i]) != m.end()) m[a[i]]++;
		else m[a[i]] = 1;
	}
	map<int, int>::iterator it = m.lower_bound(minval);
	printf("%d ", it->first);
	for (int i = k; i < n; i++)
	{
		it = m.find(a[i - k]);
		if (it->second > 1) it->second--;
		else m.erase(it);
		if (m.find(a[i]) != m.end()) m[a[i]]++;
		else m[a[i]] = 1;
		it = m.lower_bound(minval);
		printf("%d ", it->first);
	}
	printf("\n");

	for (int i = 0; i < n; i++) a[i] = -a[i];
	m.clear();
	for (int i = 0; i < k; i++)
	{
		if (m.find(a[i]) != m.end()) m[a[i]]++;
		else m[a[i]] = 1;
	}
	it = m.lower_bound(minval);
	printf("%d ", (0 - it->first));
	for (int i = k; i < n; i++)
	{
		it = m.find(a[i - k]);
		if (it->second > 1) it->second--;
		else m.erase(it);
		if (m.find(a[i]) != m.end()) m[a[i]]++;
		else m[a[i]] = 1;
		it = m.lower_bound(minval);
		printf("%d ", (0 - it->first));
	}
	printf("\n");
	
	return 0;
}