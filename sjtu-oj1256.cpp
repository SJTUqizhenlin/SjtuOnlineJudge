#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct tri_rcd
{
	int spkid, tgtid, typenum;
	tri_rcd() :spkid(-1), tgtid(-1), typenum(-1) {}
	tri_rcd(int sspkid, int ttgtid, int ttypenum)
		:spkid(sspkid), tgtid(ttgtid), typenum(ttypenum) {}
};

string WeekDay[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
unordered_map<string, int> idofname;
vector<string> nameofid;
vector<tri_rcd> rcds;
int ishonest[10];
int ispossib[10];
int possibweekday[7];

int isWeekDay(string s)
{
	for (int i = 0; i < 7; i++)
		if (s == WeekDay[i]) return (i + 1);
	return 0;
}

void init_nameNid(int M)
{
	for (int i = 0; i < M; i++)
	{
		string tmpname;
		getline(cin, tmpname);
		nameofid.push_back(tmpname);
		idofname[tmpname] = i;
	}
	return;
}

void ana_sente(int spkid, string sente)
{
	if (sente == "I have the ring.")
	{
		rcds.push_back(tri_rcd(spkid, spkid, 1));
		return;
	}
	if (sente == "I have not the ring.")
	{
		rcds.push_back(tri_rcd(spkid, spkid, 2));
		return;
	}
	int midpos = sente.find(' ');
	int sentelen = sente.length();
	if (midpos == string::npos) return;
	string fstword = sente.substr(0, midpos);
	if (fstword == "Today")
		if (sente.substr(midpos, 4) == " is ")
		{
			int weekdaynum = isWeekDay(sente.substr(midpos + 4, sentelen - midpos - 5));
			if (weekdaynum > 0)
			{
				rcds.push_back(tri_rcd(spkid, weekdaynum, 3));
				return;
			}
		}
	if (idofname.find(fstword) != idofname.end())
	{
		string restsente = sente.substr(midpos + 1);
		if (restsente == "has the ring.")
			rcds.push_back(tri_rcd(spkid, idofname[fstword], 1));
		if (restsente == "has not the ring.")
			rcds.push_back(tri_rcd(spkid, idofname[fstword], 2));
	}
	return;
}

void deal_with(string respon)
{
	int midpos = respon.find(':');
	int id = idofname[respon.substr(0, midpos)];
	string sente = respon.substr(midpos + 2);
	ana_sente(id, sente);
	return;
}

bool reduce_possib(int M)
{
	int rcdssize = rcds.size();
	for (int i = 0; i < rcdssize; i++)
	{
		tri_rcd tmp = rcds[i];
		if (ishonest[tmp.spkid] == 1)
		{
			if (tmp.typenum == 3)
			{
				if (possibweekday[tmp.tgtid - 1] == 0)
					possibweekday[tmp.tgtid - 1] = 1;
				else
					if (possibweekday[tmp.tgtid - 1] == 2)
						return false;
			}
			else
			{
				if (ispossib[tmp.tgtid] == 0)
					ispossib[tmp.tgtid] = tmp.typenum;
				else
					if (ispossib[tmp.tgtid] != tmp.typenum)
						return false;
			}
		}
		else
		{
			if (tmp.typenum == 3)
			{
				if (possibweekday[tmp.tgtid - 1] == 0)
					possibweekday[tmp.tgtid - 1] = 2;
				else
					if (possibweekday[tmp.tgtid - 1] == 1)
						return false;
			}
			else
			{
				if (ispossib[tmp.tgtid] == 0)
					ispossib[tmp.tgtid] = 3 - tmp.typenum;
				else
					if (ispossib[tmp.tgtid] != 3 - tmp.typenum)
						return false;
			}
		}
	}
	return true;
}

int main()
{
	int M, N, P; cin >> M >> N >> P;
	char echar = getchar();

	init_nameNid(M);

	for (int i = 0; i < P; i++)
	{
		string respon;
		getline(cin, respon);
		deal_with(respon);
	}

	for (int i = 0; i < N; i++) ishonest[i] = 0;
	for (int i = N; i < M; i++) ishonest[i] = 1;
	bool hasvalid_permutation = false;
	bool is_confused = false;
	int foundres = -1;
	do
	{
		for (int i = 0; i < M; i++) ispossib[i] = 0;
		for (int i = 0; i < 7; i++) possibweekday[i] = 0;
		bool avalid = reduce_possib(M);
		if (avalid)
		{
			int numof1 = 0, numof2 = 0, numofwd = 0, numofnotwd = 0;
			for (int i = 0; i < M; i++)
			{
				if (ispossib[i] == 1) numof1++;
				if (ispossib[i] == 2) numof2++;
			}
			for (int i = 0; i < 7; i++)
			{
				if (possibweekday[i] == 1) numofwd++;
				if (possibweekday[i] == 2) numofnotwd++;
			}
			if ((numof2 < M && numof1 < 2) && (numofnotwd < 7 && numofwd < 2))
			{
				hasvalid_permutation = true;
				if (numof1 == 0 && numof2 < M - 1)
					is_confused = true;
				else
				{
					if (numof2 == M - 1)
						for (int i = 0; i < M; i++) if (ispossib[i] != 2) ispossib[i] = 1;
					int res = -1;
					for (int i = 0; i < M; i++) if (ispossib[i] == 1) res = i;
					if (foundres == -1)
						foundres = res;
					else
						if (foundres != res) is_confused = true;
				}
			}
		}
	} while (next_permutation(ishonest, ishonest + M));
	if (!hasvalid_permutation) cout << "It is impossible!" << endl;
	else
	{
		if (is_confused) 
			cout << "I am confused." << endl;
		else
			cout << nameofid[foundres] << endl;
	}
	return 0;
}