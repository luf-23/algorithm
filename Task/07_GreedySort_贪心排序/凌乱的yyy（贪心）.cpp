#include <bits/stdc++.h>
using namespace std;
struct Time {
	int s,e;
	int cost;
};
bool cmp (Time x,Time y)
{
	return x.e <= y.e;
}
int main()
{
	int n;
	cin >> n;
	Time t[n+1];
	t[0].s = 0;
	t[0].e = 0;
	for (int i=1;i<=n;i++)
	{
		cin >> t[i].s >> t[i].e;
		t[i].cost = t[i].e - t[i].s;
	}
	sort(t+1,t+n+1,cmp);
	int cnt = 0;
	int pos = 0;
	for (int i=1;i<=n;i++)
	{
		if (pos<=t[i].s)
		{
			cnt++;
			pos = t[i].e;
		}
	}
	cout << cnt << endl;
	return 0;
}

