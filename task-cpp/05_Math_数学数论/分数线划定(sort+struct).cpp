#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct People{
	int bmh;
	int grade;
};
bool cmp(People x,People y)
{
	if (x.grade!=y.grade) return x.grade > y.grade;
	else return x.bmh < y.bmh;
}
int main()
{
	int n,m;
	cin >> n >> m;
	People p[n+1];
	for (int i=1;i<=n;i++)
	{
		cin >> p[i].bmh >> p[i].grade;
	}
	sort(p+1,p+n+1,cmp);
	int fsx;
	int jh = (int)(1.5*m);
	fsx = p[jh].grade;
	int sj = 0;
	for (int i=1;i<=n;i++)
	{
		if (p[i].grade>=fsx) sj++;
		else break;
	}
	cout << fsx << ' ' << sj << endl;
	for (int i=1;i<=sj;i++)
		cout << p[i].bmh << ' ' << p[i].grade << endl;
	return 0;
}
