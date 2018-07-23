#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct student
{
	int order;
	string name;
	string number;
	int grade;
	student(int order, string number, string name, int grade)
	{
		this->order = order;
		this->number = number;
		this->name = name;
		this->grade = grade;
	}
};

bool cmp1(student s1, student s2)
{
	return s1.number < s2.number;
}

bool cmp2(student s1, student s2)
{
	if (s1.grade != s2.grade)
		return s1.grade > s2.grade;
	return s1.order < s2.order;
}

int main()
{
	vector<student> v;
	set<string> store;
	int n = 0;
	char ch = '0';
	string newnum, newname;
	int newgrade;
	while (ch != '7')
	{
		cin >> ch;
		if (ch == '1')
		{
			cin >> newnum >> newname >> newgrade;
			if (store.find(newnum) == store.end())
			{
				n++;
				store.insert(newnum);
				student newstu(n, newnum, newname, newgrade);
				v.push_back(newstu);
				cout << "SUCCESS" << endl;
			}
			else
			{
				cout << "FAILED" << endl;
			}
		}
		if (ch == '2')
		{
			if (v.size() > 0)
				for (int i = 0; i < v.size(); i++)
					cout << v[i].number << ' ' << v[i].name << ' ' << v[i].grade << endl;
		}
		if (ch == '3')
		{
			cin >> newname;
			for (int i = 0; i < v.size(); i++)
				if (v[i].number == newnum)
				{
					cout << v[i].number << ' ' << v[i].name << ' ' << v[i].grade << endl;
					break;
				}
		}
		if (ch == '4')
		{
			cin >> newname;
			for (int i = 0; i < v.size(); i++)
				if (v[i].name == newname)
				{
					cout << v[i].number << ' ' << v[i].name << ' ' << v[i].grade << endl;
					break;
				}
		}
		if (ch == '5')
		{
			if (v.size() != 0)
			{
				vector<student> v1(v);
				sort(v1.begin(), v1.end(), cmp1);
				for (int i = 0; i < v1.size(); i++)
					cout << v1[i].number << ' ' << v1[i].name << ' ' << v1[i].grade << endl;
			}
		}
		if (ch == '6')
		{
			if (v.size() != 0)
			{
				vector<student> v2(v);
				sort(v2.begin(), v2.end(), cmp2);
				for (int i = 0; i < v2.size(); i++)
					cout << v2[i].number << ' ' << v2[i].name << ' ' << v2[i].grade << endl;
			}
		}
	}
	cout << "END";
	return 0;
}