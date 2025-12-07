#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ll num[n+1];
		for (int i=1;i<=n;i++)
			cin >> num[i];
		sort(num+1,num+n+1);
		map<ll,ll>mp;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<=n;j+=num[i])
			{
				mp[j]++;
			}
		}
		ll ans = 0;
		for (map<ll,ll>::iterator it=mp.begin();it!=mp.end();++it)
		{
			if (it->first!=0)
				ans = max(ans,it->second);
		}
		cout << ans << '\n';
	}
	return 0;
}
