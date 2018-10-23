#include <iostream>

using namespace std;

class listnode {
public:
	const static int M = 150;
	int arr[M + 3];
	int cur;
	listnode* nxt;
	listnode* pre;
	listnode() {
		arr[0] = 0;
		cur = 0;
		nxt = nullptr; pre = nullptr;
	}
	void delatcur() {
		for (int i = cur; i < arr[0]; i++)
			arr[i] = arr[i + 1];
		arr[0] -= 1;
		return;
	}
	void addbehind(int w) {
		for (int i = arr[0]; i > cur; i--)
			arr[i + 1] = arr[i];
		arr[cur + 1] = w;
		cur += 1;
		arr[0] += 1;
		return;
	}
};

class linklist {
public:
	listnode* head;
	listnode* cur;
	int Count = 0;
	linklist() {
		head = new listnode();
		cur = head;
		head->addbehind(1);
		Count = 1;
	}
	void setbeg() {
		cur->cur = 0;
		head->cur = 1;
		cur = head;
		return;
	}
	void add(int w) {
		cur->addbehind(w);
		if (cur->arr[0] == cur->M) {
			listnode* tmp = new listnode();
			int half = (cur->M) / 2;
			tmp->arr[0] = half;
			for (int i = 1; i <= half; i++) {
				tmp->arr[i] = cur->arr[i + half];
			}
			cur->arr[0] = half;
			tmp->nxt = cur->nxt;
			tmp->pre = cur;
			if (tmp->nxt) tmp->nxt->pre = tmp;
			cur->nxt = tmp;
			if (cur->cur > half) {
				tmp->cur = cur->cur - half;
				cur->cur = 0;
				cur = cur->nxt;
			}
		}
		Count += 1;
		return;
	}
	void del() {
		cur->delatcur();
		if (cur->arr[0] == 0) {
			listnode* PRE = cur->pre;
			if (!PRE) {
				head = cur->nxt;
				head->pre = nullptr;
				cur->nxt->cur = 1;
				cur = cur->nxt;
			}
			else {
				listnode* NXT = cur->nxt;
				PRE->nxt = NXT;
				if (NXT) {
					NXT->pre = PRE;
					NXT->cur = 1;
					cur = NXT;
				}
				else {
					head->cur = 1;
					cur = head;
				}
			}
		}
		else {
			if (cur->cur > cur->arr[0]) {
				if (cur->nxt) {
					cur->nxt->cur = 1;
					cur->cur = 0;
					cur = cur->nxt;
				}
				else {
					cur->cur = 0;
					head->cur = 1;
					cur = head;
				}
			}
		}
		Count -= 1;
		return;
	}
	void walk(int k) {
		k = k % Count;
		if ((cur->cur) + k <= cur->arr[0]) {
			cur->cur += k;
			return;
		}
		k -= (cur->arr[0] - cur->cur);
		cur->cur = 0;
		if (cur->nxt) cur = cur->nxt;
		else cur = head;
		while (k > cur->arr[0]) {
			k -= cur->arr[0];
			cur->cur = 0;
			if (cur->nxt) cur = cur->nxt;
			else cur = head;
		}
		cur->cur = k;
		return;
	}
	int getsum() {
		int ret = 0;
		listnode* tmp = head;
		while (tmp) {
			for (int i = 1; i <= tmp->arr[0]; i++) {
				//cout << tmp->arr[i] << " ";
				ret += tmp->arr[i];
			}
			//cout << endl;
			tmp = tmp->nxt;
		}
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	int N, M;
	cin >> N >> M;
	linklist* l = new linklist();
	for (int i = 2; i <= N; i++) l->add(i);
	l->setbeg();
	int o, k, w;
	for (int i = 0; i < M; i++) {
		cin >> o;
		if (o == 0) {
			cin >> k;
			l->walk(k - 1);
			l->del();
		}
		else {
			cin >> k >> w;
			l->walk(k - 1);
			l->add(w);
		}
		//l->getsum();
	}
	cout << l->getsum() << endl;
	return 0;
}