#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	char s1[1005], s2[1005];
	scanf("%s", s1);
	scanf("%s", s2);
	int len = strlen(s1);
	int pos[2]; int diffnum = 0;
	bool flag = true;
	for (int i = 0; i < len; i++) {
		if (s1[i] != s2[i]) {
			if (diffnum < 2) { pos[diffnum] = i; diffnum++; }
			else { flag = false; break; }
		}
	}
	if (diffnum == 0) printf("YES\n");
	else {
		if (flag == false) printf("NO\n");
		else {
			if (diffnum == 1) printf("NO\n");
			else {
				if (s1[pos[0]] == s2[pos[1]] &&
					s2[pos[0]] == s1[pos[1]]) printf("YES\n");
				else printf("NO\n");
			}
		}
	}
	return 0;
}