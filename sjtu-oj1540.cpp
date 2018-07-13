#include <stdio.h>
#include <algorithm>
using namespace std;

class HashMap {
public:
	class record {
	public:
		char name[35];
		int num; record* next;
		record(char *s) {
			int i = -1;
			do {
				++i; name[i] = s[i];
			} while (s[i] != '\0');
			num = 1; next = nullptr;
		}
		record() {
			name[0] = '\0';
			num = 0; next = nullptr;
		}
	};

	bool isSame(char *s1, char *s2) {
		int i1 = 0, i2 = 0;
		while (s1[i1] != '\0' && s2[i2] != '\0') {
			if (s1[i1] != s2[i2]) return false;
			i1++; i2++;
		}
		if (s1[i1] == '\0' && s2[i2] == '\0') return true;
		else return false;
	}

	static const int MapSize = 10007;
	record arr[MapSize];
	
	HashMap() {}

	int HashCode(char *s) {
		int res = 1;
		for (int i = 0; s[i] != '\0'; i++)
			res = (res * (int)(s[i])) % MapSize;
		return res;
	}

	void insert(char *s) {
		int tmp = HashCode(s);
		record* cur = &(arr[tmp]);
		while (cur->next != nullptr && !isSame(cur->next->name, s)) 
			cur = cur->next;
		if (cur->next == nullptr) cur->next = new record(s);
		else cur->next->num += 1;
		return;
	}
};

int getstring(char *s, char c)
{
	c = getchar();
	if (c == EOF) return 0;
	int i = 0;
	while (c != '\n' && c != EOF) { 
		s[i] = c; i++; 
		c = getchar();
	}
	s[i] = '\0'; 
	if (c == '\n') return 1;
	else return 2;
}

HashMap h;
HashMap::record* store[10005];
int totsp = -1;

void fill_store() {
	HashMap::record *cur;
	for (int i = 0; i < h.MapSize; i++) {
		cur = (h.arr[i]).next;
		while (cur != nullptr) {
			store[++totsp] = new HashMap::record(cur->name);
			store[totsp]->num = cur->num;
			cur = cur->next;
		}
	} return;
}

bool cmp(const HashMap::record *a, const HashMap::record *b) {
	for (int i = 0; a->name[i] || b->name[i]; i++) {
		if (a->name[i] < b->name[i]) return true;
		else {
			if (a->name[i] > b->name[i]) return false;
		}
	}
	return false;
}

int main()
{
	char *s = new char[35];
	char c = 0;
	int totnum = 0;
	int scanflag;
	while (true) {
		scanflag = getstring(s, c);
		if (scanflag == 0) break;
		h.insert(s); totnum++;
		if (scanflag == 2) break;
	}
	fill_store();
	sort(store, store + totsp + 1, cmp);
	double ratio = 0;
	for (int i = 0; i <= totsp; i++) {
		ratio = store[i]->num * 100.0 / totnum;
		printf("%s %.4f\n", store[i]->name, ratio);
	}
	return 0;
}


//TO FIND a prime number(greater than fixed num)

//#include <iostream>
//using namespace std;
//
//bool isPrime(int x)
//{
//	for (int i = 2; i * i <= x; i++)
//		if (x % i == 0) return false;
//	return true;
//}
//
//int main()
//{
//	int x = 10000;
//	while (!isPrime(x)) x++;
//	cout << x; return 0;
//}