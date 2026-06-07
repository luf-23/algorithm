#include <bits/stdc++.h>
using namespace std;
struct People{
	int xuhao;
	string ps;
};

bool cmp(People x,People y)
{
	if (x.ps.length()!=y.ps.length()) return x.ps.length() > y.ps.length();
	else{
		for (int i=0;i<x.ps.length();i++)
		{
			if (x.ps[i]!=y.ps[i]) return x.ps[i] > y.ps[i];
		}
	}
}

int main()
{
	int n;
	cin >> n;
	People p[n+1];
	for (int i=1;i<=n;i++)
	{
		cin >> p[i].ps;
		p[i].xuhao = i;
	}
	sort(p+1,p+n+1,cmp);
	cout << p[1].xuhao << endl << p[1].ps;
	return 0;
}
