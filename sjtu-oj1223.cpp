#include <stdio.h>
#include <algorithm>

using namespace std;

struct fishtank
{
	int id, strength, score;
	fishtank()
		:id(0), strength(0), score(0) {}
	fishtank(int iid, int istrength, int iscore)
		:id(iid), strength(istrength), score(iscore) {}
	bool operator<(const fishtank &rhs) const
	{
		if (score == rhs.score) return id < rhs.id;
		return score > rhs.score;
	}
};

fishtank arr[200005];

int main()
{
	int n, r; scanf("%d%d", &n, &r);
	for (int i = 1; i <= n * 2; i++) { scanf("%d", &arr[i].score); arr[i].id = i; }
	for (int i = 1; i <= n * 2; i++) scanf("%d", &arr[i].strength);
	sort(arr + 1, arr + n * 2 + 1);
	for (int t = 0; t < r; t++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (arr[2 * i - 1].strength > arr[2 * i].strength)
				arr[2 * i - 1].score++;
			else arr[2 * i].score++;
		}
		sort(arr + 1, arr + n * 2 + 1);
	}
	for (int i = 1; i <= n * 2; i++) printf("%d ", arr[i].id);
	printf("\n");
	return 0;
}