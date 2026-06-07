#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n,m;
		cin >> n >> m;
		ll a[n+1];
		ll b[m+1];
		ll sa[n+1];
		ll sb[m+1];
		sa[0] = sb[0] = 0;
		for (int i=1;i<=n;i++) cin >> a[i];
		for (int i=1;i<=m;i++) cin >> b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+m+1);
		ll ans = 0;
		for (int i=1;i<=n;i++) sa[i] = sa[i-1] + a[i];
		for (int i=1;i<=m;i++) sb[i] = sb[i-1] + b[i];
		for (int i=0;i<=n;i++)
		{
			ll ret = abs(sa[i]-(sb[m]-sb[m-i]))+abs(sa[n]-sa[i]-sb[n-i]);
			ans = max(ans,ret);
		}
		cout << ans << endl;
	}
	return 0;
}
