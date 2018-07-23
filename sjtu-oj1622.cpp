#include <stdio.h>
using namespace std;

const int maxn = 210000;
int arr[maxn * 2 + 5];

int main()
{
	int N;
	int endpos[2] = { maxn + 1, maxn };
	int lstzero[2] = { 0, maxn * 2 + 1 };
	scanf("%d", &N);
	char order[10]; int onum;
	int direc = 1;
	for (int i = 0; i < N; i++)
	{
		scanf("%s", &order[0]);
		switch (order[2])
		{
		case 'S': //push
			scanf("%d", &onum);
			if (direc) arr[++endpos[direc]] = onum;
			else arr[--endpos[direc]] = onum;
			if (!onum)
			{
				lstzero[direc] = endpos[direc];
				if (lstzero[1 - direc] == (1 - direc) * (maxn * 2 + 1))
					lstzero[1 - direc] = endpos[direc];
			}
			break;
		case 'P': //pop
			if (!arr[endpos[direc]])
			{
				lstzero[direc] = direc * (maxn * 2 + 1);
				if (lstzero[1 - direc] == endpos[direc])
					lstzero[1 - direc] = (1 - direc) * (maxn * 2 + 1);
				else
				{
					if (direc)
					{
						int tmppos = endpos[direc] - 1;
						while (arr[tmppos]) --tmppos;
						lstzero[direc] = tmppos;
					}
					else
					{
						int tmppos = endpos[direc] + 1;
						while (arr[tmppos]) ++tmppos;
						lstzero[direc] = tmppos;
					}
				}
			}
			endpos[direc] += (direc ? (-1) : (1));
			break;
		case 'V': //reverse
			direc = 1 - direc;
			break;
		case 'E': //query
			if (endpos[1] < endpos[0]) printf("Invalid.\n");
			else
			{
				if (lstzero[0] == 0)
					printf("%d\n", ((endpos[1] - endpos[0] + 1) % 2 == 0 ? 0 : 1));
				else
					printf("%d\n", ((endpos[1 - direc] - lstzero[1 - direc]
						+ (lstzero[1 - direc] == endpos[direc])) % 2 == 0 ? 1 : 0));
			}
			break;
		default:
			break;
		}
	}
	return 0;
}

