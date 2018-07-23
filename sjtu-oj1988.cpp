#include <stdio.h>
//#include <unordered_map>
#include <string.h>
using namespace std;

const int MAXC = 512;
const int HALFC = 256;

class listNode {
public:
	listNode *nxt, *pre;
	int num_count;
	int *arr;
	//unordered_map<int, int> hashmap;
	int *hashmap;
	listNode() {
		nxt = nullptr; pre = nullptr;
		num_count = 0;
		arr = new int[MAXC];
		//hashmap.clear();
		hashmap = new int[10001];
		memset(hashmap, 0, sizeof(int) * 10001);
	}
	void insertFront(int x) {
		for (int i = num_count; i > 0; i--)
			arr[i] = arr[i - 1];
		arr[0] = x;
		++num_count;
		hashmap[x] += 1;
		return;
	}
	void insertBack(int x) {
		arr[num_count] = x;
		++num_count;
		hashmap[x] += 1;
		return;
	}
	void deleteAt(int x) {
		int i = 0;
		for (i; i < num_count; i++)
			if (arr[i] == x) break;
		for (int j = i; j + 1 < num_count; j++)
			arr[j] = arr[j + 1];
		--num_count;
		hashmap[x] -= 1;
		return;
	}
	void insertAfter(int x, int y) {
		int i = 0;
		for (i; i < num_count; i++)
			if (arr[i] == x) break;
		i++;
		for (int j = num_count; j > i; j--)
			arr[j] = arr[j - 1];
		arr[i] = y; num_count++;
		hashmap[y] += 1;
		return;
	}
};

class MyList {
public:
	listNode *beg, *end;
	MyList() {
		beg = new listNode();
		end = new listNode();
		beg->nxt = end; end->pre = beg;
	}
	void insertFront(int x) {
		beg->insertFront(x);
		if (beg->num_count == MAXC) {
			listNode *tmp = new listNode();
			for (int i = 0; i < HALFC; i++) {
				tmp->arr[i] = beg->arr[HALFC + i];
				beg->hashmap[beg->arr[HALFC + i]] -= 1;
				tmp->hashmap[tmp->arr[i]] += 1;
			}
			beg->num_count = HALFC;
			tmp->num_count = HALFC;
			tmp->nxt = beg->nxt; tmp->pre = beg;
			tmp->nxt->pre = tmp;
			tmp->pre->nxt = tmp;
		} return;
	}
	void insertBack(int x) {
		listNode *tail = end->pre;
		tail->insertBack(x);
		if (tail->num_count == MAXC) {
			listNode *tmp = new listNode();
			for (int i = 0; i < HALFC; i++) {
				tmp->arr[i] = tail->arr[HALFC + i];
				tail->hashmap[tail->arr[HALFC + i]] -= 1;
				tmp->hashmap[tmp->arr[i]] += 1;
			}
			tail->num_count = HALFC;
			tmp->num_count = HALFC;
			tmp->nxt = end; tmp->pre = end->pre;
			tmp->nxt->pre = tmp;
			tmp->pre->nxt = tmp;
		} return;
	}
	void deleteAt(int x) {
		listNode *cur = beg;
		while (cur != end && cur->hashmap[x] == 0)
			cur = cur->nxt;
		if (cur == end) return;
		cur->deleteAt(x); return;
	}
	void insertAfter(int x, int y) {
		listNode *cur = beg;
		while (cur != end && cur->hashmap[x] == 0)
			cur = cur->nxt;
		if (cur == end) return;
		cur->insertAfter(x, y);
		if (cur->num_count == MAXC) {
			listNode *tmp = new listNode();
			for (int i = 0; i < HALFC; i++) {
				tmp->arr[i] = cur->arr[HALFC + i];
				cur->hashmap[cur->arr[HALFC + i]] -= 1;
				tmp->hashmap[tmp->arr[i]] += 1;
			}
			cur->num_count = HALFC;
			tmp->num_count = HALFC;
			tmp->nxt = cur->nxt; tmp->pre = cur;
			tmp->nxt->pre = tmp;
			tmp->pre->nxt = tmp;
		} return;
	}
};

int main() {
	MyList l;
	int N, M, x, y;
	char op;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		l.insertBack(x);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%c", &op);
		while (!(op >= 'A' && op <= 'D'))
			scanf("%c", &op);
		if (op == 'A') {
			scanf("%d", &x);
			l.insertFront(x);
		}
		if (op == 'B') {
			scanf("%d", &x);
			l.insertBack(x);
		}
		if (op == 'C') {
			scanf("%d", &x);
			l.deleteAt(x);
		}
		if (op == 'D') {
			scanf("%d%d", &x, &y);
			l.insertAfter(x, y);
		}
	}
	int res = 0;
	listNode *cur = l.beg;
	while (cur != l.end) {
		res += cur->num_count;
		cur = cur->nxt;
	}
	printf("%d\n", res);
	cur = l.beg;
	while (cur != l.end) {
		for (int i = 0; i < cur->num_count; i++)
			printf("%d ", cur->arr[i]);
		cur = cur->nxt;
	}
	printf("\n");
	return 0;
}