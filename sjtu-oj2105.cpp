#include <stdio.h>
#include <stack>
using namespace std;

long long arr[100005];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
	stack<int> st;
	st.push(0);
	long long res = 0, tmp = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] >= arr[st.top()])
		{
			st.push(i);
		}
		else
		{
			while (arr[i] < arr[st.top()])
			{
				tmp = arr[st.top()]; st.pop();
				tmp *= (i - st.top() - 1);
				if (tmp > res) res = tmp;
			}
			st.push(i);
		}
	}
	while (0 < arr[st.top()])
	{
		tmp = arr[st.top()]; st.pop();
		tmp *= (n - st.top());
		if (tmp > res) res = tmp;
	}
	printf("%lld\n", res);
	return 0;
}