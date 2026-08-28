#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m;
	cin >> n >> m;
	ll num[n+1];
	map<ll,bool> mp;
	for (int i=1;i<=n;i++)
		cin >> num[i];
	ll x;
	for (int i=1;i<=m;i++)
	{
		cin >> x;
		mp[x] = 1;
	}
	bool book[n+1] = {0};
	for (int i=1;i<=n;i++)
	{
		if (mp.find(num[i])!=mp.end()) book[i] = 1;
	}
	ll cnt = 0;
	int flag = 1;
	for (int i=1;i<=n;i++)
	{
		if (book[i]==0)
		{
			if (flag==1)
			{
				cnt++;
				flag = 0;
			}
		}
		if (book[i]==1) flag = 1;
	}
	cout << cnt;
}
