#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdio.h>

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

	int rcdssize = rcds.size();
	if (rcdssize == 0) cout << "Orz" << endl;
	else
	{
		for (int i = 0; i < rcdssize; i++)
			cout << rcds[i].spkid << " " << rcds[i].tgtid << " " << rcds[i].typenum << endl;
	}
	return 0;
}