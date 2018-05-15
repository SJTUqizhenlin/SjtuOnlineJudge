#include <iostream>
#include <stdio.h>

using namespace std;

struct LinkedList
{
	int value;
	LinkedList *next;
	LinkedList(int v)
		:value(v), next(NULL) {}
};

int main()
{
	int N;
	cin >> N;
	int tmpint;
	LinkedList header(0);
	LinkedList *cur = &header;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tmpint);
		LinkedList *newnode = new LinkedList(tmpint);
		cur->next = newnode;
		cur = cur->next;
	}
	int M;
	cin >> M;
	int count = 0;
	LinkedList buffer = LinkedList(0);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &tmpint);
		cur = &header;
		while (cur->next != NULL)
		{
			count++;
			if (tmpint == cur->next->value)
			{
				buffer.next = cur->next;
				cur->next = cur->next->next;
				buffer.next->next = header.next;
				header.next = buffer.next;
				break;
			}
			cur = cur->next;
		}
	}
	cout << count << endl;
	return 0;
}