#include <stdio.h>
using namespace std;

const int maxn = 100005;
const int boundt = 9; //by experiment
int arr[maxn], n, m;

struct segtr
{
	int left, right, times;
	long long val;
	segtr() :left(0), right(0), times(0), val(0) {}
};
segtr tr[maxn * 4];

long long transForm(long long x)
{
	long long res = 1;
	while (x)
	{
		res *= (x % 10 + 1);
		x /= 10;
	}
	return (res - 1);
}

void update_in(int no)
{
	tr[no].val = tr[no << 1].val + tr[(no << 1) + 1].val;
	return;
}

void build_tr(int no, int l, int r)
{
	tr[no].left = l;
	tr[no].right = r;
	if (l == r) { tr[no].val = arr[l]; return; }
	int mid = (l + r) >> 1;
	build_tr(no << 1, l, mid);
	build_tr((no << 1) + 1, mid + 1, r);
	update_in(no);
	return;
}

void change_in(int no, int a, int b)
{
	if (tr[no].left >= a && tr[no].right <= b)
	{
		tr[no].times++;
		if (tr[no].left == tr[no].right)
		{
			tr[no].val = transForm(tr[no].val);
			return;
		}
	}
	int mid = (tr[no].left + tr[no].right) >> 1;
	if (tr[no << 1].times < boundt && a <= mid)
		change_in(no << 1, a, b);
	if (tr[(no << 1) + 1].times < boundt && b > mid)
		change_in((no << 1) + 1, a, b);
	update_in(no);
	return;
}

long long query_sum(int no, int a, int b)
{
	if (a <= tr[no].left && b >= tr[no].right)
		return tr[no].val;
	long long ans = 0;
	int mid = (tr[no].left + tr[no].right) >> 1;
	if (a <= mid) ans += query_sum(no << 1, a, b);
	if (b > mid) ans += query_sum((no << 1) + 1, a, b);
	return ans;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	scanf("%d", &m);
	build_tr(1, 1, n);
	int od, a, b;
	while (m--)
	{
		scanf("%d%d%d", &od, &a, &b);
		if (od == 0) change_in(1, a, b);
		else printf("%lld\n", query_sum(1, a, b));
	}
	return 0;
}