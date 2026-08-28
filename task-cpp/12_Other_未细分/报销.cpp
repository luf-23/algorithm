#include <bits/stdc++.h>
using namespace std;
struct People{
	string name;
	int sum = 0;
	int pos;
	int rk;
};
bool cmp1(People x,People y)
{
	return x.sum >= y.sum;
}
bool cmp2(People x,People y)
{
	if (x.sum!=y.sum) return x.sum > y.sum;
	if (x.name!=y.name) return x.name < y.name;
	return x.pos < y.pos;
}
int main()
{
	int n,m;
	cin >> n >> m;
	People p[n+1];
	for (int i=1;i<=n;i++)
	{
		int t = m;
		cin >> p[i].name;
		p[i].pos = i;
		while (t--)
		{
			int x;
			cin >> x;
			p[i].sum += x;
		}
	}
	sort(p+1,p+n+1,cmp1);
	int now = 1;
	p[1].rk = 1;
	int t = 0;
	for (int i=2;i<=n;i++)
	{
		t++;
		if (p[i].sum<p[now].sum)
		{
			p[i].rk = p[now].rk + t;
			now = i;
			t = 0;
		}else{
			p[i].rk = p[now].rk;
		}
	}
	sort(p+1,p+n+1,cmp2);
	for (int i=1;i<=n;i++)
	{
		cout << p[i].rk << ' ' << p[i].pos << ' ' << p[i].name << ' ' << p[i].sum << endl;
	}
	return 0;
}
