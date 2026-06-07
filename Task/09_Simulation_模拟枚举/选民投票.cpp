#include <bits/stdc++.h>
using namespace std;
map<string,bool>mp;
struct People{
	string name;
	int cnt;
	string str;
	int pos;
};
bool cmp(People x,People y)
{
	if (x.cnt!=y.cnt) return x.cnt>y.cnt;
	return x.pos < y.pos;
}
int main()
{
	int n;
	cin >> n;
	People p[n+1];
	string inva[100000];
	int c = 1;
	for (int i=1;i<=n;i++)
	{
		cin >> p[i].name;
		string temp = p[i].name;
		for (int j=0;j<temp.length();j++)
		{
			if (temp[j]>='A'&&temp[j]<='Z')
			{
				temp[j] = tolower(temp[j]);
			}
		}
		p[i].str = temp;
		p[i].cnt = 0;
		p[i].pos = i;
	}
	int m;
	cin >> m;
	while (m--)
	{
		string na;
		cin >> na;
		string t = na;
		for (int i=0;i<na.length();i++)
		{
			if (na[i]>='A'&&na[i]<='Z') na[i] = tolower(na[i]);
		}
		int flag = 0;
		for (int i=1;i<=n;i++)
		{
			if (p[i].str==na)
			{
				p[i].cnt++;
				flag = 1;
				break;
			}
		}
		if (!flag&&!mp[t])
		{
			inva[c++] = t;
			mp[t] = 1;
		}
	}
	sort(p+1,p+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		cout << p[i].name << ':' << p[i].cnt << endl;
	}
	if (!inva[1].empty())
	{
		cout << endl << "invalid vote:" << endl;
		for (int i=1;i<c;i++)
		{
			cout << inva[i] << endl;
		}
	}
	return 0;
}
