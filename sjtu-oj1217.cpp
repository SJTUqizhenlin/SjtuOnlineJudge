#include <stdio.h>
#include <unordered_set>
#include <set>

using namespace std;

class uoset
{
private:
	static const int MOD = 30011;
	struct linrlist
	{
		int val; linrlist *next;
		linrlist() :val(0), next(nullptr) {};
		linrlist(int v) :val(v), next(nullptr) {};
	};
	linrlist hashtb[MOD];
public:
	uoset() {}
	void insert(int x)
	{
		linrlist *cur = &hashtb[x % MOD];
		while (cur->next) { if (cur->next->val == x) return; cur = cur->next; }
		cur->next = new linrlist(x);
	}
	bool find(int x)
	{
		linrlist *cur = &hashtb[x % MOD];
		while (cur->next) { if (cur->next->val == x) return true; cur = cur->next; }
		return false;
	}
};

int main()
{
	uoset uoset1;
	int n, m, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { scanf("%d", &tmp); uoset1.insert(tmp); }
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &tmp);
		if (uoset1.find(tmp)) printf("Y\n");
		else printf("N\n");
	}
	return 0;
}