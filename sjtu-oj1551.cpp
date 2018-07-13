//Attention!
//This problem doesn't tell us, but the p's array is increasing.
#include <stdio.h>
#include <stack>
using namespace std;


int main() {
	stack<int> s;
	int N; scanf("%d", &N);
	int p, v;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &p, &v);
		while (!s.empty() && s.top() > v)
			s.pop();
		s.push(v);
	}
	printf("%d\n", (s.size()));
	return 0;
}